#include "othersinform.h"
#include "ui_othersinform.h"
#include <QSound>

othersinform::othersinform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::othersinform)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    message = "";
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    QPixmap pixmap = QPixmap("imagines/otheruser.png").scaled(this->size());
    QPalette palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
}

othersinform::~othersinform()
{
    delete ui;
}

void othersinform::newConnect()
{
    blockSize = 0;
    // 取消已有的连接
    tcpSocket->abort();
    tcpSocket->connectToHost(ip_address,6666);
    sendMessage();
}

void othersinform::sendMessage()
{
    // 用于暂存我们要发送的数据
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    // 设置数据流的版本，客户端和服务器端使用的版本要相同
    message = "/userinform/" + username;
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

void othersinform::readMessage()
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
    if(message == "none"){
        ui->textBrowser->setText("该用户不存在");
        return;
    }
    else if(message.section('/',1,1) == username){
        QString temp;
        message.remove(0,username.length()+1);
        temp = message.section('/',1,1);
        rate = temp;
        message.remove(0,temp.length()+1);
        temp = message.section('/',1,1);
        primarypoke = temp;
        message.remove(0,temp.length()+1);
        temp = message.section('/',1,1);
        seniorpoke = temp;
        message.remove(0,temp.length()+1);
        temp = message.section('/',1,1);
        win = temp;
        message.remove(0,temp.length()+1);
        temp = message.section('/',1,1);
        fail = temp;
        message.remove(0,temp.length()+1);
    }
    qDebug()<<"message"<<message;
    pokeTotal = primarypoke.toInt() + seniorpoke.toInt();
    pokename = new QString [pokeTotal];
    pokelevel = new QString [pokeTotal];
    pokeexp = new QString [pokeTotal];
    pokeskill1 = new QString [pokeTotal];
    pokeskill2 = new QString [pokeTotal];
    pokeskill3 = new QString [pokeTotal];
    pokeid = new QString [pokeTotal];
    int num = 0;
    ui->tableWidget->setRowCount(pokeTotal);
    ui->tableWidget->setColumnCount(6);
    QStringList rowLabels;
    rowLabels << "pokename" << "pokelevel" << "pokeexp" << "pokeskill1"<< "pokeskill2"<< "pokeskill3";
    ui->tableWidget->setHorizontalHeaderLabels(rowLabels);
    while(message.section('/',1,1) == "pokename"){
        qDebug()<<"message"<<message;
        QTableWidgetItem *tableWidgetItem1 = new QTableWidgetItem;
        QTableWidgetItem *tableWidgetItem2 = new QTableWidgetItem;
        QTableWidgetItem *tableWidgetItem3 = new QTableWidgetItem;
        QTableWidgetItem *tableWidgetItem4 = new QTableWidgetItem;
        QTableWidgetItem *tableWidgetItem5 = new QTableWidgetItem;
        QTableWidgetItem *tableWidgetItem6 = new QTableWidgetItem;
        message.remove(message.indexOf("pokename"),9);
        pokename[num] = message.section('/',1,1);
        *tableWidgetItem1 = QTableWidgetItem(pokename[num]);
        ui->tableWidget->setItem(num,0,tableWidgetItem1);
        message.remove(0,pokename[num].length()+1);
        pokelevel[num] = message.section('/',1,1);
        *tableWidgetItem2 = QTableWidgetItem(pokelevel[num]);
        ui->tableWidget->setItem(num,1,tableWidgetItem2);
        message.remove(0,pokelevel[num].length()+1);
        pokeexp[num] = message.section('/',1,1);
        *tableWidgetItem3 = QTableWidgetItem(pokeexp[num]);
        ui->tableWidget->setItem(num,2,tableWidgetItem3);
        message.remove(0,pokeexp[num].length()+1);
        pokeskill1[num] = message.section('/',1,1);
        *tableWidgetItem4 = QTableWidgetItem(pokeskill1[num]);
        ui->tableWidget->setItem(num,3,tableWidgetItem4);
        message.remove(0,pokeskill1[num].length()+1);
        pokeskill2[num] = message.section('/',1,1);
        *tableWidgetItem5 = QTableWidgetItem(pokeskill2[num]);
        ui->tableWidget->setItem(num,4,tableWidgetItem5);
        message.remove(0,pokeskill2[num].length()+1);
        pokeskill3[num] = message.section('/',1,1);
        *tableWidgetItem6 = QTableWidgetItem(pokeskill3[num]);
        ui->tableWidget->setItem(num,5,tableWidgetItem6);
        message.remove(0,pokeskill3[num].length()+1);
        pokeid[num] = message.section('/',1,1);
        message.remove(0,pokeid[num].length()+1);
        num++;
    }
    ui->tableWidget->show();
    ui->textBrowser->setText("用户名："+username+"      胜率："+rate+"     低级精灵数："+primarypoke+"       高级精灵数："+seniorpoke);
}

void othersinform::on_lineEdit1_textEdited(const QString &arg1)
{
    username = arg1;
}

void othersinform::on_pushButton1_clicked()
{
    QSound::play("imagines/pushbutton.wav");
    newConnect();
}

void othersinform::on_pushButton1_2_clicked()
{
    QSound::play("imagines/pushbutton.wav");
}
