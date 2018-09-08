#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include "ipaddress.h"

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);
    void sendMessage();
    void acceptConnection();

    void on_lineEdit1_textEdited(const QString &arg1);

    void on_lineEdit2_textEdited(const QString &arg1);

    void on_pushButton2_clicked();

    void on_pushButton1_clicked();

private:
    QTcpSocket *tcpSocket;
    QString message;
    quint16 blockSize;
    QString ipaddress;
    QString username;
    QString password;
    QString Buffer;
    Ui::Register *ui;
    bool receIf;
};

extern QString nameExchange;

#endif // REGISTER_H
