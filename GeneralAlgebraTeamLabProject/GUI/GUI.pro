QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEPENDPATH += . ../Lib
INCLUDEPATH += ../Lib
LIBS += -L../Lib/debug/ -lLib
LIBS += -L../Lib/release/ -lLib

SOURCES += \
    finitefieldwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    polynomialfieldwindow.cpp \
    polynomialringwindow.cpp

HEADERS += \
    finitefieldwindow.h \
    mainwindow.h \
    polynomialfieldwindow.h \
    polynomialringwindow.h \
    validation.h

FORMS += \
    finitefieldwindow.ui \
    mainwindow.ui \
    polynomialfieldwindow.ui \
    polynomialringwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
