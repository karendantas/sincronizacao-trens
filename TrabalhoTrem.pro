#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T06:45:49
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrabalhoTrem
TEMPLATE = app


SOURCES +=\
    client.cpp \
    clientwindow.cpp \
    controllersocketmain.cpp \
        mainwindow.cpp \
    trem.cpp

HEADERS  += mainwindow.h \
    clientwindow.h \
    controllersocketmain.h \
    trem.h

FORMS    += mainwindow.ui \
    clientwindow.ui

CONFIG  += c++11
LIBS += -pthread
