#include "generator.h"
#include <cmath>
#include <bits/stdc++.h>

std::vector<int> findDivisors (int n)
{
    std::vector<int> res;
    int k = sqrt(n);
    for (int i=1; i<=k; i++)
        {
            if (n%i == 0)
            {
                if (n/i == i) res.emplace_back(i);
                else
                {
                    res.emplace_back(i);
                    res.emplace_back(n/i);
                }
            }
        }
    sort(res.begin(), res.end());
    return res;
}

//x^2 + 1 , x
long orderOfPolinome(long modulus, const Polinome irreducible, const Polinome polinome) {
    long n = maxOrderOfPolinome(modulus, irreducible);
    auto divisors = findDivisors(n);
    Polinome result = polinome;
     for(auto i : divisors)
     {
         if(polinome.pow(i,irreducible,modulus).divide(irreducible,modulus).remainder->toString() == "1")
             return i;
     }
     return 0;
}

long degreeOfPolinome(Polinome p) {
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

long maxOrderOfPolinome(long modulus, const Polinome p) {
   return pow(modulus, degreeOfPolinome(p))-1;
}

bool isGenerator(long modulus, const Polinome p1, const Polinome p2 ) {
    return orderOfPolinome(modulus, p1, p2) == maxOrderOfPolinome(modulus, p1);
}
