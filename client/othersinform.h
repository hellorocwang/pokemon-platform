#ifndef OTHERSINFORM_H
#define OTHERSINFORM_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTableWidget>
#include "ipaddress.h"

namespace Ui {
class othersinform;
}

class othersinform : public QMainWindow
{
    Q_OBJECT

public:
    explicit othersinform(QWidget *parent = 0);
    ~othersinform();

private slots:
    void on_lineEdit1_textEdited(const QString &arg1);

    void newConnect();
    void sendMessage();
    void readMessage();

    void on_pushButton1_clicked();

    void on_pushButton1_2_clicked();

private:
    Ui::othersinform *ui;
    QString username;
    QTcpSocket *tcpSocket;
    QString message;
    quint16 blockSize;
    QString ipaddress;
    QString password;
    QString Buffer;
    QString rate;
    QString primarypoke;
    QString seniorpoke;
    QString win;
    QString fail;
    QString *pokename;
    QString *pokelevel;
    QString *pokeexp;
    QString *pokeskill1;
    QString *pokeskill2;
    QString *pokeskill3;
    QString *pokeid;
    QString pokenameTran;
    QString pokelevelTran;
    QString pokeexpTran;
    QString pokeskill1Tran;
    QString pokeskill2Tran;
    QString pokeskill3Tran;
    int pokeTotal;
};

#endif // OTHERSINFORM_H
