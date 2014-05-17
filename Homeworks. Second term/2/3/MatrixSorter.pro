QT       += core

QT       -= gui
QT       += testlib

TARGET = MatrixSorter
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    matrixsort.cpp \
    matrixsorttest.cpp

HEADERS += \
    matrixsort.h \
    matrixsorttest.h
