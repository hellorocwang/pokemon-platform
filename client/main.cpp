#include "mainwindow.h"
#include "pokemon.h"
#include "ipaddress.h"
#include <QApplication>
#include <QDebug>

QString ip_address = " ";

int main(int argc, char *argv[])
{
    QFile f("ipaddress.txt");
    if(f.open(QIODevice::ReadOnly))
    {
        QTextStream txtInput(&f);
        QString lineStr[10];
        int num = 0;
        while(!txtInput.atEnd())
        {
            lineStr[num] = txtInput.readLine();
            num ++;
        }
        f.close();
        ip_address =  lineStr[0];
    }
    qDebug()<<ip_address;
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
    /*MegaCharizardX user1;
    MegaVenusaur user2;
    int skill1 = -1,skill2 = -1;
    while(true){
        caculateBuff(user1);
        if(user1.getnowHP() <= 0){
            qDebug()<<"user2 win !";
            break;
        }
        caculateBuff(user2);
        if(user1.getnowHP() <= 0){
            qDebug()<<"user2 win !";
            break;
        }
        qDebug()<<"user1---hp:"<<user1.getnowHP();
        qDebug()<<"user2---hp:"<<user2.getnowHP();
        if(user1.getSpeed() >= user2.getSpeed()){
            skill1 = user1.skill.releaseSkill(skill1,1);
            user1.skill.skillEffect(user1,user2,skill1);
            qDebug()<<"user2,hp:"<<user2.getnowHP();
            if(user2.getnowHP() <= 0){
                qDebug()<<"user1 win !";
                break;
            }
            skill2 = user2.skill.releaseSkill(skill2,1);
            user2.skill.skillEffect(user2,user1,skill2);
            qDebug()<<"user1,hp:"<<user1.getnowHP();
            if(user1.getnowHP() <= 0){
                qDebug()<<"user2 win !";
                break;
            }
        }
        else if(user2.getSpeed() > user1.getSpeed()){
            skill2 = user2.skill.releaseSkill(skill2,1);
            user2.skill.skillEffect(user2,user1,skill2);
            if(user1.getnowHP() <= 0){
                qDebug()<<"user2 win !";
                break;
            }
            qDebug()<<"user1,hp:"<<user1.getnowHP();
            skill1 = user1.skill.releaseSkill(skill1,1);
            user1.skill.skillEffect(user1,user2,skill1);
            if(user2.getnowHP() <= 0){
                qDebug()<<"user1 win !";
                break;
            }
            qDebug()<<"user2,hp:"<<user2.getnowHP();
        }
    }*/
}
