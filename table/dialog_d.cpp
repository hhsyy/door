#include "dialog_d.h"
#include "ui_dialog_d.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QMessageBox>

Dialog_d::Dialog_d(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_d)
{
    ui->setupUi(this);
    this->setWindowTitle("delete");
}

Dialog_d::~Dialog_d()
{
    delete ui;
}

void Dialog_d::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/hhs/user.db");
    QSqlQuery query;
    if ( !db.open()){
        qFatal("failed to connect.") ;
    }else {
        QSqlQuery query( db );

        QString text = ui->lineEdit->text().toUtf8();
        QString select_sql = "delete from user where username='"+text+"'";


        query.prepare(select_sql);

        if(!query.exec(select_sql))
        {
        qDebug()<<query.lastError();
        }
        else
        {

             QMessageBox::warning(this,tr("ok"),tr("delete is ok"),QMessageBox::Ok);
             db.close();

        }

    }
}
