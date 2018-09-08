#include "newuser.h"
#include <QMessageBox>
#include <QSound>
#include "ui_newuser.h"
#include "singlebattle.h"

newuser::newuser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newuser)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    message = "";
    QRegExp regExp("[a-zA-Z0-9]+$");
    ui->lineEdit1->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit2->setValidator(new QRegExpValidator(regExp, this));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    QPixmap pixmap = QPixmap("imagines/newuser.png").scaled(this->size());
    QPalette palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
}

newuser::~newuser()
{
    delete ui;
}

void newuser::on_lineEdit1_textEdited(const QString &arg1)
{
    username = arg1;
}

void newuser::on_lineEdit2_textChanged(const QString &arg1)
{
    password = arg1;
}

void newuser::on_lineEdit3_textChanged(const QString &arg1)
{
    passwordW = arg1;
}

void newuser::on_pushButton1_clicked()
{
    QSound::play("imagines/pushbutton.wav");
    if(password == ""){
        QMessageBox::about(NULL, "About", "密码不能为空，请重新输入");
    }
    else if(password == passwordW){
        newConnect();
        //close();
    }
    else
        QMessageBox::about(NULL, "About", "两次密码输入不一致，请重新输入");
}

void newuser::on_pushButton2_clicked()
{
    QSound::play("imagines/pushbutton.wav");
}

void newuser::newConnect()
{
    blockSize = 0;
    // 取消已有的连接
    tcpSocket->abort();
    tcpSocket->connectToHost(ip_address,6666);
    sendMessage();
}

void newuser::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
}

void newuser::sendMessage()
{
    // 用于暂存我们要发送的数据
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    // 设置数据流的版本，客户端和服务器端使用的版本要相同
    message = "/Newuser/username/" + username + "/password/"+password;
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    /****encode*****/
    out <<message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    // 获取已经建立的连接的套接字
    tcpSocket->write(block);
    // 发送数据成功后，显示提示
    qDebug()<<"send message successful!!!";
}

void newuser::readMessage()
{
    QDataStream in(tcpSocket);
    // 设置数据流版本，这里要和服务器端相同
    in.setVersion(QDataStream::Qt_4_0);
    // 如果是刚开始接收数据
    if (blockSize == 0) {
        //判断接收的数据是否大于两字节，也就是文件的大小信息所占的空间
        //如果是则保存到blockSize变量中，否则直接返回，继续接收数据
        if(tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> blockSize;
    }
    // 如果没有得到全部的数据，则返回，继续接收数据
    if(tcpSocket->bytesAvailable() < blockSize) return;
    // 将接收到的数据存放到变量中
    in >> message;
    // 显示接收到的数据
    //Buffer = Buffer+message;
    qDebug() << message;
    if(message == "OK"){
        close();
        QMessageBox::about(NULL, "About", "注册成功");
    }
    else if(message == "USER"){
        QMessageBox::about(NULL, "About", "用户名已存在，请重新输入");
    }
    else{
        QMessageBox::about(NULL, "About", "请检查网络");
    }
}
