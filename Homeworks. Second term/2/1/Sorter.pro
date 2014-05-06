QT       += core

QT       -= gui
QT       += testlib

TARGET = Sorter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    qsort.cpp \
    bubblesort.cpp \
    insertionsort.cpp \
    sortertest.cpp

HEADERS += \
    sort.h \
    qsort.h \
    bubblesort.h \
    insertionsort.h \
    sortertest.h
