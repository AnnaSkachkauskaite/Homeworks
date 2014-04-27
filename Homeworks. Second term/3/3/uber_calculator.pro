#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T13:47:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uber_calculator
TEMPLATE = app


SOURCES += main.cpp\
        ubercalculator.cpp \
    stack.cpp \
    pointstack.cpp \
    calculator.cpp

HEADERS  += ubercalculator.h \
    stack.h \
    pointstack.h \
    calculator.h

FORMS    += ubercalculator.ui

QMAKE_CXXFLAGS += -std=c++0x
