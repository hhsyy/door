#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QMessageBox>
#include <dialog_d.h>
#include <dialog_s.h>
#include <warn.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("data table");
    ui->tableWidget->setColumnCount(2);
       QStringList m_Header;
       m_Header<<QString("user")<<QString("password");
       ui->tableWidget->setHorizontalHeaderLabels(m_Header);
       ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);


       tcpServer =new QTcpServer(this);
       connect(tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
       start();
     }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/hhs/user.db");
    QSqlQuery query;
    QString username;
    QString password;
    if ( !db.open())
       {

    }else {
         QSqlQuery query( db );
        QString select_sql = "select username,password from user";
        query.prepare(select_sql);


        if(!query.exec(select_sql))
        {
        qDebug()<<query.lastError();
        }
        else
        {
        while(query.next())
        {
            username = query.value(0).toString();
            password = query.value(1).toString();

            ui->tableWidget->insertRow(query.ValuesAsRows);
            ui->tableWidget->setItem(query.ValuesAsRows,0,new QTableWidgetItem(username));
            ui->tableWidget->setItem(query.ValuesAsRows,1,new QTableWidgetItem(password));
            db.close();
        }
        }

    }


}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog_d *de = new Dialog_d();
    de->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog_s *s = new Dialog_s();
    s->show();
}



void MainWindow::start()

{
    if(!tcpServer->listen(QHostAddress::Any,1205))
{
    close();
    return;
}
}

void MainWindow::acceptConnection()
{
    tcpSocket =tcpServer->nextPendingConnection();
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readdata()));
}

void MainWindow::readdata()

{
    QString fromClient = tcpSocket->readAll();
    QString a = fromClient.toUtf8();

    QByteArray message = "0";
    QStringList myList = a.split("-");

    QString   name=myList[0];
    QString   pw=myList[1];

    if(name=="help"){

       QMessageBox::information(this,"ok",a);
       message="4";
       QDataStream out(&message,QIODevice::WriteOnly);
       tcpSocket->write(message);
    }else{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("C:/Users/hhs/user.db");
    QSqlQuery query;
    if ( !db.open())
       {

    }else {
         QSqlQuery query( db );
        QString select_sql = "select * from user";
        query.prepare(select_sql);


        if(!query.exec(select_sql))
        {
        qDebug()<<query.lastError();
        }
        else
        {
        while(query.next())
        {
            QString username = query.value(0).toString();
            QString password = query.value(1).toString();

            if(name==username.toUtf8() and pw==password.toUtf8()){
               message = "1";
            }
        }
        QDataStream out(&message,QIODevice::WriteOnly);
        tcpSocket->write(message);
    }
    }
}
}

void MainWindow::on_write()
{

}

