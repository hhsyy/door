#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket *m_tcpsocket;
    QTcpServer *tcpServer;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void readdata();

};


#endif // MAINWINDOW_H
