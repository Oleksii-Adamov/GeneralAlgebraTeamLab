#include "reversepolinom.h"

Polinome ReversePolinom::inverse(Polinome a, Polinome p, int modulo)
{
    Polinome t = Polinome("0");
    Polinome newt = Polinome("1");
    Polinome r = p;
    Polinome newr = a;

    while (!(newr == Polinome("0"))){
        Polinome quotient = *r.divide(newr, modulo).quotient;
        Polinome quotient1 = quotient;
        Polinome r1 = r;
        r = newr;

        newr = r1.subtract(quotient.multiply(newr, modulo), modulo);
        Polinome t1 = t;
        t = newt;

        newt = t1.subtract(quotient1.multiply(newt, modulo), modulo);
    }

    if(r.degree().value > 0){
        return Polinome("0");//MEOW
    }
    
    Polinome res = Polinome("1");
    res.divide(r, modulo);
    res = res.multiply(t, modulo);

    return res;
    
}

ReversePolinom::ReversePolinom(Polinome a, Polinome p, int modulo){
   this->reverse = inverse(a, p, modulo);
}
Polinome ReversePolinom::get_reverse(){
    return this->reverse;
}
