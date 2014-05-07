#-------------------------------------------------
#
# Project created by QtCreator 2014-02-23T20:32:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GitVisualizationTool
TEMPLATE = app
CONFIG += C11++
QMAKE_CXXFLAGS += -std=c++11


SOURCES += branch.cpp \
        commitnode.cpp \
        main.cpp\
        mainwindow.cpp \
        gcommitarrow.cpp \
        gcommitnode.cpp \
        ggraphicsscene.cpp \
        gitapi.cpp \
        gitapiresponse.cpp \
        gitobject.cpp \
        gituser.cpp \
        localrepoparser.cpp \
        localrepository.cpp \
        remote.cpp \
        repository.cpp \
        sha1.cpp \
        tag.cpp \
        gitinitdialog.cpp \
        gitadddialog.cpp \
        gitmergedialog.cpp \
        gitcommitdialog.cpp \
        gitbranchdialog.cpp \
        gitrevertdialog.cpp \
        gitpulldialog.cpp \
        gitpushdialog.cpp \
        logger.cpp \
        github/githubwebapi.cpp \
        github/githubrepoparser.cpp \
    github/signup.cpp \
    github/signin.cpp

HEADERS  += branch.h \
        commitnode.h \
        mainwindow.h \
        gcommitarrow.h \
        gcommitnode.h \
        ggraphicsscene.h \
        gitapi.h \
        gitapiresponse.h \
        gitobject.h \
        gituser.h \
        localrepoparser.h \
        localrepository.h \
        remote.h \
        repository.h \
        sha1.h \
        tag.h \
        gitinitdialog.h \
        gitadddialog.h \
        gitmergedialog.h \
        gitcommitdialog.h \
        gitbranchdialog.h \
        gitrevertdialog.h \
        gitpulldialog.h \
        gitpushdialog.h \
        logger.h \ 
        github/githubrepoparser.h \
        github/githubwebapi.h \
    github/signup.h \
    github/signin.h

FORMS    += mainwindow.ui \
        gitinitdialog.ui \
        gitadddialog.ui \
        gitmergedialog.ui \
        gitcommitdialog.ui \
        gitbranchdialog.ui \
        gitrevertdialog.ui \
        gitpulldialog.ui \
        gitpushdialog.ui \
    github/signup.ui \
    github/signin.ui \
    GitHubView.ui

RESOURCES += resources/images.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/ -lcurl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/ -lcurl
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lcurl

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/release/libcurl.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/debug/libcurl.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/release/curl.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/debug/curl.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libcurl.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/ -lcurl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/ -lcurl
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lcurl

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include
