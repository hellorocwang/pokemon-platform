#ifndef NEWUSER_H
#define NEWUSER_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include "ipaddress.h"

namespace Ui {
class newuser;
}

class newuser : public QMainWindow
{
    Q_OBJECT

public:
    explicit newuser(QWidget *parent = 0);
    ~newuser();

private slots:
    void on_lineEdit1_textEdited(const QString &arg1);

    void on_lineEdit2_textChanged(const QString &arg1);

    void on_lineEdit3_textChanged(const QString &arg1);

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void sendMessage();

    void readMessage();

    void newConnect();

    void displayError(QAbstractSocket::SocketError);

private:
    QTcpSocket *tcpSocket;
    QString message;
    quint16 blockSize;
    QString password;
    QString passwordW;
    QString username;
    Ui::newuser *ui;
};

#endif // NEWUSER_H
