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
    // constuctor from integer with respect to given modulo > 0
    IntModulo(long long num, unsigned long long modulo);
    // constructor from string
    IntModulo(const std::string& input);
    // copy constructor
    IntModulo(const IntModulo& other);
    // copy assignment operator
    IntModulo& operator=(const IntModulo& other);
private:
    // fields

    // I do not store modulo, because that would be a waste of memory (we will work in fields with some constant modulo, so
    // there is no sense to store it with every integer
    long long num = 0;
public:
    // methods

    void set_num(const long long input);
    long long get_num() const;
    // change num to num (mod modulo > 0) , num < 0 taken into account
    void mod(unsigned long long modulo);
    // adds to num other , with respect to given modulo > 0
    void add(const IntModulo& other, unsigned long long modulo);
    // substracts from num other , with respect to given modulo > 0
    void substract(const IntModulo& other, unsigned long long modulo);
    // multiplies num by other , with respect to given modulo > 0
    void multiply(const IntModulo& other, unsigned long long modulo);
    // finds reversed element
    IntModulo findReversed(unsigned long long modulo);
    // return string representation of num
    std::string ToString() const;
    // read num from string
    void FromString(const std::string& input);
    // overload of >> for streams
    LIB_EXPORT friend std::istream &operator>>(std::istream& in, IntModulo& obj );
};

#endif // INTMODULO_H
