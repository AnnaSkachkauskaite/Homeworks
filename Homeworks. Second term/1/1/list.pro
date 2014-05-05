QT       += core

QT       -= gui
QT       += testlib

TARGET = list
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    arrlist.cpp \
    list.cpp \
    pointlist.cpp \
    pointerlisttest.cpp \
    arraylisttest.cpp

HEADERS += \
    arrlist.h \
    list.h \
    pointlist.h \
    pointerlisttest.h \
    arraylisttest.h

QMAKE_CXXFLAGS += -std=c++0x
