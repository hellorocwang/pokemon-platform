#include <QtGui>
#include <QApplication>
#include "receiver.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    receiver w;
    w.show();

    return a.exec();
}
