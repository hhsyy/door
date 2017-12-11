#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T09:41:51
#
#-------------------------------------------------

QT       += core gui sql
QT       += network
QT +=sql;
TARGET = table
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog_d.cpp \
    dialog_s.cpp

HEADERS  += mainwindow.h \
    dialog_d.h \
    dialog_s.h

FORMS    += mainwindow.ui \
    dialog_d.ui \
    dialog_s.ui
