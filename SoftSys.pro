#-------------------------------------------------
#
# Project created by QtCreator 2014-09-25T08:39:37
#
#-------------------------------------------------

QT       += core gui
QT       += webkitwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoftSys
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    display.qrc
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9
DESTDIR = $$PWD
PROJECT_DIR = $$PWD
