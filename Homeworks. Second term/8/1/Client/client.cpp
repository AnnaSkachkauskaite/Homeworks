#include <QtWidgets>
#include <QtNetwork>
#include <QObject>

#include "client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    networkSession(0),
    blockSize(0)
{

    setWindowTitle(tr("Chat"));

    hostLabel = new QLabel(tr("Server IP-adress:"));
    hostCombo = new QComboBox;

    portLabel = new QLabel(tr("Server port:"));
    portLineEdit = new QLineEdit;
    portLineEdit->setValidator(new QIntValidator(1, 65535));

    statusLabel = new QLabel;
    statusLabel = new QLabel(tr("This app requires that you run the Chat server as well."));

    message = new QLineEdit;

    sendButton = new QPushButton(tr("Send"));
    sendButton->setEnabled(false);

    connectButton = new QPushButton(tr("Connect"));

    quitButton = new QPushButton(tr("Quit"));

    quitButton->setAutoDefault(false);

    conversatoin = new QTextEdit;
    conversatoin->setReadOnly(true);

    QList<QHostAddress> adressList = QNetworkInterface::allAddresses();

    for (int i = 0; i < adressList.size(); ++i)
    {
        hostCombo->addItem(adressList.at(i).toString());
    }

    tcpSocket = new QTcpSocket;

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(send()));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(connectServer()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnect()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(connectButton);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);
    QHBoxLayout *messageLayout = new QHBoxLayout;
    messageLayout->addWidget(message);
    messageLayout->addWidget(sendButton);


    QGridLayout *connectionLayout = new QGridLayout;
    connectionLayout->addWidget(hostLabel, 0, 0);
    connectionLayout->addWidget(hostCombo, 0, 1);
    connectionLayout->addWidget(portLabel, 1, 0);
    connectionLayout->addWidget(portLineEdit, 1, 1);
    connectionLayout->addWidget(statusLabel, 2, 0, 1, 2);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(connectionLayout);
    mainLayout->addWidget(conversatoin);
    mainLayout->addLayout(messageLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    portLineEdit->setFocus();

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
                QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    tcpSocket->close();
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Chat client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Chat client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Chat client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }
    hostCombo->setEnabled(true);
    portLineEdit->setEnabled(true);
}

void Client::disconnect()
{
    hostCombo->setDisabled(true);
    portLineEdit->setDisabled(true);
    connectButton->setEnabled(true);
    sendButton->setDisabled(true);

    QMessageBox::information(this, tr("Chat"), tr("Server disconnected!"));
}

void Client::sessionOpened()
{
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

    statusLabel = new QLabel(tr("This app requires that you run the Chat server as well."));

    sendButton->setEnabled(true);
}

void Client::connectServer()
{
    tcpSocket->connectToHost(hostCombo->currentText(), portLineEdit->text().toInt());

    if (tcpSocket->waitForConnected(5000))
    {
        conversatoin->clear();
        conversatoin->textCursor().insertText("Server connected!\n");
        sendButton->setEnabled(true);
        hostCombo->setDisabled(true);
        connectButton->setDisabled(true);
        portLineEdit->setDisabled(true);
    }
    else
    {
        hostCombo->setEnabled(true);
        portLineEdit->setEnabled(true);
    }
}



void Client::startRead()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_2);

    if (blockSize == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
             return;

    blockSize = 0;
    QString newMessage;
    in >> newMessage;
    conversatoin->textCursor().insertText("Server: " + newMessage + '\n');
}

void Client::send()
{
    sendButton->setEnabled(false);

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)message->text().length();
    out << message->text();
    tcpSocket->write(block);

    conversatoin->textCursor().insertText("You: " + message->text() + '\n');

    message->clear();

    sendButton->setEnabled(true);
}



