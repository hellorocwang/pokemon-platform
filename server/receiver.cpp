#include "receiver.h"
#include "connection.h"
#include "ui_receiver.h"
#include "alluser.h"
#include "pokemon.h"


receiver::receiver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::receiver)
{
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug() << "localHostName: " << localHostName << endl
             << "IP Address: " << info.addresses();

    foreach (QHostAddress address, info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            qDebug() << address.toString();
    }
    Buffer = "";
    message = "";
    createConnection();
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()*10 + time.second()*1000);
    ui->setupUi(this);
    socket=0;
    tcpServer = new QTcpServer(this);
    // 使用了IPv4的本地主机地址，等价于QHostAddress("127.0.0.1")
    if (!tcpServer->listen(QHostAddress::Any, 6666)) {
        qDebug() << tcpServer->errorString();
        close();
    }
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
  //  connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
  //              this, SLOT(displayError(QAbstractSocket::SocketError)));
}

receiver::~receiver()
{
    delete ui;
}

void receiver::readMessage(){
    QString str;
    blockSize=0;
    QDataStream in(socket);
    // 设置数据流版本，这里要和服务器端相同
    in.setVersion(QDataStream::Qt_4_0);
    // 如果是刚开始接收数据
    if (blockSize == 0) {
        //判断接收的数据是否大于两字节，也就是文件的大小信息所占的空间
        //如果是则保存到blockSize变量中，否则直接返回，继续接收数据
        if(socket->bytesAvailable() < (int)sizeof(quint16)) return;  //bytesAvailable()返回字节数
        in >> blockSize;
    }
    // 如果没有得到全部的数据，则返回，继续接收数据
    if(socket->bytesAvailable() < blockSize) return;
    // 将接收到的数据存放到变量中
    in >> str;
    // 显示接收到的数据
    Buffer = Buffer + str;
    qDebug()<<Buffer;
    QString str1,str2,str3,str4;
    if(Buffer.section('/',1,1) == "Register"){
        Buffer.remove(Buffer.indexOf("Register"),9);
        Buffer.remove(Buffer.indexOf("username"),9);
        qDebug()<<Buffer;
        str1 = Buffer.section('/',1,1);
        Buffer.remove(0,str1.length()+1);
        qDebug()<<Buffer;
        Buffer.remove(Buffer.indexOf("password"),9);
        qDebug()<<Buffer;
        str2 = Buffer.section('/',1,1);
        Buffer.remove(0,str2.length()+1);
        qDebug()<<Buffer;
        qDebug()<<str1<<str2;
        //在数据库中进行查询操作
        registerSent(str1,str2);
    }
    else if(Buffer.section('/',1,1) == "Newuser"){
        Buffer.remove(Buffer.indexOf("Newuser"),8);
        Buffer.remove(Buffer.indexOf("username"),9);
        qDebug()<<Buffer;
        str1 = Buffer.section('/',1,1);
        Buffer.remove(0,str1.length()+1);
        qDebug()<<Buffer;
        Buffer.remove(Buffer.indexOf("password"),9);
        qDebug()<<Buffer;
        str2 = Buffer.section('/',1,1);
        Buffer.remove(0,str2.length()+1);
        qDebug()<<Buffer;
        qDebug()<<str1<<str2;
        //在数据库中进行查询操作
        newuserSent(str1,str2);
    }
    else if(Buffer.section('/',1,1) == "userinform"){
        Buffer.remove(Buffer.indexOf("userinform"),11);
        str1 = Buffer.section('/',1,1);
        Buffer.remove(0,str1.length()+1);
        qDebug()<<"-----"<<str1;
        userinformSent(str1);
    }
    else if(Buffer.section('/',1,1) == "othersinform"){
        Buffer.remove(Buffer.indexOf("othersinform"),13);
        str1 = Buffer.section('/',1,1);
        Buffer.remove(0,str1.length()+1);
        userinformSent(str1);
    }
    //message = "/" + battleType + "/" + username + "/" + pokechoose;
    else if(Buffer.section('/',1,1) == "battleUP"){
        qDebug()<<"battleUP:"<<Buffer;
        Buffer.remove(Buffer.indexOf("battleUP"),9);
        str1 = Buffer.section('/',1,1);
        Buffer.remove(0,str1.length()+1);
        str2 = Buffer.section('/',1,1);
        Buffer.remove(0,str2.length()+1);
        str3 = Buffer.section('/',1,1);
        Buffer.remove(0,str3.length()+1);
        singleBattleSentUP(str1,str2,str3);
    }
    else if(Buffer.section('/',1,1) == "battleVS"){
        qDebug()<<"battleVS:"<<Buffer;
        Buffer.remove(Buffer.indexOf("battleVS"),9);
        str1 = Buffer.section('/',1,1);
        Buffer.remove(0,str1.length()+1);
        str2 = Buffer.section('/',1,1);
        Buffer.remove(0,str2.length()+1);
        str3 = Buffer.section('/',1,1);
        Buffer.remove(0,str3.length()+1);
        str4 = Buffer.section('/',1,1);
        Buffer.remove(0,str4.length()+1);
        singleBattleSentVS(str1,str2,str3,str4);
    }
    else{
        Buffer = "";
    }
}

