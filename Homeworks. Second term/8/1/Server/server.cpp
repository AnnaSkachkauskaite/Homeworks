#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

#include "server.h"

Server::Server(QWidget *parent):
    QDialog(parent),
    tcpServer(0),
    clientSocket(0),
    networkSession(0),
    messageSize(0)
{
    statusLabel = new QLabel;

    conversation = new QTextEdit;
    conversation->setReadOnly(true);

    messageText = new QLineEdit;

    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    sendButton = new QPushButton(tr("Send"));
    sendButton->setEnabled(false);

    QHBoxLayout *messageLayout = new QHBoxLayout;
    messageLayout->addWidget(messageText);
    messageLayout->addWidget(sendButton);
    QHBoxLayout *quitButtonLayout = new QHBoxLayout;
    quitButtonLayout->addStretch(1);
    quitButtonLayout->addWidget(quitButton);
    quitButtonLayout->addStretch(1);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(conversation);
    mainLayout->addLayout(messageLayout);
    mainLayout->addLayout(quitButtonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Chat"));




    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    } else {
        sessionOpened();
    }


        connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
        connect(sendButton, SIGNAL(clicked()), this, SLOT(send()));
        connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptClientConnection()));


}

void Server::sessionOpened()
{
    if (networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen()) {
        QMessageBox::critical(this, tr("Chat"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Client example now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));
}

void Server::disconnect()
{
    sendButton->setEnabled(false);
    QMessageBox::information(this, tr("Chat"),
                             tr("Client disconnected!"));
}

void Server::acceptClientConnection()
{
    clientSocket = tcpServer->nextPendingConnection();

    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(disconnect()));

    conversation->clear();
    conversation->textCursor().insertText("Client connected!\n");

    sendButton->setEnabled(true);
}

void Server::send()
{
    if(clientSocket)
    {
        sendButton->setEnabled(false);
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out << (quint16)messageText->text().length();
        out << messageText->text();
        clientSocket->write(block);
        conversation->textCursor().insertText("You: " + messageText->text() + '\n');
        messageText->clear();
        sendButton->setEnabled(true);
    }
}

void Server::startRead()
{
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_2);
    if (messageSize == 0)
    {
        if (clientSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> messageSize;
    }

    if (clientSocket->bytesAvailable() < messageSize)
             return;

    messageSize = 0;
    QString newMessage;
    in >> newMessage;
    conversation->textCursor().insertText("Client: " + newMessage + '\n');
}



