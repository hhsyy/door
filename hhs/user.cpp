#include "user.h"
#include "ui_user.h"
#include <mainwindow.h>
#include <QMessageBox>
#include "QDataStream";
#include <QElapsedTimer>
#include <user.h>

user::user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
    this->setWindowTitle("client");
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_clicked()
{
   MainWindow *mw = new MainWindow();
   mw->show();
   this->close();
}

void user::on_pushButton_2_clicked()
{
    m_tcpsocket = new QTcpSocket(this);
    m_tcpsocket->abort();

    m_tcpsocket->connectToHost("192.168.140.1",1205);//设置客户端的端口号

    connect(m_tcpsocket,SIGNAL(readyRead()),
                this,SLOT(readData()));//用于接受数据
         QByteArray message = "help-harry up";
         QDataStream out(&message,QIODevice::WriteOnly);
         out.setVersion(QDataStream::Qt_4_7);
         m_tcpsocket->write(message);
            k="0";
         QElapsedTimer q;
         q.start();
         while(q.elapsed()<5000)
         QCoreApplication::processEvents();

         if(!t.isFinished()&&k=="0"){
             QMessageBox::information(this,"ok","no message");
              t.quit();
         }

}



void user::readData()

{
    QString i = m_tcpsocket->readAll();
    k = i.toUtf8();
    if(k=="4"){
        if(t.isFinished()){
      QMessageBox::information(this,"ok","message is ok,but is late");

      }else{

          QMessageBox::information(this,"ok","message is ok");
          t.quit();

      }
  }

}

void user::start(){



}

void user::on_pushButton_3_clicked()
{
    user *w;
     this->close();
}
