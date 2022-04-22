#ifndef NUMBERMODULO_H
#define NUMBERMODULO_H

#include "Lib_global.h"

class LIB_EXPORT NumberModulo
{
public:
    NumberModulo();
private:
    long long num = 0;
    long long modulo = 2;
public:
    void set_num(long long input);
    long long get_num();
    void set_modulo(long long input);
    long long get_modulo();
};

#endif // NUMBERMODULO_H
