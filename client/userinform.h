#ifndef USERINFORM_H
#define USERINFORM_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTableWidget>
#include "ipaddress.h"

namespace Ui {
class userinform;
}

class userinform : public QMainWindow
{
    Q_OBJECT

public:
    explicit userinform(QWidget *parent = 0);
    ~userinform();

private:
    Ui::userinform *ui;
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
    QString pokechoose;
    int choose;
    int pokeTotal;

signals:
    void sendData(QStringList);

private slots:
    void newConnect();
    void sendMessage();
    void readMessage();

    void on_tableWidget_cellClicked(int row, int column);
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
};

#endif // USERINFORM_H
