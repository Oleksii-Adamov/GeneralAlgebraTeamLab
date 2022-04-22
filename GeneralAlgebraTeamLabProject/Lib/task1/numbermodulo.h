#ifndef NUMBERMODULO_H
#define NUMBERMODULO_H

#include "Lib_global.h"

class LIB_EXPORT NumberModulo
{
public:
    NumberModulo();
private:
    long long num;
public:
    void set_num(long long input);
    long long get_num();
};

#endif // NUMBERMODULO_H
