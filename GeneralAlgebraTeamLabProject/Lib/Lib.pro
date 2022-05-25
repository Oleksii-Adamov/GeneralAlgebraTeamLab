QT -= gui

TEMPLATE = lib
DEFINES += LIB_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lib.cpp \
    task1/intmodulo.cpp \
    task11/polinome.cpp \
    task5/pollardfactorization.cpp

HEADERS += \
    Lib_global.h \
    lib.h \
    task1/intmodulo.h \
    task11/polinome.h \
    task13/division_result.hpp \
    task13/polinome_division.hpp \
    task5/pollardfactorization.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
