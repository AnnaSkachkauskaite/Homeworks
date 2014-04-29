QT       += core
QT       += testlib
QT       -= gui

TARGET = SharedPointer
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    sharedpointertest.cpp

HEADERS += \
    sharedpointer.h \
    sharedpointertest.h
