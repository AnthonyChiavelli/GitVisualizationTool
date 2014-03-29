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
        ui/mainwindow.cpp \
    model/gcommitnode.cpp \
    model/remote.cpp \
    model/repository.cpp \
    model/gituser.cpp \
    model/commitnode.cpp \
    model/localrepository.cpp \
    model/branch.cpp \
    model/tag.cpp \
    ui/ggraphicsscene.cpp \
    ui/gcommitarrow.cpp

HEADERS  += ui/mainwindow.h \
    model/gcommitnode.h \
    model/remote.h \
    model/repository.h \
    model/gituser.h \
    model/commitnode.h \
    model/localrepository.h \
    model/branch.h \
    model/tag.h \
    ui/ggraphicsscene.h \
    ui/gcommitarrow.h


FORMS    += mainwindow.ui
