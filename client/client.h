#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QDialog>

#include <QAbstractSocket>
#include <QTcpSocket>
namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private:
    Ui::Client *ui;
    QTcpSocket *tcpSocket;
    QString message;
    quint16 blockSize;
    QString ipaddress;
private slots:
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);

    void on_connectButton_clicked();
    void on_hostLineEdit_textEdited(const QString &arg1);
};

#endif // CLIENT_H
