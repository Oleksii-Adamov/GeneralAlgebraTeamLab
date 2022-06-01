#include "reversepolinom.h"

Polinome ReversePolinom::xGCD(Polinome a, Polinome b, int field)
{
    if(b == Polinome()){
        this->x = Polinome("1");
        this->y = Polinome("0");
        return a;
    }

    DivisionResult<Polinome> c = a.divide(b, field);

    Polinome x1, y1, gcd = xGCD(b, *c.remainder, field);
    this->x = y1;
    Polinome a1 = a;
    DivisionResult<Polinome> a2 = a1.divide(b, field);
    Polinome q1 = *a2.quotient;
    Polinome mult = q1.multiply(y1, field);
    this->y = x1.subtract(mult, field);
    return gcd;
}

ReversePolinom::ReversePolinom(Polinome a, Polinome b, int field){

    Polinome x;
//   x = xGCD(a, b, field);
}
