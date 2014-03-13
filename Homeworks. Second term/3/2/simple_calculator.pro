#-------------------------------------------------
#
# Project created by QtCreator 2014-03-09T18:31:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simple_calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculation.cpp

HEADERS  += mainwindow.h \
    calculation.h

FORMS    += mainwindow.ui
