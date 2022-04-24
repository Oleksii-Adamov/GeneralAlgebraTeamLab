#include "intmodulo.h"
#include <stdexcept>

IntModulo::IntModulo()
{

}

void IntModulo::set_num(long long input)
{
    num = input;
}

long long IntModulo::get_num() const
{
    return num;
}

IntModulo::IntModulo(long long num)
    : num(num)
{

}

IntModulo::IntModulo(long long num, unsigned long long modulo)
    : num(num)
{
    mod(modulo);
}

IntModulo::IntModulo(const IntModulo& other)
{
    num = other.get_num();
}

IntModulo& IntModulo::operator=(const IntModulo& other)
{
    num = other.get_num();
    return *this;
}

void IntModulo::mod(unsigned long long modulo)
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

void IntModulo::add(const IntModulo& other, unsigned long long modulo)
{
    num += other.get_num();
    mod(modulo);
}

void IntModulo::substract(const IntModulo& other, unsigned long long modulo)
{
    num -= other.get_num();
    mod(modulo);
}
void IntModulo::multiply(const IntModulo& other, unsigned long long modulo)
{
    num *= other.get_num();
    mod(modulo);
}
