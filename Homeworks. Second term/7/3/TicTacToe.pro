#-------------------------------------------------
#
# Project created by QtCreator 2014-05-07T17:21:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        gamewindow.cpp \
    tictactoe.cpp

HEADERS  += gamewindow.h \
    tictactoe.h

FORMS    += gamewindow.ui
