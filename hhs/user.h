#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QtNetwork>
#include <QThread>
namespace Ui {
    class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = 0);
    ~user();

private:
    Ui::user *ui;
    QTcpSocket *m_tcpsocket;
    QTcpServer *tcpServer;
    QString k;
    QString l;
    QThread t;

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void readData();
    void start();
};

#endif // USER_H
