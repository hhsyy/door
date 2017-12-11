#include <QtGui/QApplication>
#include "user.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   user w;
    w.show();

    return a.exec();
}
