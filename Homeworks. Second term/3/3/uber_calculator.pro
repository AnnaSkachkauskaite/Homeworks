QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uber_calculator
TEMPLATE = app


SOURCES += main.cpp\
        ubercalculator.cpp \
    stack.cpp \
    pointstack.cpp \
    calc.cpp \
    calculator.cpp \
    calculatortest.cpp

HEADERS  += ubercalculator.h \
    stack.h \
    pointstack.h \
    calc.h \
    calculator.h \
    calculatortest.h

FORMS    += ubercalculator.ui

QMAKE_CXXFLAGS += -std=c++0x
