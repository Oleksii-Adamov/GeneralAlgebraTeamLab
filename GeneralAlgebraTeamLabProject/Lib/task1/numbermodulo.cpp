#include "numbermodulo.h"
#include <stdexcept>

NumberModulo::NumberModulo()
{

}

void NumberModulo::set_num(long long input)
{
    num = input;
}

long long NumberModulo::get_num() const
{
    return num;
}

void NumberModulo::mod(unsigned long long modulo)
{
    // check for zero
    if (modulo == 0)
        throw std::invalid_argument("modulo = 0");
    if (num < 0) {
        long long abs_num = -num;
        // add floor(abs_num / modulo) * modulo
        num += (abs_num / modulo) * modulo;
        // taking another step if needed
        if (num < 0)
            num += modulo;
    }
    else
        num %= modulo;
}

void NumberModulo::add(const NumberModulo& other, unsigned long long modulo)
{

}

void NumberModulo::substract(const NumberModulo& other, unsigned long long modulo)
{

}
void NumberModulo::multiply(const NumberModulo& other, unsigned long long modulo)
{

}
