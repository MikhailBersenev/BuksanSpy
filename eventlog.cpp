#include "eventlog.h"
#include "ui_eventlog.h"

eventlog::eventlog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eventlog)
{
    ui->setupUi(this);
}

eventlog::~eventlog()
{
    delete ui;
}
