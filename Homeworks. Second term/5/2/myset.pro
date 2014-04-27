QT       += core
QT += testlib
QT       -= gui

TARGET = myset
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG += c++11
SOURCES += main.cpp \
    settest.cpp

HEADERS += \
    myset.h \
    settest.h
