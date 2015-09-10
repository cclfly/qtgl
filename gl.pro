#-------------------------------------------------
#
# Project created by QtCreator 2015-09-09T17:05:36
#
#-------------------------------------------------

QT       += opengl core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gl
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
        glwidget.cpp

HEADERS  += widget.h\
        glwidget.h

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=c++1y