// 处理等待的数据报
void receiver::sendMessage()
{
    qDebug()<<message;
    //message += "!";
    // 用于暂存我们要发送的数据
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    // 设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    // 获取已经建立的连接的套接字
    socket->write(block);
    socket->disconnectFromHost();
    // 发送数据成功后，显示提示
    
}

void receiver::acceptConnection()
{
    socket = tcpServer->nextPendingConnection();
    // 关闭服务器，不再进行监听
   // tcpServer->close();
    connect(socket, SIGNAL(readyRead()),this, SLOT(readMessage()));
    connect(socket,SIGNAL(disconnected()), socket,SLOT(deleteLater()));
}

void receiver::registerSent(QString str1,QString str2){
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    QSqlQuery query(db);
    qDebug() << "QSQLITE:";
    //query.exec("select * from pokedata");
    query.prepare("SELECT username,password FROM pokedata WHERE username = ? ");
    QString username = str1;
    query.addBindValue(username);
    query.exec();
    int num = 0;
    QString temp;
    while(query.next()){
        num++;
        temp = query.value(1).toString();
        qDebug()<<temp;
    }
    if(num != 0){
        message = "WORD";
        if(temp == str2)
            message = "OK";
    }
    else{
        message = "USER";
    }
    blockSize=0;
    sendMessage();
}

void receiver::newuserSent(QString str1,QString str2){
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    QSqlQuery query(db);
    qDebug() << "QSQLITE:";
    query.prepare("SELECT username FROM pokedata WHERE username = ? ");
    QString username = str1;
    query.addBindValue(username);
    query.exec();
    int num = 0;
    QString temp;
    QString a1,a2;
    while(query.next()){
        num++;
        temp = query.value(1).toString();
        qDebug()<<temp;
    }
    if(num == 0){
        message = "OK";
        query.clear();
        query.prepare("INSERT INTO pokedata (username, password, rate, primarypoke, seniorpoke, win,fail) "
                                     "VALUES (:username, :password, :rate, :primarypoke, :seniorpoke, :win,:fail)");
        query.bindValue(":username", str1);
        query.bindValue(":password", str2);
        query.bindValue(":rate", 0);
        query.bindValue(":primarypoke", 3);
        query.bindValue(":seniorpoke", 0);
        query.bindValue(":win",0);
        query.bindValue(":fail",0);
        query.exec();
        QString newpoke = randomCreate();
        query.prepare("insert into pokemondata (username, pokename, pokelevel, pokeexp, pokeskill1, pokeskill2, pokeskill3,id)"
                      "VALUES(:username, :pokename, :pokelevel, :pokeexp, :pokeskill1, :pokeskill2, :pokeskill3,:id)");
        query.bindValue(":username", str1);
        query.bindValue(":pokename", newpoke);
        query.bindValue(":pokelevel", 0);
        query.bindValue(":pokeexp", 0);
        query.bindValue(":pokeskill1", -1);
        query.bindValue(":pokeskill2", -1);
        query.bindValue(":pokeskill3", -1);
        query.bindValue(":id",1);
        query.exec();
        newpoke = randomCreate();
        query.clear();
        query.prepare("insert into pokemondata (username, pokename, pokelevel, pokeexp, pokeskill1, pokeskill2, pokeskill3,id)"
                      "VALUES(:username, :pokename, :pokelevel, :pokeexp, :pokeskill1, :pokeskill2, :pokeskill3,:id)");
        query.bindValue(":username", str1);
        query.bindValue(":pokename", newpoke);
        query.bindValue(":pokelevel", 0);
        query.bindValue(":pokeexp", 0);
        query.bindValue(":pokeskill1", -1);
        query.bindValue(":pokeskill2", -1);
        query.bindValue(":pokeskill3", -1);
        query.bindValue(":id",2);
        query.exec();
        newpoke = randomCreate();
        query.clear();
        query.prepare("insert into pokemondata (username, pokename, pokelevel, pokeexp, pokeskill1, pokeskill2, pokeskill3,id)"
                      "VALUES(:username, :pokename, :pokelevel, :pokeexp, :pokeskill1, :pokeskill2, :pokeskill3,:id)");
        query.bindValue(":username", str1);
        query.bindValue(":pokename", newpoke);
        query.bindValue(":pokelevel", 0);
        query.bindValue(":pokeexp", 0);
        query.bindValue(":pokeskill1", -1);
        query.bindValue(":pokeskill2", -1);
        query.bindValue(":pokeskill3", -1);
        query.bindValue(":id",3);
        query.exec();
    }
    else{
        message = "USER";
    }
    sendMessage();
}

