#include "userinform.h"
#include "ui_userinform.h"
#include "register.h"
#include "singlebattle.h"
#include <QSound>


userinform::userinform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userinform)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap("imagines/userinform.png").scaled(this->size());
    QPalette palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
    tcpSocket = new QTcpSocket(this);
    message = "";
    choose = 0;
    username = nameExchange;
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    newConnect();
    ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(testSlot(int,int)));

}

userinform::~userinform()
{
    delete ui;
}

void userinform::newConnect()
{
    blockSize = 0;
    // 取消已有的连接
    tcpSocket->abort();
    tcpSocket->connectToHost(ip_address,6666);
    sendMessage();
}

void userinform::sendMessage()
{
    // 用于暂存我们要发送的数据
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    // 设置数据流的版本，客户端和服务器端使用的版本要相同
    message = "/othersinform/" + username;
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

void userinform::readMessage()
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
    qDebug()<<"message----"<<message;
    if(message.section('/',1,1) == username){
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
    ui->textBrowser->setText("用户名："+username+" 胜率："+rate+" 低级精灵数："+primarypoke+" 高级精灵数："+seniorpoke+" 胜利："+win+" 失败："+fail);
}

void userinform::on_tableWidget_cellClicked(int row, int column)
{
    pokenameTran = pokename[row];
    pokelevelTran = pokelevel[row];
    pokeexpTran = pokeexp[row];
    pokeskill1Tran = pokeskill1[row];
    pokeskill2Tran = pokeskill2[row];
    pokeskill3Tran = pokeskill3[row];
    pokechoose = pokeid[row];
    choose = 1;
    qDebug()<<pokenameTran<<pokelevelTran<<pokeexpTran<<pokeskill1Tran<<pokeskill2Tran<<pokeskill3Tran<<pokechoose;
}

void userinform::on_pushButton1_clicked()
{
    QSound::play("imagines/pushbutton.wav");
    if(choose == 1){
        QStringList tempTram;
        tempTram<<pokenameTran<<pokelevelTran<<pokeexpTran<<pokeskill1Tran<<pokeskill2Tran<<pokeskill3Tran<<pokechoose;
        emit sendData(tempTram);
        singleBattle * s = new singleBattle(this);
        s->receiveData(tempTram);
        s->receiveType("battleUP");
        s->show();
        close();
     }
}

void userinform::on_pushButton2_clicked()
{
    QSound::play("imagines/pushbutton.wav");
    if(choose == 1){
        QStringList tempTram;
        tempTram<<pokenameTran<<pokelevelTran<<pokeexpTran<<pokeskill1Tran<<pokeskill2Tran<<pokeskill3Tran<<pokechoose;
        emit sendData(tempTram);
        singleBattle * s = new singleBattle(this);
        s->receiveData(tempTram);
        s->receiveType("battleVS");
        s->show();
        close();
     }
}
