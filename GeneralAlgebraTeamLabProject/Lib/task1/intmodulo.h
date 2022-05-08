#ifndef INTMODULO_H
#define INTMODULO_H

#include "Lib_global.h"
#include <string>
#include <iostream>

class LIB_EXPORT IntModulo
{
public:
    // constructors

    // default constructor num = 0
    IntModulo();
    // constuctor from integer
    IntModulo(long long num);
    // constuctor from integer with respect to given modulus > 0
    IntModulo(long long num, unsigned long long modulus);
    // constructor from string (std::invalid_argument if contains non digits before digits, but if string is "123d", then num := 123)
    IntModulo(const std::string& input);
    // copy constructor
    IntModulo(const IntModulo& other);
    // copy assignment operator
    IntModulo& operator=(const IntModulo& other);
private:
    // fields

    // I do not store modulus, because that would be a waste of memory (we will work in fields with some constant modulus, so
    // there is no sense to store it with every integer
    long long num = 0;
public:
    // methods

    void set_num(const long long input);
    long long get_num() const;
    // change num to num (mod modulus > 0) , num < 0 taken into account
    void mod(unsigned long long modulus);
    // adds to num other , with respect to given modulus > 0
    void add(const IntModulo& other, unsigned long long modulus);
    // substracts from num other , with respect to given modulus > 0
    void substract(const IntModulo& other, unsigned long long modulus);
    // multiplies num by other , with respect to given modulo > 0
    void multiply(const IntModulo& other, unsigned long long modulus);
    // divides a number by a number, with respect to given modulus > 0
    void divide(long long num1, unsigned long long modulus);
    // finds reversed element
    IntModulo findReversed(unsigned long long modulus);
    // num = num^(exponent) (mod modulus > 0) complexity O(log exponent) using Right-to-left binary method
    void pow(unsigned long long exponent, unsigned long long modulus);
    // return string representation of num
    std::string ToString() const;
    // read num from string (std::invalid_argument if contains non digits before digits, but if string is "123d", then num := 123)
    void FromString(const std::string& input);
    // overload of >> for streams
    LIB_EXPORT friend std::istream &operator>>(std::istream& in, IntModulo& obj );
};


#endif // INTMODULO_H
