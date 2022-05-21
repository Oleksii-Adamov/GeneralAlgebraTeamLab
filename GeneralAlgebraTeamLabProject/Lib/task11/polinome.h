#ifndef POLINOME_H
#define POLINOME_H

#include "Lib_global.h"
#include "task1/intmodulo.h"
#include <vector>
#include <string>

class LIB_EXPORT Polinome {
private:
    std::vector<IntModulo>* coefficients;

public:
    //constructors
    Polinome();
    Polinome(int power);
    Polinome(std::vector<IntModulo>* coefficients);
    /**
     * The string should be like this: " 3x^2 + 35x^4 + 22x + 321".
     * There could be whitespaces between numbers, variables and powers (" 3x^ 2 + 35  x ^ 4   + 22 x  + 321 " ).
     * The variable should be only x.
     * No "*" sings.
     */
    Polinome(const std::string& writtenPolinome);
    ~Polinome();

    //Methods
    Polinome add(const Polinome& polinome, unsigned long long modulus);
    Polinome subtract(const Polinome& polinome, unsigned long long modulus);
    Polinome multiply(const Polinome& polinome, unsigned long long modulus);
    std::string toString();
    Polinome Polinome::CyclotomicPolynomial(long long n, unsigned long long modulus);

    bool operator== (const Polinome& polinome) const;
};

#endif // POLINOME_H
