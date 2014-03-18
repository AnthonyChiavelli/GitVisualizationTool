#-------------------------------------------------
#
# Project created by QtCreator 2014-02-23T20:32:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GitVisualizationTool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gcommitnode.cpp \
    gcommitarrow.cpp \
    greposcene.cpp

HEADERS  += mainwindow.h \
    gcommitnode.h \
    gcommitarrow.h \
    greposcene.h

FORMS    += mainwindow.ui
