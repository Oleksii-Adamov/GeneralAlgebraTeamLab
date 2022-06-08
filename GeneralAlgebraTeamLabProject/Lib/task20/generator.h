#ifndef GENERATOR_H
#define GENERATOR_H

#include "Lib_global.h"
#include "task11/polinome.h"
#include "task13/polinome_division.h"
#include "task13/division_result.h"

// p1 - irreducible
LIB_EXPORT std::vector<int> findDivisors (int n);
LIB_EXPORT long orderOfPolinome(long modulus, const Polinome p1, const Polinome p2);
LIB_EXPORT long degreeOfPolinome(const Polinome p);
LIB_EXPORT long maxOrderOfPolinome(long modulus, const Polinome p);
LIB_EXPORT bool isGenerator(long modulus, const Polinome p1, const Polinome p2);

#endif
