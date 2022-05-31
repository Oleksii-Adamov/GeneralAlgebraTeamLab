#include "generator.h"
#include <cmath>

//x^2 + 1 , x
int orderOfPolinome(int modulus, const Polinome irreducible, const Polinome polinome) {
    int order = 1;
    Polinome result = polinome;
     while (result.toString() != Polinome("1").toString()){
         order++;
         result = result.multiply(polinome, modulus);
         result = *result.divide(irreducible, modulus).remainder;
    }
     return order;
}

int degreeOfPolinome(Polinome p) {
    int degree = 0;
    for (int i = p.getCoefficients()->size()-1; i >= 0; i--)
    {

        if ((*p.getCoefficients())[i].ToString() != "0")
        {
            return i;
        }
    }
    return degree;
}

int maxOrderOfPolinome(int modulus, const Polinome p) {
   return pow(modulus, degreeOfPolinome(p))-1;
}

bool isGenerator(int modulus, const Polinome p1, const Polinome p2 ) {
    return orderOfPolinome(modulus, p1, p2) == maxOrderOfPolinome(modulus, p1);
}
