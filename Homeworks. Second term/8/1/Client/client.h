#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>

class QComboBox;
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;
class QTextEdit;

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);

private slots:
    ///Show error message
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();
    ///Send message
    void send();
    ///Read message from Server
    void startRead();
    void connectServer();
    void disconnect();


private:
    QLabel *hostLabel;
    QLabel *portLabel;
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;
    QPushButton *sendButton;
    QPushButton *quitButton;
    QPushButton *connectButton;
    ///Chat
    QTextEdit *conversatoin;
    ///Line for texting message
    QLineEdit *message;

    QTcpSocket *tcpSocket;
    quint16 blockSize;

    QNetworkSession *networkSession;
};

#endif
