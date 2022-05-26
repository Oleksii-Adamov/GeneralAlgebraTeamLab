#ifndef GENERATOR_H
#define GENERATOR_H

#include "Lib_global.h"
#include "task11/polinome.h"
#include "task13/polinome_division.h"
#include "task13/division_result.h"

LIB_EXPORT int orderOfPolinome(int modulus, const Polinome p1, const Polinome p2);
LIB_EXPORT int degreeOfPolinome(const Polinome p);
LIB_EXPORT int maxOrderOfPolinome(int modulus, const Polinome p);
LIB_EXPORT bool isGenerator(int modulus, const Polinome p1, const Polinome p2);

#endif
