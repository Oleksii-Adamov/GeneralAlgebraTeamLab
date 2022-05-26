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


LIB_EXPORT int GCD(int a, int b);
LIB_EXPORT int m(int q, int n, int i);
LIB_EXPORT int euler(int n);
LIB_EXPORT int multCount(int q, int n, int i);
LIB_EXPORT Polinome ri(int q, int n, int i);
LIB_EXPORT int d(int q, int n);
LIB_EXPORT std::vector<Polinome> computePolynomialProductOfCyclotomicPlynomial(int q, int n, int i);

#endif 
