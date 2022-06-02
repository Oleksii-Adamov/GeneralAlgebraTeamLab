#ifndef REVERSEPOLINOM_H
#define REVERSEPOLINOM_H

#include "Lib_global.h"
#include "task11/polinome.cpp"
#include "task13/polinome_division.cpp"

class LIB_EXPORT ReversePolinom
{
    Polinome a, b, reverse;
public:
    ReversePolinom(Polinome a, Polinome p, int modulo);
    Polinome inverse(Polinome a, Polinome p, int modulo);
    Polinome get_reverse();
};

#endif // REVERSEPOLINOM_H
