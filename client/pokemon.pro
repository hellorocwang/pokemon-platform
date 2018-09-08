#-------------------------------------------------
#
# Project created by QtCreator 2016-11-16T20:42:46
#
#-------------------------------------------------

QT       += core gui
QT       += network

QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pokemon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pokemon.cpp \
    register.cpp \
    newuser.cpp \
    userinform.cpp \
    singlebattle.cpp \
    othersinform.cpp

HEADERS  += mainwindow.h \
    pokemon.h \
    register.h \
    newuser.h \
    userinform.h \
    singlebattle.h \
    othersinform.h \
    ipaddress.h

FORMS    += mainwindow.ui \
    register.ui \
    newuser.ui \
    userinform.ui \
    singlebattle.ui \
    othersinform.ui


QT += sql


RC_FILE += myico.rc
