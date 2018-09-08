#ifndef RECEIVER_H
#define RECEIVER_H

#include <QMainWindow>
#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlRelationalDelegate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QMainWindow>

namespace Ui {
    class receiver;
}

class receiver : public QMainWindow
{
    Q_OBJECT

public:
    explicit receiver(QWidget *parent = 0);
    ~receiver();

private:
    Ui::receiver *ui;
    QTcpServer *tcpServer;
    QTcpSocket *socket;
    QString message;
    QString Buffer;
    quint16 blockSize;
    QString askuser;
    QSqlTableModel *model;
private slots:
    void sendMessage();
    void acceptConnection();
    void readMessage();
    void registerSent(QString str1, QString str2);
    void newuserSent(QString str1,QString str2);
    void userinformSent(QString str1);
    void singleBattleSentUP(QString username, QString pokechoose, QString result);
    void singleBattleSentVS(QString username, QString pokechoose, QString result, QString pokedefeat);
    void on_lineEdit1_textEdited(const QString &arg1);
    void on_pushButton2_clicked();
    void on_pushButton2_2_clicked();
};

#endif // RECEIVER_H
