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
    task7/discrete_logarithm.cpp \
    task13/polinome_copy.cpp \
    task13/polinome_division.cpp \
    task13/polinome_gcd.cpp \
    task13/polynome_degree.cpp \
    task5/pollardfactorization.cpp \
    task6/sqrt.cpp\
    task15/ri.cpp \
    task20/generator.cpp \
    task8/findgroup.cpp \
    task19/reversepolinom.cpp \
    utils.cpp
    
HEADERS += \
    Lib_global.h \
    lib.h \
    task1/intmodulo.h \
    task11/polinome.h \
    task7/discrete_logarithm.h \
    task13/degree_result.h \
    task13/division_result.h \
    task13/polinome_copy.h \
    task13/polinome_degree.h \
    task13/polinome_division.h \
    task13/polinome_gcd.h \
    task5/pollardfactorization.h \
    task6/sqrt.h \
    task15/ri.h \
    task19/reversepolinom.h \
    utils.h \
    task20/generator.h \
    task8/findgroup.h 
   

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
