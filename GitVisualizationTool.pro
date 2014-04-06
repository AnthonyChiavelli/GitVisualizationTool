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
        remote.cpp \
        repository.cpp \
        gituser.cpp \
        commitnode.cpp \
        localrepository.cpp \
        branch.cpp \
        tag.cpp \
        ggraphicsscene.cpp \
        gcommitarrow.cpp

HEADERS  += mainwindow.h \
        gcommitnode.h \
        remote.h \
        repository.h \
        gituser.h \
        commitnode.h \
        localrepository.h \
        branch.h \
        tag.h \
        ggraphicsscene.h \
        gcommitarrow.h


FORMS    += mainwindow.ui
