#-------------------------------------------------
#
# Project created by QtCreator 2017-05-12T22:45:36
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += -std=c++11

LIBS += -lglut -lGLU

TARGET = MyOpenGLWithQt
TEMPLATE = app

LIBS += -lglut -lGLU

SOURCES += main.cpp\
        mainwindow.cpp \
    myglwidget.cpp

HEADERS  += mainwindow.h \
    myglwidget.h

FORMS    += mainwindow.ui
