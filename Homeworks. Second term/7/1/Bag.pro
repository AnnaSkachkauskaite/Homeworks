QT       += core
QT       += testlib
QT       -= gui

TARGET = Bag
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    bag.cpp \
    bagtest.cpp

HEADERS += \
    bag.h \
    bagtest.h
