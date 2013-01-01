#-------------------------------------------------
#
# Project created by QtCreator 2012-09-28T11:58:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TermProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    train.cpp \
    adddialog.cpp \
    searchnum.cpp \
    searchstation.cpp

HEADERS  += mainwindow.h \
    train.h \
    adddialog.h \
    searchnum.h \
    searchstation.h

FORMS    += mainwindow.ui \
    adddialog.ui \
    searchnum.ui \
    searchstation.ui
