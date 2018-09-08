#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPainter>
#include <QMimeData>
#include <QDrag>
#include <QSound>
#include "singleBattle.h"
#include "register.h"
#include "othersinform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setStyleSheet("border-image:url(imagines/background.png)");
    //QPainter painter(this);
    //QPixmap pix;
    QPixmap pixmap = QPixmap("imagines/background.png").scaled(this->size());
    QPalette palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
 /*   pix.load("imagines/background.jpg");
    painter.drawPixmap(0,0,100,100,pix);
    painter.translate(100,100); //将（100，100）设为坐标原点
    painter.drawPixmap(0,0,100,100,pix);
    setAcceptDrops(true);
    QLabel *label = new QLabel(this);
    QPixmap pixmap("imagines/1.png");
    QPixmap pix=pixmap.scaled(163,163).scaled(150, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    label ->setPixmap(pix);
    label ->resize(pix.size());
    label ->move(100,100);
    label ->setAttribute(Qt::WA_DeleteOnClose);*/
}

/*void MainWindow::mousePressEvent(QMouseEvent *event){
    QLabel *child = static_cast<QLabel *>(childAt(event->pos()));
    if(!child->inherits(("QLabel")))    return;
    QPixmap pixmap = *child->pixmap();
    QByteArray itemData;
    QDataStream dataStream(&itemData,QIODevice::WriteOnly);
    dataStream<<pixmap<<QPoint(event->pos()-child->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("myimage/png", itemData);
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos()-child->pos());

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(),QColor(127,127,127,127));
    child->setPixmap(tempPixmap);

    if(drag->exec(Qt::CopyAction|Qt::MoveAction,Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else{
        child->show();
        child->setPixmap(pixmap);
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event){
    if(event->mimeData()->hasFormat("myimage/png")){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event){
    if(event->mimeData()->hasFormat("myimage/png")){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event){
    if(event->mimeData()->hasFormat("myimage/png")){
        QByteArray itemData = event->mimeData()->data("myimage/png");
        QDataStream dataStream(&itemData,QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        dataStream>>pixmap>>offset;
        QLabel *newLabel = new QLabel(this);
        newLabel->setPixmap(pixmap);
        newLabel->resize(pixmap.size());
        newLabel->move(event->pos()-offset);
        newLabel->show();
        newLabel->setAttribute(Qt::WA_DeleteOnClose);
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else{
        event->ignore();
    }
}
*/
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton1_clicked()
{
    QSound::play("imagines/pushbutton.wav");
    Register *widget = new Register(this);
    widget->show();
}

void MainWindow::on_pushButton2_clicked()
{
    QSound::play("imagines/pushbutton.wav");
    //singleBattle *widget = new singleBattle(this);
    //widget->show();
}

void MainWindow::on_pushButton4_clicked()
{
    QSound::play("imagines/pushbutton.wav");
    othersinform *widget = new othersinform(this);
    widget->show();
}

void MainWindow::on_pushButton3_clicked()
{
    QSound::play("imagines/pushbutton.wav");
}
