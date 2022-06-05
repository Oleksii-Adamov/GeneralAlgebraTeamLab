QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

DEPENDPATH += . ../Lib

INCLUDEPATH += ../Lib

LIBS += ../Lib/libLib.a

#LIBS += -L../Lib/release/ -lLib

SOURCES +=  tst_discretelogarithm.cpp
