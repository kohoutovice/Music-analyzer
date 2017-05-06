#-------------------------------------------------
#
# Project created by QtCreator 2017-05-02T22:23:38
#
#-------------------------------------------------

QT       += testlib multimedia

QT       -= gui

TARGET = tst_tests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_tests.cpp \
    ../Music-analyzer/musicanalyzer.cpp
HEADERS += ../Music-analyzer/musicanalyzer.h

INCLUDEPATH += ../Music-analyzer
DEFINES += SRCDIR=\\\"$$PWD/\\\"
