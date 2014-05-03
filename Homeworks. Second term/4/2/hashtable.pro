QT       += core

QT       -= gui
QT       += testlib

TARGET = hashtable
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += main.cpp \
    hashfunction.cpp \
    hashtable.cpp \
    hashtabletest.cpp

HEADERS += \
    hashfunction.h \
    hashtable.h \
    hashtabletest.h
