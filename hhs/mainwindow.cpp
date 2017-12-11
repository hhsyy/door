#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "QDataStream";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("login");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QByteArray username ,password;
    username = ui ->lineEdit->text().toUtf8();
    password = ui ->lineEdit_2->text().toUtf8();

    if(username.isEmpty()&&password.isEmpty()){
        QMessageBox::information(this,"warm!","user or password is emoty!");

    }else{
        m_tcpsocket = new QTcpSocket(this);
        m_tcpsocket->abort();

        m_tcpsocket->connectToHost("192.168.140.1",1205);//设置客户端的端口号
        connect(m_tcpsocket,SIGNAL(readyRead()),
                    this,SLOT(readdata()));//用于接受数据


             QByteArray message = username+"-"+password;
             QDataStream out(&message,QIODevice::WriteOnly);
             out.setVersion(QDataStream::Qt_4_7);
             m_tcpsocket->write(message);


    }
}

void MainWindow::readdata()

{
    QString i = m_tcpsocket->readAll();
    QString k = i.toUtf8();

    if(k=="0"){
      QMessageBox::information(this,"ok","username or password is fail");
    }else if(k=="1"){
      QMessageBox::information(this,"ok","login is ok");
    }
}



void MainWindow::on_pushButton_2_clicked()
{
   MainWindow *w;
     w->close();
}
