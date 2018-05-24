#-------------------------------------------------
#
# Project created by QtCreator 2018-04-27T13:49:13
#
#-------------------------------------------------

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WifiBot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wifibotcontroller.cpp

HEADERS  += mainwindow.h \
    wifibotcontroller.h \
    direction.h

FORMS    += mainwindow.ui
