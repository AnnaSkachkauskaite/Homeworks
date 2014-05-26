QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1Gun
TEMPLATE = app


SOURCES += main.cpp\
        mainWindow.cpp \
    bullet.cpp \
    cannon.cpp \
    target.cpp

HEADERS  += mainWindow.h \
    bullet.h \
    cannon.h \
    target.h

FORMS    += mainWindow.ui
