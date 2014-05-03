QT       += core

QT       -= gui
QT       += testlib

TARGET = Vector
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    vectortest.cpp

HEADERS += \
    vector.h \
    vectortest.h
