#include "warn.h"
#include "ui_warn.h"
#include <QMessageBox>

warn::warn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::warn)
{
    ui->setupUi(this);

}

warn::~warn()
{
    delete ui;
}




