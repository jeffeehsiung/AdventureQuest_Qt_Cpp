#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T11:11:10
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++17
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \


HEADERS  += mainwindow.h\
            world.h\

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
