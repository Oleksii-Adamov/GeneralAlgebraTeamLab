#ifndef POLINOME_H
#define POLINOME_H

#include "Lib_global.h"
#include "task1/intmodulo.h"
#include <vector>
#include <string>

class LIB_EXPORT Polinome {
private:
    std::vector<IntModulo> coefficients;

public:
    //constructors
    Polinome();
    Polinome(int power);
    Polinome(std::vector<IntModulo> coefficients);
    Polinome(std::string writtenPolinome);

    //Methods
    Polinome add(const Polinome& polinome, unsigned long long modulo);
    Polinome subtract(const Polinome& polinome, unsigned long long modulo);
    Polinome multiply(const Polinome& polinome, unsigned long long modulo);
};

#endif // POLINOME_H
