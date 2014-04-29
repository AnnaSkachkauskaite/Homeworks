QT       += core
QT += testlib
QT       -= gui

TARGET = HierarchicalCalculator
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += main.cpp \
    sum.cpp \
    subtract.cpp \
    mult.cpp \
    div.cpp \
    number.cpp \
    calculator.cpp \
    calculatortest.cpp

HEADERS += \
    treeelement.h \
    sum.h \
    subtract.h \
    mult.h \
    div.h \
    number.h \
    calculator.h \
    calculatortest.h
