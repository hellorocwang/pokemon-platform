 #-------------------------------------------------
#
# Project created by QtCreator 2016-12-06T20:25:28
#
#-------------------------------------------------
QT += sql
QT       += core gui
QT += network
TARGET = sqlModel
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++14
TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        receiver.cpp \
    pokemon.cpp \
    alluser.cpp

HEADERS  += receiver.h \
    connection.h \
    pokemon.h \
    alluser.h

FORMS    += receiver.ui \
    alluser.ui

DISTFILES +=
