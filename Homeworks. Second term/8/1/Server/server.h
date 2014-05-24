#ifndef SERVER_H
#define SERVER_H

#include <QDialog>

class QLabel;
class QPushButton;
class QTcpServer;
class QNetworkSession;
class QLineEdit;
class QTextEdit;
class QTcpSocket;

///Class for privat chat Server
class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);

private slots:
    void sessionOpened();
    void acceptClientConnection();
    ///Send message to Client
    void send();
    ///Start read message
    void startRead();
    ///Disconnect Client
    void disconnect();

private:
    QLabel *statusLabel;
    ///Line for texting message
    QLineEdit *messageText;
    ///Chat
    QTextEdit *conversation;
    QPushButton *sendButton;
    QPushButton *quitButton;
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
    QNetworkSession *networkSession;
    quint16 messageSize;
};

#endif  // SERVER_H
