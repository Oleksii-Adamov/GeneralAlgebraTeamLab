#ifndef REVERSEPOLINOM_H
#define REVERSEPOLINOM_H

#include "Lib_global.h"
#include "task11/polinome.cpp"
#include "task13/polinome_division.cpp"

class LIB_EXPORT ReversePolinom
{
    Polinome a, b, x, y, gcd;
public:
    ReversePolinom(Polinome a, Polinome b, int field);
    Polinome xGCD(Polinome a, Polinome b, int field);
};

#endif // REVERSEPOLINOM_H