void receiver::userinformSent(QString str1){
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    QSqlQuery query(db);
    query.prepare("SELECT username,password,rate,primarypoke,seniorpoke,win,fail FROM pokedata WHERE username = ? ");
    QString username = str1;
    query.addBindValue(username);
    query.exec();
    int num = 0;
    while(query.next()){
        num++;
        message = "/"+ query.value(0).toString() + "/" + query.value(2).toString() + "/" + query.value(3).toString() + "/" + query.value(4).toString() + "/" + query.value(5).toString() + "/" + query.value(6).toString();
        qDebug()<<query.value(0).toString()<<query.value(2).toString()<<query.value(3).toString()<<query.value(4).toString();
    }
    query.clear();
    query.prepare("SELECT username,pokename,pokelevel,pokeexp,pokeskill1,pokeskill2,pokeskill3,id FROM pokemondata WHERE username = ?");
    query.addBindValue(username);
    query.exec();
    while(query.next()){
        if(query.value((1)).toString() != ""){
        message = message + "/pokename/"+ query.value(1).toString() + "/" + query.value(2).toString() + "/" + query.value(3).toString() + "/" + query.value(4).toString() + "/" + query.value(5).toString() + "/" + query.value(6).toString()+"/"+query.value(7).toString();
        qDebug()<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString()<<query.value(4).toString()<<query.value(5).toString()<<query.value(6).toString();
        }
    }
    qDebug()<<message;
    if(num == 0)    message = "none";
    sendMessage();
}

