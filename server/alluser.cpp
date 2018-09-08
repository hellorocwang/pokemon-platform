#include "alluser.h"
#include "ui_alluser.h"

alluser::alluser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::alluser)
{
    ui->setupUi(this);
}

alluser::~alluser()
{
    delete ui;
}
