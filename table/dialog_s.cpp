#include "dialog_s.h"
#include "ui_dialog_s.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QMessageBox>

Dialog_s::Dialog_s(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_s)
{
    ui->setupUi(this);
    this->setWindowTitle("insert");
}

Dialog_s::~Dialog_s()
{
    delete ui;
}

void Dialog_s::on_pushButton_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/hhs/user.db");
    if ( !db.open()){

    }else {
        QSqlQuery query( db );
        QString username = ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();

        QString select_sql = "insert into user values('"+username+"','"+password+"')";

        if(!query.exec(select_sql))
        {
        qDebug()<<query.lastError();
        }
        else
        {
                query.exec();
             QMessageBox::warning(this,tr("ok"),tr("insert is ok"),QMessageBox::Ok);

        }
         db.close();
}

}
