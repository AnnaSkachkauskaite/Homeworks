QT       += core

QT       -= gui

TARGET = hashtable
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += main.cpp \
    hashfunction.cpp \
    hashtable.cpp

HEADERS += \
    hashfunction.h \
    hashtable.h
