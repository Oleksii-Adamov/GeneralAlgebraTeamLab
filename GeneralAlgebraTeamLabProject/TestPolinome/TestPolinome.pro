QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
DEPENDPATH += . ../Lib
INCLUDEPATH += ../Lib
#LIBS += -L../Lib/debug/ -lLib
#LIBS += -L../Lib/release/ -lLib
LIBS += ../Lib/libLib.a

SOURCES +=  tst_test_polinome.cpp
