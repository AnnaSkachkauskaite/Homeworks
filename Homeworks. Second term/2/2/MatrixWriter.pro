QT       += core

QT       -= gui
QT       += testlib

TARGET = MatrixWriter
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    writer.cpp \
    filewriter.cpp \
    consolewriter.cpp \
    writertest.cpp

HEADERS += \
    writer.h \
    filewriter.h \
    consolewriter.h \
    writertest.h
