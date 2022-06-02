#ifndef RI_H
#define RI_H

#include "Lib_global.h"
#include "task1/intmodulo.h"
#include <vector>
#include "task11/polinome.h"
#include <cmath>
#include <queue>
#include "task13/polinome_gcd.h"
#include "task20/generator.h"


LIB_EXPORT long long NumberGCD(long long a, long long b);
LIB_EXPORT long long m(long long q, long long n, long long i);
LIB_EXPORT long long multCount(long long q, long long n, long long i);
LIB_EXPORT Polinome ri(long long q, long long n, long long i);
LIB_EXPORT long long d(long long q, long long n);
LIB_EXPORT std::vector<Polinome> computePolynomialProductOfCyclotomicPlynomial(long long q, long long n);

#endif 