void receiver::singleBattleSentUP(QString username,QString pokechoose,QString result){
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    QSqlQuery query(db);
    int num = 0;
    query.prepare("SELECT username,pokename,pokelevel,pokeexp,pokeskill1,pokeskill2,pokeskill3 FROM pokemondata WHERE id = ?");
    query.addBindValue(pokechoose.toInt());
    query.exec();
    QString pokenametemp;
    int pokeleveltemp,pokeexptemp,pokeskill1temp,pokeskill2temp,pokeskill3temp;
    while(query.next()){
            pokenametemp = query.value(1).toString();
            pokeleveltemp = query.value(2).toInt();
            pokeexptemp = query.value(3).toInt();
            pokeskill1temp = query.value(4).toInt();
            pokeskill2temp = query.value(5).toInt();
            pokeskill3temp = query.value(6).toInt();
    }
    int rate;
    int primarypoke,seniorpoke,win,fail;
    query.prepare("SELECT username, password, rate, primarypoke, seniorpoke, win, fail FROM pokedata WHERE username = ?");
    query.addBindValue(username);
    query.exec();
    while(query.next()){
        rate = query.value(2).toInt();
        primarypoke = query.value(3).toInt();
        seniorpoke = query.value(4).toInt();
        win = query.value(5).toInt();
        fail = query.value(6).toInt();
    }
    query.clear();
    pokemon *user;
    if(pokenametemp == "Bulbasaur"){
        user = new Bulbasaur();
        user->levelUP(pokeleveltemp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Lvysaur"){
        user = new Lvysaur(pokeleveltemp,pokeskill1temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Venusaur"){
        user = new Venusaur(pokeleveltemp,pokeskill1temp,pokeskill2temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "MegaVenusaur"){
        user = new MegaVenusaur(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Charmander"){
        user = new Charmander();
        user->levelUP(pokeleveltemp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Charmeleon"){
        user = new Charmeleon(pokeleveltemp,pokeskill1temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Charizard"){
        user = new Charizard(pokeleveltemp,pokeskill1temp,pokeskill2temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "MegaCharizardX"){
        user = new MegaCharizardX(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "MegaCharizardY"){
        user = new MegaCharizardY(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Squirtle"){
        user = new Squirtle();
        user->levelUP(pokeleveltemp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Wartortle"){
        user = new Wartortle(pokeleveltemp,pokeskill1temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Blastoise"){
        user = new Blastoise(pokeleveltemp,pokeskill1temp,pokeskill2temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "MegaBlastoise"){
        user = new MegaBlastoise(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
        user->setnowExp(pokeexptemp);
    }
    qDebug()<<"single:"<<pokenametemp<<pokeleveltemp<<pokeexptemp<<pokeskill1temp<<pokeskill2temp<<pokeskill3temp;
    if(result == "win"){
        user->expUP(100);
        query.prepare("UPDATE pokedata SET rate = ?,win = ?,fail = ? WHERE username = ?");
        query.bindValue(0, (int)((float)(win + 1)/(float)(win + fail + 1))*100);
        query.bindValue(1, win + 1);
        query.bindValue(2, fail);
        query.bindValue(3, username);
        query.exec();
    }
    else{
        query.prepare("UPDATE pokedata SET rate = ?,win = ?,fail = ? WHERE username = ?");
        query.bindValue(0, (int)(100*(float)(win)/(float)(win + fail + 1)));
        query.bindValue(1, win);
        query.bindValue(2, fail+1);
        query.bindValue(3, username);
        query.exec();
        user->expUP(20);
    }
    num = 0;
    if(user->getLevel()%10 == 0 && user->getnowExperience() == 0){
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()*10 + time.second()*1000);
        if(pokenametemp == "Bulbasaur"){
            user = new Lvysaur();
        }
        else if(pokenametemp == "Lvysaur"){
            user = new Venusaur(user);
        }
        else if(pokenametemp == "Venusaur"){
            user = new MegaVenusaur(user);
        }
        else if(pokenametemp == "Charmander"){
            user = new Charmeleon();
        }
        else if(pokenametemp == "Charmeleon"){
            user = new Charizard(user);
        }
        else if(pokenametemp == "Charizard"){
            if(qrand()%2 == 0){
                user = new MegaCharizardX(user);
            }
            else{
                user = new MegaCharizardY(user);
            }
        }
        else if(pokenametemp == "Squirtle"){
            user = new Wartortle();
        }
        else if(pokenametemp == "Wartortle"){
            user = new Blastoise(user);
        }
        else if(pokenametemp == "Blastoise"){
            user = new MegaBlastoise(user);
        }
        if(user->getLevel() == 20){
            query.prepare("UPDATE pokedata SET primarypoke = ?, seniorpoke = ? WHERE username = ?");
            query.bindValue(0, primarypoke - 1);
            query.bindValue(1, seniorpoke + 1);
            query.bindValue(2,username);
            query.exec();
        }
    }
    query.prepare("UPDATE pokemondata SET pokename = ?, pokelevel = ?,"
    "pokeexp = ?, pokeskill1 = ?, pokeskill2 = ?, pokeskill3 = ? WHERE id = ?");
    query.bindValue(0, user->returnPokename());
    query.bindValue(1, user->getLevel());
    query.bindValue(2, user->getnowExperience());
    query.bindValue(3, user->skillInitial()->getFirstSkill());
    qDebug()<<"1";
    query.bindValue(4, user->skillInitial()->getSecondSkill());
     qDebug()<<"2";
    query.bindValue(5, user->skillInitial()->getThirdSkill());
    query.bindValue(6, pokechoose.toInt());
    query.exec();
    qDebug()<<"3";
    qDebug()<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString()<<query.value(4).toString()<<query.value(5).toString()<<query.value(6).toString();
}

void receiver::singleBattleSentVS(QString username, QString pokechoose, QString result, QString pokedefeat){
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    QSqlQuery query(db);
    int num = 0;
    query.exec("select * from pokemondata");
    while(query.next()){
        num = query.value(7).toInt();
    }
    query.clear();
    query.prepare("SELECT username,pokename,pokelevel,pokeexp,pokeskill1,pokeskill2,pokeskill3 FROM pokemondata WHERE id = ?");
    query.addBindValue(pokechoose.toInt());
    query.exec();
    QString pokenametemp;
    int pokeleveltemp,pokeexptemp,pokeskill1temp,pokeskill2temp,pokeskill3temp;
    while(query.next()){
            pokenametemp = query.value(1).toString();
            pokeleveltemp = query.value(2).toInt();
            pokeexptemp = query.value(3).toInt();
            pokeskill1temp = query.value(4).toInt();
            pokeskill2temp = query.value(5).toInt();
            pokeskill3temp = query.value(6).toInt();
    }
    int rate;
    int primarypoke,seniorpoke,win,fail;
    query.prepare("SELECT username, password, rate, primarypoke, seniorpoke, win, fail FROM pokedata WHERE username = ?");
    query.addBindValue(username);
    query.exec();
    while(query.next()){
        rate = query.value(2).toInt();
        primarypoke = query.value(3).toInt();
        seniorpoke = query.value(4).toInt();
        win = query.value(5).toInt();
        fail = query.value(6).toInt();
    }
    query.clear();
    pokemon *user,*acquire;
    if(pokenametemp == "Bulbasaur"){
        user = new Bulbasaur();
        user->levelUP(pokeleveltemp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Lvysaur"){
        user = new Lvysaur(pokeleveltemp,pokeskill1temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Venusaur"){
        user = new Venusaur(pokeleveltemp,pokeskill1temp,pokeskill2temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "MegaVenusaur"){
        user = new MegaVenusaur(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Charmander"){
        user = new Charmander();
        user->levelUP(pokeleveltemp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Charmeleon"){
        user = new Charmeleon(pokeleveltemp,pokeskill1temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Charizard"){
        user = new Charizard(pokeleveltemp,pokeskill1temp,pokeskill2temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "MegaCharizardX"){
        user = new MegaCharizardX(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "MegaCharizardY"){
        user = new MegaCharizardY(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Squirtle"){
        user = new Squirtle();
        user->levelUP(pokeleveltemp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Wartortle"){
        user = new Wartortle(pokeleveltemp,pokeskill1temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "Blastoise"){
        user = new Blastoise(pokeleveltemp,pokeskill1temp,pokeskill2temp);
        user->setnowExp(pokeexptemp);
    }
    else if(pokenametemp == "MegaBlastoise"){
        user = new MegaBlastoise(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
        user->setnowExp(pokeexptemp);
    }
    if(pokedefeat == "Bulbasaur"){
        acquire = new Bulbasaur();
    }
    else if(pokedefeat == "Lvysaur"){
        acquire = new Lvysaur(pokeleveltemp,pokeskill1temp);
    }
    else if(pokedefeat == "Venusaur"){
        acquire = new Venusaur(pokeleveltemp,pokeskill1temp,pokeskill2temp);
    }
    else if(pokedefeat == "MegaVenusaur"){
        acquire = new MegaVenusaur(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
    }
    else if(pokedefeat == "Charmander"){
        acquire = new Charmander();
    }
    else if(pokedefeat == "Charmeleon"){
        acquire = new Charmeleon(pokeleveltemp,pokeskill1temp);
    }
    else if(pokedefeat == "Charizard"){
        acquire = new Charizard(pokeleveltemp,pokeskill1temp,pokeskill2temp);
    }
    else if(pokedefeat == "MegaCharizardX"){
        acquire = new MegaCharizardX(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
    }
    else if(pokedefeat == "MegaCharizardY"){
        acquire = new MegaCharizardY(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
    }
    else if(pokedefeat == "Squirtle"){
        acquire = new Squirtle();
    }
    else if(pokedefeat == "Wartortle"){
        acquire = new Wartortle(pokeleveltemp,pokeskill1temp);
    }
    else if(pokedefeat == "Blastoise"){
        acquire = new Blastoise(pokeleveltemp,pokeskill1temp,pokeskill2temp);
    }
    else if(pokedefeat == "MegaBlastoise"){
        acquire = new MegaBlastoise(pokeleveltemp,pokeskill1temp,pokeskill2temp,pokeskill3temp);
    }
    query.clear();
    qDebug()<<"single:"<<pokenametemp<<pokeleveltemp<<pokeexptemp<<pokeskill1temp<<pokeskill2temp<<pokeskill3temp;
    if(result == "win"){
        user->expUP(100);
        query.prepare("UPDATE pokedata SET rate = ?,win = ?,fail = ? WHERE username = ?");
        query.bindValue(0, (int)(100*((float)(win + 1)/(float)(win + fail + 1))));
        query.bindValue(1, win + 1);
        query.bindValue(2, fail);
        query.bindValue(3, username);
        query.exec();
        if(user->getLevel()%10 == 0 && user->getnowExperience() == 0){
            QTime time;
            time= QTime::currentTime();
            qsrand(time.msec()*10 + time.second()*1000);
            if(pokenametemp == "Bulbasaur"){
                user = new Lvysaur();
            }
            else if(pokenametemp == "Lvysaur"){
                user = new Venusaur(user);
            }
            else if(pokenametemp == "Venusaur"){
                user = new MegaVenusaur(user);
            }
            else if(pokenametemp == "Charmander"){
                user = new Charmeleon();
            }
            else if(pokenametemp == "Charmeleon"){
                user = new Charizard(user);
            }
            else if(pokenametemp == "Charizard"){
                if(qrand()%2 == 0){
                    user = new MegaCharizardX(user);
                }
                else{
                    user = new MegaCharizardY(user);
                }
            }
            else if(pokenametemp == "Squirtle"){
                user = new Wartortle();
            }
            else if(pokenametemp == "Wartortle"){
                user = new Blastoise(user);
            }
            else if(pokenametemp == "Blastoise"){
                user = new MegaBlastoise(user);
            }
            if(user->getLevel() == 20){
                query.prepare("UPDATE pokedata SET primarypoke = ?, seniorpoke = ? WHERE username = ?");
                query.bindValue(0, primarypoke - 1);
                query.bindValue(1, seniorpoke + 1);
                query.bindValue(2,username);
                query.exec();
            }
        }
        query.prepare("UPDATE pokemondata SET pokename = ?, pokelevel = ?,"
        "pokeexp = ?, pokeskill1 = ?, pokeskill2 = ?, pokeskill3 = ? WHERE id = ?");
        query.bindValue(0, user->returnPokename());
        query.bindValue(1, user->getLevel());
        query.bindValue(2, user->getnowExperience());
        query.bindValue(3, user->skillInitial()->getFirstSkill());
        qDebug()<<"1";
        query.bindValue(4, user->skillInitial()->getSecondSkill());
         qDebug()<<"2";
        query.bindValue(5, user->skillInitial()->getThirdSkill());
        query.bindValue(6, pokechoose.toInt());
        query.exec();
        query.clear();
        query.prepare("insert into pokemondata (username, pokename, pokelevel, pokeexp, pokeskill1, pokeskill2, pokeskill3,id)"
                      "VALUES(:username, :pokename, :pokelevel, :pokeexp, :pokeskill1, :pokeskill2, :pokeskill3,:id)");
        query.bindValue(":username", username);
        query.bindValue(":pokename", acquire->returnPokename());
        query.bindValue(":pokelevel", acquire->getLevel());
        query.bindValue(":pokeexp", 0);
        query.bindValue(":pokeskill1", acquire->skillInitial()->getFirstSkill());
        query.bindValue(":pokeskill2", acquire->skillInitial()->getSecondSkill());
        query.bindValue(":pokeskill3", acquire->skillInitial()->getThirdSkill());
        query.bindValue(":id",num+1);
        query.exec();
        if(acquire->getLevel()<20){
            query.prepare("UPDATE pokedata SET primarypoke = ?, seniorpoke = ? WHERE username = ?");
            query.bindValue(0, primarypoke + 1);
            query.bindValue(1, seniorpoke);
            query.bindValue(2, username);
            query.exec();
        }
        else{
            query.prepare("UPDATE pokedata SET primarypoke = ?, seniorpoke = ? WHERE username = ?");
            query.bindValue(0, primarypoke);
            query.bindValue(1, seniorpoke + 1);
            query.bindValue(2, username);
            query.exec();
        }
        qDebug()<<"3";
    }
    else{
        query.prepare("UPDATE pokedata SET rate = ?,primarypoke = ?, seniorpoke = ?,win = ?,fail = ? WHERE username = ?");
        query.bindValue(0, (int)(100*(float)(win)/(float)(win + fail + 1)));
        if(user->getLevel()<20){
            query.bindValue(1,primarypoke - 1);
            query.bindValue(2,seniorpoke);
        }
        else{
            query.bindValue(1,primarypoke);
            query.bindValue(2,seniorpoke - 1);
        }
        query.bindValue(3, win);
        query.bindValue(4, fail + 1);
        query.bindValue(5, username);
        query.exec();
        query.prepare("DELETE FROM pokemondata WHERE id = ?");
        query.bindValue(0, pokechoose.toInt());
        query.exec();
        int sum = 0;
        query.exec("select * from pokemondata");
        while(query.next()){
            sum++;
        }
        if(sum == 0){
            QString newpoke = randomCreate();
            query.prepare("insert into pokemondata (username, pokename, pokelevel, pokeexp, pokeskill1, pokeskill2, pokeskill3,id)"
                          "VALUES(:username, :pokename, :pokelevel, :pokeexp, :pokeskill1, :pokeskill2, :pokeskill3,:id)");
            query.bindValue(":username", username);
            query.bindValue(":pokename", newpoke);
            query.bindValue(":pokelevel", 0);
            query.bindValue(":pokeexp", 0);
            query.bindValue(":pokeskill1", -1);
            query.bindValue(":pokeskill2", -1);
            query.bindValue(":pokeskill3", -1);
            query.bindValue(":id",1);
            query.exec();
            query.prepare("UPDATE pokedata SET primarypoke = ? WHERE username = ?");
            query.bindValue(0, primarypoke + 1);
            query.bindValue(1, username);
            query.exec();
        }
    }
}

void receiver::on_lineEdit1_textEdited(const QString &arg1)
{
    askuser = arg1;
}

void receiver::on_pushButton2_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    QSqlQuery query(db);
    qDebug() << "QSQLITE:";
    //query.exec("select * from pokedata");
    query.prepare("SELECT username,password,rate,primarypoke,seniorpoke,win,fail FROM pokedata WHERE username = ? ");
    QString username = askuser;
    query.addBindValue(username);
    query.exec();
    int num = 0;
    QString temp1,temp2,temp3,temp4,temp5,temp6;
    while(query.next()){
        num++;
        temp1 = query.value(1).toString();
        temp2 = query.value(2).toString();
        temp3 = query.value(3).toString();
        temp4 = query.value(4).toString();
        temp5 = query.value(5).toString();
        temp6 = query.value(6).toString();
    }
    if(num == 0){
        ui->textBrowser->setText("用户不存在");
    }
    else{
        ui->textBrowser->setText("username:" + username + "\npassword:" + temp1 + "\nrate:" + temp2 + "\nprimarypoke:" + temp3 + "\nseniorpoke:" + temp4 + "\nwin:"+temp5+"\nfailed"+temp6);
        QSqlQueryModel *model = new QSqlQueryModel(this);
        query.prepare("SELECT username,pokename,pokelevel,pokeexp,pokeskill1,pokeskill2,pokeskill3,id FROM pokemondata WHERE username = ?");
        //query.exec("select * from pokemondata");
        QString username = askuser;
        query.addBindValue(username);
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("username"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("pokename"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("pokelevel"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("pokeexp"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("pokeskill1"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("pokeskill2"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("pokeskill3"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("id"));
        ui->tableView->setModel(model);
    }
}

void receiver::on_pushButton2_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("QSQLITE");
    QSqlQuery query(db);
    QString name1,word1;
    qDebug() << "QSQLITE:";
    query.exec("select * from pokedata");
    while(query.next()){
        name1 = query.value(0).toString();
        word1 = query.value(1).toString();
        qDebug()<<name1<<word1;
    }
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select * from pokedata");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("username"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("password"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("rate"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("primarypoke"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("seniorpoke"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("win"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("fail"));
    // model->removeColumn(1); //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    ui->tableView->setModel(model);
}
