#ifndef NUMBERMODULO_H
#define NUMBERMODULO_H

#include "Lib_global.h"

class LIB_EXPORT NumberModulo
{
public:
    NumberModulo();
    // constuctor from integer
    NumberModulo(long long num);
    // constuctor from integer by modulo
    NumberModulo(long long num, unsigned long long modulo);
private:
    long long num = 0;
public:
    void set_num(const long long input);
    long long get_num() const;
    // change num to num (mod modulo > 0) , num < 0 taken into account
    void mod(unsigned long long modulo);
    // adds to num other , with respect to given modulo > 0
    void add(const NumberModulo& other, unsigned long long modulo);
    // substracts from num other , with respect to given modulo > 0
    void substract(const NumberModulo& other, unsigned long long modulo);
    // multiplies num by other , with respect to given modulo > 0
    void multiply(const NumberModulo& other, unsigned long long modulo);
};

#endif // NUMBERMODULO_H
