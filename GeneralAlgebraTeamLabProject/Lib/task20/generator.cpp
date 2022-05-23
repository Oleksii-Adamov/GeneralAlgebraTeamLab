#include "generator.h"
#include <cmath>

//x^2 + 1 , x
int orderOfPolinome(int modulus, const Polinome p1, const Polinome p2) {
    int order = 1;
    bool found = false;
    Polinome result = p2;
     while (!found){
         result = p2.multiply(p2, modulus);
         if (result.getRemainder(p1, modulus) == 1)
         {
             return order;
        }
        order++;
    }
}

int degreeOfPolinome(const Polinome p) {
    int degree = 0;
    for (int i = p.coefficients->size()-1; i >= 0; i--)
    {
        if ((*p.coefficients)[i] != 0)
        {
            degree = i;
        }
    }
    return degree;
}

int maxOrderOfPolinome(int modulus, const Polinome p) {
   return pow(modulus, degreeOfPolinome(p))-1;
}

bool isGenerator(int modulus, const Polinome p) {
    return degreeOfPolinome(p) == maxOrderOfPolinome(modulus, p);
}