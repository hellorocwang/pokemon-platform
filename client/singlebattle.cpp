#include "singlebattle.h"
#include "ui_singlebattle.h"
#include "userinform.h"
#include <QThread>
#include <QEventLoop>
#include <QMessageBox>
#include <QSound>
#include "qsequentialanimationgroup.h"
#include "qparallelanimationgroup.h"


singleBattle::singleBattle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::singleBattle)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()*10 + time.second()*1000);
    setFixedSize(1042,705);
    QString background = randomBack(1,3);
    background = "imagines/singlebattle" + background + ".png";
    QPixmap pixmap = QPixmap(background).scaled(this->size());
    QPalette palette (this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
    username = nameExchange;
    rerandomskill = -1;
    battleend = 0;
    movement = 0;
    ifClicked = 1;
  //connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

singleBattle::~singleBattle()
{
    delete ui;
}

void singleBattle::receiveData(QStringList data){
    pokename = data.at(0);
    pokelevel = data.at(1);
    pokeexp = data.at(2);
    pokeskill1 = data.at(3);
    pokeskill2 = data.at(4);
    pokeskill3 = data.at(5);
    pokechoose = data.at(6);
    QPixmap pixmap1,pixmap2;
    QString temp;
    if(pokename == "Bulbasaur"){
       pixmap1 = QPixmap("imagines/1.png");
       ownPoke = new Bulbasaur();
       ownPoke->levelUP(pokelevel.toInt());
       temp = randomCreate(1,3);
    }
    else if(pokename == "Lvysaur"){
        pixmap1 = QPixmap("imagines/2.png");
        ownPoke = new Lvysaur(pokelevel.toInt(),pokeskill1.toInt());
        ownPoke->levelUP(pokelevel.toInt());
        temp = randomCreate(11,13);
    }
    else if(pokename == "Venusaur"){
        pixmap1 = QPixmap("imagines/3.png");
        ownPoke = new Venusaur(pokelevel.toInt(),pokeskill1.toInt(),pokeskill2.toInt());
        ownPoke->levelUP(pokelevel.toInt());
        temp = randomCreate(21,23);
    }
    else if(pokename == "Charmander"){
        pixmap1 = QPixmap("imagines/4.png");
        ownPoke = new Charmander();
        ownPoke->levelUP(pokelevel.toInt());
        temp = randomCreate(1,3);
    }
    else if(pokename == "Charmeleon"){
        pixmap1 = QPixmap("imagines/5.png");
        ownPoke = new Charmeleon(pokelevel.toInt(),pokeskill1.toInt());
        ownPoke->levelUP(pokelevel.toInt());
        temp = randomCreate(11,13);
    }
    else if(pokename == "Charizard"){
        pixmap1 = QPixmap("imagines/6.png");
        ownPoke = new Charizard(pokelevel.toInt(),pokeskill1.toInt(),pokeskill2.toInt());
        ownPoke->levelUP(pokelevel.toInt());
        temp = randomCreate(21,23);
    }
    else if(pokename == "Squirtle"){
        pixmap1 = QPixmap("imagines/7.png");
        ownPoke = new Squirtle();
        ownPoke->levelUP(pokelevel.toInt());
        temp = randomCreate(1,3);
    }
    else if(pokename == "Wartortle"){
        pixmap1 = QPixmap("imagines/8.png");
        ownPoke = new Wartortle(pokelevel.toInt(),pokeskill1.toInt());
        ownPoke->levelUP(pokelevel.toInt());
        temp = randomCreate(11,13);
    }
    else if(pokename == "Blastoise"){
        pixmap1 = QPixmap("imagines/9.png");
        ownPoke = new Blastoise(pokelevel.toInt(),pokeskill1.toInt(),pokeskill2.toInt());
        ownPoke->levelUP(pokelevel.toInt());
        temp = randomCreate(21,23);
    }
    if(temp == "Bulbasaur"){
       pixmap2 = QPixmap("imagines/1.png");
       batPoke = new Bulbasaur();
       batPoke->levelUP(pokelevel.toInt());
    }
    else if(temp == "Lvysaur"){
        pixmap2 = QPixmap("imagines/2.png");
        batPoke = new Lvysaur();
        batPoke->levelUP(pokelevel.toInt());
    }
    else if(temp == "Venusaur"){
        pixmap2 = QPixmap("imagines/3.png");
        batPoke = new Venusaur();
        batPoke->levelUP(pokelevel.toInt());
    }
    else if(temp == "Charmander"){
        pixmap2 = QPixmap("imagines/4.png");
        batPoke = new Charmander();
        batPoke->levelUP(pokelevel.toInt());
    }
    else if(temp == "Charmeleon"){
        pixmap2 = QPixmap("imagines/5.png");
        batPoke = new Charmeleon();
        batPoke->levelUP(pokelevel.toInt());
    }
    else if(temp == "Charizard"){
        pixmap2 = QPixmap("imagines/6.png");
        batPoke = new Charizard();
        batPoke->levelUP(pokelevel.toInt());
    }
    else if(temp == "Squirtle"){
        pixmap2 = QPixmap("imagines/7.png");
        batPoke = new Squirtle();
        batPoke->levelUP(pokelevel.toInt());
    }
    else if(temp == "Wartortle"){
        pixmap2 = QPixmap("imagines/8.png");
        batPoke = new Wartortle();
        batPoke->levelUP(pokelevel.toInt());
    }
    else if(temp == "Blastoise"){
        pixmap2 = QPixmap("imagines/9.png");
        batPoke = new Blastoise();
        batPoke->levelUP(pokelevel.toInt());
    }
    QPixmap pix1=pixmap1.scaled(140, 130, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pix2=pixmap2.scaled(140, 130, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label ->setPixmap(pix1);
    ui->label ->resize(pix1.size());
    ui->label_2->setPixmap(pix2);
    ui->label_2->resize(pix2.size());
    ui->pushButton->setText(ownPoke->skillInitial()->returnSkillName(0));
    if(pokeskill1 != "-1"){
        ui->pushButton_2->setText(ownPoke->skillInitial()->returnSkillName(pokeskill1.toInt()));
    }
    else ui->pushButton_2->setText(" ");
    if(pokeskill2 != "-1"){
        ui->pushButton_3->setText(ownPoke->skillInitial()->returnSkillName(pokeskill2.toInt()));
    }
    else ui->pushButton_3->setText(" ");
    if(pokeskill3 != "-1"){
        ui->pushButton_4->setText(ownPoke->skillInitial()->returnSkillName(pokeskill3.toInt()));
    }
    else ui->pushButton_4->setText(" ");
}

void singleBattle::newConnect()
{
    stopConnect();
    tcpSocket->connectToHost(ip_address,6666);
    //sendMessage();
}

void singleBattle::stopConnect(){
    blockSize = 0;
    // 取消已有的连接
    tcpSocket->abort();
}

void singleBattle::sendMessage()
{
    // 用于暂存我们要发送的数据
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    // 设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    /****encode*****/
    out <<message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    // 获取已经建立的连接的套接字
    tcpSocket->write(block);
    // 发送数据成功后，显示提示
}

void singleBattle::readMessage()
{
    QDataStream in(tcpSocket);
    // 设置数据流版本，这里要和服务器端相同
    in.setVersion(QDataStream::Qt_4_0);
    // 如果是刚开始接收数据
    if (blockSize == 0) {
        //判断接收的数据是否大于两字节，也就是文件的大小信息所占的空间
        //如果是则保存到blockSize变量中，否则直接返回，继续接收数据
        if(tcpSocket->bytesAvailable() < (int)sizeof(quint16)) {
            return;
        }
        in >> blockSize;
    }
    // 如果没有得到全部的数据，则返回，继续接收数据
    if(tcpSocket->bytesAvailable() < blockSize) {
        return;
    }
    // 将接收到的数据存放到变量中
    in >> message;
    // 显示接收到的数据
    if(message.section('/',1,1) == "pokename"){
        message.remove(message.indexOf("pokename"),9);
        pokename = message.section('/',1,1);
        message.remove(message.indexOf("pokelevel"),10);
        pokelevel = message.section('/',1,1);
        message.remove(message.indexOf("pokeskill1"),11);
        pokeskill1 = message.section('/',1,1);
        message.remove(message.indexOf("pokeskill2"),11);
        pokeskill2 = message.section('/',1,1);
        message.remove(message.indexOf("pokeskill3"),11);
        pokeskill3 = message.section('/',1,1);
    }
}

void singleBattle::on_pushButton_clicked()
{
    if(ifClicked == 1){
        qDebug()<<pokename<<pokelevel<<pokeexp<<pokeskill1<<pokeskill2<<pokeskill3;
        caculateBuff(ownPoke);
        update();
        if(batPoke->getnowHP() <= 0){
            qDebug()<<"player win !";
            battleend = 1;
            update();
            battleEnd();
            return;
        }
        caculateBuff(batPoke);
        update();
        if(ownPoke->getnowHP() <= 0){
            qDebug()<<"computer win !";
            battleend = -1;
            update();
            battleEnd();
            return;
        }
        update();
        qDebug()<<"ownPoke---hp:"<<ownPoke->getnowHP();
        qDebug()<<"batPoke---hp:"<<batPoke->getnowHP();
        if(ownPoke->getSpeed() >= batPoke->getSpeed()){
            movement = 1;
            ownPoke->skillInitial()->skillEffect(ownPoke,batPoke,0);
            battleEffect1();
            qDebug()<<"batPoke,hp:"<<batPoke->getnowHP();
            if(batPoke->getnowHP() <= 0){
                qDebug()<<"ownPoke win !";
                battleend = 1;
                update();
                battleEnd();
                return;
            }
            movement = 0;
            ifClicked = 0;
            waitSkill(1000);
            rerandomskill = batPoke->skillInitial()->releaseSkill(rerandomskill,1);
            batPoke->skillInitial()->skillEffect(batPoke,ownPoke,rerandomskill);
            battleEffect2();
            qDebug()<<"ownPoke,hp:"<<ownPoke->getnowHP();
            if(ownPoke->getnowHP() <= 0){
                qDebug()<<"batPoke win !";
                battleend = -1;
                update();
                battleEnd();
                return;
            }
            update();
        }
        else if(batPoke->getSpeed() > ownPoke->getSpeed()){
            ifClicked = 0;
            movement = 0;
            waitSkill(1000);
            rerandomskill = batPoke->skillInitial()->releaseSkill(rerandomskill,1);
            batPoke->skillInitial()->skillEffect(batPoke,ownPoke,rerandomskill);
            battleEffect2();
            if(ownPoke->getnowHP() <= 0){
                qDebug()<<"batPoke win !";
                battleend = -1;
                update();
                battleEnd();
                return;
            }
            qDebug()<<"ownPoke,hp:"<<ownPoke->getnowHP();
            movement = 1;
            ownPoke->skillInitial()->skillEffect(ownPoke,batPoke,0);
            battleEffect1();
            if(batPoke->getnowHP() <= 0){
                qDebug()<<"ownPoke win !";
                battleend = 1;
                update();
                battleEnd();
                return;
            }
            qDebug()<<"batPoke,hp:"<<batPoke->getnowHP();
        }
    }
    update();
}

void singleBattle::on_pushButton_2_clicked()
{
    if(pokeskill1 != "-1"){
        if(ifClicked == 1){
            qDebug()<<pokename<<pokelevel<<pokeexp<<pokeskill1<<pokeskill2<<pokeskill3;
            caculateBuff(ownPoke);
            update();
            if(batPoke->getnowHP() <= 0){
                qDebug()<<"player win !";
                battleend = 1;
                update();
                battleEnd();
                return;
            }
            caculateBuff(batPoke);
            update();
            if(ownPoke->getnowHP() <= 0){
                qDebug()<<"computer win !";
                battleend = -1;
                update();
                battleEnd();
                return;
            }
            update();
            qDebug()<<"ownPoke---hp:"<<ownPoke->getnowHP();
            qDebug()<<"batPoke---hp:"<<batPoke->getnowHP();
            if(ownPoke->getSpeed() >= batPoke->getSpeed()){
                movement = 1;
                ownPoke->skillInitial()->skillEffect(ownPoke,batPoke,pokeskill1.toInt());
                battleEffect1();
                qDebug()<<"batPoke,hp:"<<batPoke->getnowHP();
                if(batPoke->getnowHP() <= 0){
                    qDebug()<<"ownPoke win !";
                    battleend = 1;
                    update();
                    battleEnd();
                    return;
                }
                movement = 0;
                ifClicked = 0;
                waitSkill(1000);
                rerandomskill = batPoke->skillInitial()->releaseSkill(rerandomskill,1);
                batPoke->skillInitial()->skillEffect(batPoke,ownPoke,rerandomskill);
                battleEffect2();
                qDebug()<<"ownPoke,hp:"<<ownPoke->getnowHP();
                if(ownPoke->getnowHP() <= 0){
                    qDebug()<<"batPoke win !";
                    battleend = -1;
                    update();
                    battleEnd();
                    return;
                }
                update();
            }
            else if(batPoke->getSpeed() > ownPoke->getSpeed()){
                ifClicked = 0;
                movement = 0;
                waitSkill(1000);
                rerandomskill = batPoke->skillInitial()->releaseSkill(rerandomskill,1);
                batPoke->skillInitial()->skillEffect(batPoke,ownPoke,rerandomskill);
                battleEffect2();
                if(ownPoke->getnowHP() <= 0){
                    qDebug()<<"batPoke win !";
                    battleend = -1;
                    update();
                    battleEnd();
                    return;
                }
                qDebug()<<"ownPoke,hp:"<<ownPoke->getnowHP();
                movement = 1;
                ownPoke->skillInitial()->skillEffect(ownPoke,batPoke,pokeskill1.toInt());
                battleEffect1();
                if(batPoke->getnowHP() <= 0){
                    qDebug()<<"ownPoke win !";
                    battleend = 1;
                    update();
                    battleEnd();
                    return;
                }
                qDebug()<<"batPoke,hp:"<<batPoke->getnowHP();
            }
        }
        update();
    }
}

void singleBattle::on_pushButton_3_clicked()
{
    if(pokeskill2 != "-1"){
        if(ifClicked == 1){
            qDebug()<<pokename<<pokelevel<<pokeexp<<pokeskill1<<pokeskill2<<pokeskill3;
            caculateBuff(ownPoke);
            update();
            if(batPoke->getnowHP() <= 0){
                qDebug()<<"player win !";
                battleend = 1;
                update();
                battleEnd();
                return;
            }
            caculateBuff(batPoke);
            update();
            if(ownPoke->getnowHP() <= 0){
                qDebug()<<"computer win !";
                battleend = -1;
                update();
                battleEnd();
                return;
            }
            update();
            qDebug()<<"ownPoke---hp:"<<ownPoke->getnowHP();
            qDebug()<<"batPoke---hp:"<<batPoke->getnowHP();
            if(ownPoke->getSpeed() >= batPoke->getSpeed()){
                movement = 1;
                ownPoke->skillInitial()->skillEffect(ownPoke,batPoke,pokeskill2.toInt());
                battleEffect1();
                qDebug()<<"batPoke,hp:"<<batPoke->getnowHP();
                if(batPoke->getnowHP() <= 0){
                    qDebug()<<"ownPoke win !";
                    battleend = 1;
                    update();
                    battleEnd();
                    return;
                }
                movement = 0;
                ifClicked = 0;
                waitSkill(1000);
                rerandomskill = batPoke->skillInitial()->releaseSkill(rerandomskill,1);
                batPoke->skillInitial()->skillEffect(batPoke,ownPoke,rerandomskill);
                battleEffect2();
                qDebug()<<"ownPoke,hp:"<<ownPoke->getnowHP();
                if(ownPoke->getnowHP() <= 0){
                    qDebug()<<"batPoke win !";
                    battleend = -1;
                    update();
                    battleEnd();
                    return;
                }
                update();
            }
            else if(batPoke->getSpeed() > ownPoke->getSpeed()){
                ifClicked = 0;
                movement = 0;
                waitSkill(1000);
                rerandomskill = batPoke->skillInitial()->releaseSkill(rerandomskill,1);
                batPoke->skillInitial()->skillEffect(batPoke,ownPoke,rerandomskill);
                battleEffect2();
                if(ownPoke->getnowHP() <= 0){
                    qDebug()<<"batPoke win !";
                    battleend = -1;
                    update();
                    battleEnd();
                    return;
                }
                qDebug()<<"ownPoke,hp:"<<ownPoke->getnowHP();
                movement = 1;
                ownPoke->skillInitial()->skillEffect(ownPoke,batPoke,pokeskill2.toInt());
                battleEffect1();
                if(batPoke->getnowHP() <= 0){
                    qDebug()<<"ownPoke win !";
                    battleend = 1;
                    update();
                    battleEnd();
                    return;
                }
                qDebug()<<"batPoke,hp:"<<batPoke->getnowHP();
            }
        }
        update();
    }
}

void singleBattle::on_pushButton_4_clicked()
{
    if(pokeskill3 != "-1"){
        if(ifClicked == 1){
            qDebug()<<pokename<<pokelevel<<pokeexp<<pokeskill1<<pokeskill2<<pokeskill3;
            caculateBuff(ownPoke);
            update();
            if(batPoke->getnowHP() <= 0){
                qDebug()<<"player win !";
                battleend = 1;
                update();
                battleEnd();
                return;
            }
            caculateBuff(batPoke);
            update();
            if(ownPoke->getnowHP() <= 0){
                qDebug()<<"computer win !";
                battleend = -1;
                update();
                battleEnd();
                return;
            }
            update();
            qDebug()<<"ownPoke---hp:"<<ownPoke->getnowHP();
            qDebug()<<"batPoke---hp:"<<batPoke->getnowHP();
            if(ownPoke->getSpeed() >= batPoke->getSpeed()){
                movement = 1;
                ownPoke->skillInitial()->skillEffect(ownPoke,batPoke,pokeskill3.toInt());
                battleEffect1();
                qDebug()<<"batPoke,hp:"<<batPoke->getnowHP();
                if(batPoke->getnowHP() <= 0){
                    qDebug()<<"ownPoke win !";
                    battleend = 1;
                    update();
                    battleEnd();
                    return;
                }
                movement = 0;
                ifClicked = 0;
                waitSkill(1000);
                rerandomskill = batPoke->skillInitial()->releaseSkill(rerandomskill,1);
                batPoke->skillInitial()->skillEffect(batPoke,ownPoke,rerandomskill);
                battleEffect2();
                qDebug()<<"ownPoke,hp:"<<ownPoke->getnowHP();
                if(ownPoke->getnowHP() <= 0){
                    qDebug()<<"batPoke win !";
                    battleend = -1;
                    update();
                    battleEnd();
                    return;
                }
                update();
            }
            else if(batPoke->getSpeed() > ownPoke->getSpeed()){
                ifClicked = 0;
                movement = 0;
                waitSkill(1000);
                rerandomskill = batPoke->skillInitial()->releaseSkill(rerandomskill,1);
                batPoke->skillInitial()->skillEffect(batPoke,ownPoke,rerandomskill);
                battleEffect2();
                if(ownPoke->getnowHP() <= 0){
                    qDebug()<<"batPoke win !";
                    battleend = -1;
                    update();
                    battleEnd();
                    return;
                }
                qDebug()<<"ownPoke,hp:"<<ownPoke->getnowHP();
                movement = 1;
                ownPoke->skillInitial()->skillEffect(ownPoke,batPoke,pokeskill3.toInt());
                battleEffect1();
                if(batPoke->getnowHP() <= 0){
                    qDebug()<<"ownPoke win !";
                    battleend = 1;
                    update();
                    battleEnd();
                    return;
                }
                qDebug()<<"batPoke,hp:"<<batPoke->getnowHP();
            }
        }
        update();
    }
}

QString singleBattle::randomCreate(int first,int end){
    int pokea = first + qrand()%(end - first + 1);
    switch(pokea){
        case 1:
            return "Bulbasaur";
        case 2:
            return "Charmander";
        case 3:
            return "Squirtle";
        case 11:
            return "Lvysaur";
        case 12:
            return "Charmeleon";
        case 13:
            return "Wartortle";
        case 21:
            return "Venusaur";
        case 22:
            return "Charizard";
        case 23:
            return "Blastoise";
        default:
            return "0";
    }
}

QString singleBattle::randomBack(int first,int end){
    int pokea = first + qrand()%(end - first + 1);
    switch(pokea){
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "3";
        default:
            return "0";
    }
}

void singleBattle::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    // 设置画笔颜色
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 设置画笔颜色、宽度
    painter.setPen(QPen(QColor(255, 15, 15), 10));
    // 设置画刷颜色
    painter.setBrush(QColor(198, 10, 0));
    int length1,length2;
    length1 = 160*((float)ownPoke->getnowHP()/(float)ownPoke->getHP());
    length2 = 160*((float)batPoke->getnowHP()/(float)batPoke->getHP());
    painter.drawLine(QPointF(180,270),QPointF(180 + length1,270));
    painter.drawLine(QPointF(760,270),QPointF(760 + length2,270));
    if(battleend == 1){
        QPainter painter(this);
        // 设置画笔颜色
        painter.setPen(QColor(255, 244, 38));
        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(70);
        font.setItalic(true);
        painter.setFont(font);
        // 绘制文本
        painter.drawText(rect(), Qt::AlignCenter, "You Win");
    }
    else if(battleend == -1){
        QPainter painter(this);
        // 设置画笔颜色
        painter.setPen(QColor(133, 133, 133));
        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(70);
        font.setItalic(true);
        painter.setFont(font);
        // 绘制文本
        painter.drawText(rect(), Qt::AlignCenter, "You Failed");
    }
    if(ifClicked == 1){
        QPainter painter(this);
        // 设置画笔颜色
        painter.setPen(QColor(255, 244, 38));

        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(50);
        //font.setItalic(true);
        painter.setFont(font);
        // 绘制文本
        painter.drawText(430,90, "请操作！");
    }
    else if(ifClicked == 0){
        QPainter painter(this);
        // 设置画笔颜色
        painter.setPen(QColor(206, 0, 5));

        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(50);
        //font.setItalic(true);
        painter.setFont(font);
        // 绘制文本
        painter.drawText(430,90, "战斗中...");
    }
}

void singleBattle::battleEnd(){
    if(battleend == 1)          QSound::play("imagines/winsound.wav");
    else            QSound::play("imagines/losesou.wav");
    message = "/" + battleType + "/" + username + "/" + pokechoose;
    if(battleType == "battleUP"){
        if(battleend == 1)  message += "/win";
        else message += "/fail";
        ifClicked = 0;
        newConnect();
        sendMessage();
    }
    else if(battleType == "battleVS"){
        if(battleend == 1)  message += "/win";
        else message += "/fail";
        ifClicked = 0;
        message += "/" + batPoke->returnPokename();
        newConnect();
        sendMessage();
    }
}

void singleBattle::battleEffect1(){
    ifClicked = 0;
    this->myWidget = new QLabel(this);
    this->myWidget->setPixmap(QPixmap("imagines/skill"+ownPoke->returnPokename()+".png"));
    myWidget->show();
    this->animation = new QPropertyAnimation(myWidget,"geometry");
    this->animation->setDuration(300);//速度,越小越快
    this->animation->setStartValue(QRect(125,200,300,300));
    this->animation->setEndValue(QRect(720,200,300,300));
    this->animation->start();
    waitSkill(400);
    delete myWidget;
    QSound::play("imagines/sound"+ownPoke->returnInitialname()+".wav");
    QMovie *movie = new QMovie("imagines/skill"+ownPoke->returnInitialname()+".gif");
    this->skillEffect = new QLabel(this);
    skillEffect->show();
    skillEffect->setGeometry(QRect(760, 300, 150, 150));
    skillEffect->setMovie(movie);
    movie->start();
    waitSkill(1000);
    delete skillEffect;
    update();
    ifClicked = 1;
}

void singleBattle::battleEffect2(){
    ifClicked = 0;
    this->myWidget = new QLabel(this);
    this->myWidget->setPixmap(QPixmap("imagines/skill"+batPoke->returnPokename()+".png"));
    myWidget->show();
    this->animation = new QPropertyAnimation(myWidget,"geometry");
    this->animation->setDuration(300);//速度,越小越快
    this->animation->setStartValue(QRect(720,200,300,300));
    this->animation->setEndValue(QRect(125,200,300,300));
    this->animation->start();
    waitSkill(400);
    delete myWidget;
    QSound::play("imagines/sound"+batPoke->returnInitialname()+".wav");
    QMovie *movie = new QMovie("imagines/skill"+batPoke->returnInitialname()+".gif");
    this->skillEffect = new QLabel(this);
    skillEffect->show();
    skillEffect->setGeometry(QRect(180, 300, 150, 150));
    skillEffect->setMovie(movie);
    movie->start();
    waitSkill(1000);
    delete skillEffect;
    update();
    ifClicked = 1;
}

void singleBattle::waitSkill(int time){
    QEventLoop eventloop;
    QTimer::singleShot(time, &eventloop, SLOT(quit()));
    eventloop.exec();
}

void singleBattle::receiveType(QString type){
    battleType = type;
}

void singleBattle::on_pushButton_5_clicked()
{
    userinform *widget = new userinform(this);
    widget->show();
}
