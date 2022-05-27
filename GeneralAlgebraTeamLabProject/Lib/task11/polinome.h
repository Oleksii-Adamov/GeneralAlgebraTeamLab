#ifndef POLINOME_H
#define POLINOME_H

#include "Lib_global.h"
#include "task1/intmodulo.h"
#include "task13/division_result.h"
#include "task13/polinome_division.h"
#include "task13/degree_result.h"

#include <vector>
#include <string>
#include <algorithm>

class LIB_EXPORT Polinome {
private:
    std::vector<IntModulo>* coefficients;

public:
    //constructors
    Polinome();
    Polinome(int power);
    Polinome(std::vector<IntModulo>* coefficients);
    Polinome(const Polinome& other);
    /**
     * The string should be like this: " 3x^2 + 35x^4 + 22x + 321".
     * There could be whitespaces between numbers, variables and powers (" 3x^ 2 + 35  x ^ 4   + 22 x  + 321 " ).
     * The variable should be only x.
     * No "*" sings.
     * No same powers
     */
    Polinome(const std::string& writtenPolinome);
    ~Polinome();


    //Methods
    std::vector<IntModulo>* getCoefficients();
    Polinome add(const Polinome& polinome, unsigned long long modulus) const;
    Polinome subtract(const Polinome& polinome, unsigned long long modulus) const;
    Polinome multiply(const Polinome& polinome, unsigned long long modulus) const;
    Polinome reduce(unsigned long long modulus) const;
    std::string toString() const;
    //task 18 methods
    Polinome add(const Polinome& polinome, const Polinome& irreducible, unsigned long long modulus) const;
    Polinome subtract(const Polinome& polinome, const Polinome& irreducible, unsigned long long modulus) const;
    Polinome multiply(const Polinome& polinome, const Polinome& irreducible, unsigned long long modulus) const;
    Polinome pow(long long power, unsigned long long modulus) const;

    // task12 methods
    Polinome derivative(unsigned long long modulus);
    IntModulo evaluate(IntModulo x, unsigned long long modulus);

    // task13 methods
    DegreeResult degree() const;
    DivisionResult<Polinome> divide(const Polinome& divider, unsigned long long modulus) const;
    Polinome& operator= (const Polinome& polinome);
    Polinome* copy() const;
    Polinome* gcd(const Polinome& p, unsigned long long modulo) const;
    bool operator== (const Polinome& polinome) const;
};
LIB_EXPORT DivisionResult<Polinome> CyclotomicPolynomial(unsigned long long n, unsigned long long module);
// Function to check for Eisensteins
// Irreducubility Criterion
LIB_EXPORT bool checkIrreducibilty(Polinome& polinome, unsigned long long modulus);



#endif // POLINOME_H
