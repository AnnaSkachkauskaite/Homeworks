#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T21:39:46
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += testlib

TARGET = localNet
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    computer.cpp \
    net.cpp \
    nettest.cpp

HEADERS += \
    computer.h \
    net.h \
    nettest.h
