#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("localhost");
        db.setDatabaseName("hhs");
        db.setUserName("root");
        db.setPassword("123");
        if(db.open())
        {
            QSqlQuery query;
            query.exec("select * from hhs");
            while(query.next())
            {
                int id = query.value(0).toInt();
                QString str = query.value(1).toString();
                qDebug() << id << "|" << str;
            }
            db.close();
        }
        else
        {
            qDebug() << "opened error";
        }


    MainWindow w;
    w.show();


    return a.exec();
}
