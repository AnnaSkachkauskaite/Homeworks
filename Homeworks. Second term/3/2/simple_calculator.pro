QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simple_calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculation.cpp \
    calculatortest.cpp

HEADERS  += mainwindow.h \
    calculation.h \
    calculatortest.h

FORMS    += mainwindow.ui
