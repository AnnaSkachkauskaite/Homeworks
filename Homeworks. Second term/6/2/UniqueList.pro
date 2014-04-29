QT       += core
QT       += testlib
QT       -= gui

TARGET = UniqueList
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    list.cpp \
    pointlist.cpp \
    uniquelist.cpp \
    exeption.cpp \
    duplicateexeption.cpp \
    nonexistentelemenyexeption.cpp \
    uniquelisttest.cpp

HEADERS += \
    list.h \
    pointlist.h \
    uniquelist.h \
    exeption.h \
    duplicateexeption.h \
    nonexistentelemenyexeption.h \
    uniquelisttest.h
