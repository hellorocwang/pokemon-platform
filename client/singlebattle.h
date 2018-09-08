#ifndef SINGLEBATTLE_H
#define SINGLEBATTLE_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include <QPainter>
#include <QPropertyAnimation>
#include <QLabel>
#include <QMovie>
#include "ipaddress.h"
#include "register.h"
#include "pokemon.h"

namespace Ui {
class singleBattle;
}

class singleBattle : public QMainWindow
{
    Q_OBJECT

public:
    explicit singleBattle(QWidget *parent = 0);
    ~singleBattle();
    void receiveData(QStringList data);
    void receiveType(QString type);

private slots:
    void newConnect();
    void sendMessage();
    void readMessage();
    void stopConnect();
    void battleEnd();
    QString randomCreate(int first, int end);
    QString randomBack(int first,int end);
    void waitSkill(int time);
    void battleEffect1();
    void battleEffect2();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

protected:

    void paintEvent(QPaintEvent * event);

private:
    Ui::singleBattle *ui;
    QString username;
    QString pokename;
    QString pokelevel;
    QString pokeexp;
    QString pokeskill1;
    QString pokeskill2;
    QString pokeskill3;
    QString pokechoose;
    pokemon *ownPoke;
    pokemon *batPoke;
    QTcpSocket *tcpSocket;
    QString message;
    quint16 blockSize;
    int rerandomskill;
    QLabel *myWidget;
    QLabel *skillEffect;
    QLabel *round;
    QPropertyAnimation *animation;
    int battleend;
    QWaitCondition wait;
    int movement;
    int ifClicked;
    QString battleType;
};

#endif // SINGLEBATTLE_H
