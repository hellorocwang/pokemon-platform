#ifndef ALLUSER_H
#define ALLUSER_H

#include <QMainWindow>

namespace Ui {
class alluser;
}

class alluser : public QMainWindow
{
    Q_OBJECT

public:
    explicit alluser(QWidget *parent = 0);
    ~alluser();

private:
    Ui::alluser *ui;
};

#endif // ALLUSER_H
