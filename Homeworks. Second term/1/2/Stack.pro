QT       += core

QT       -= gui
QT       += testlib

TARGET = Stack
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    stack.cpp \
    arrstack.cpp \
    pointstack.cpp \
    calculator.cpp \
    pointstacktest.cpp \
    arraystacktest.cpp

HEADERS += \
    stack.h \
    arrstack.h \
    pointstack.h \
    calculator.h \
    pointstacktest.h \
    arraystacktest.h
