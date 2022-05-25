#ifndef INTMODULO_H
#define INTMODULO_H

#include "Lib_global.h"
#include <string>
#include <iostream>
#include <map>

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
    // == operator (same modulus is implied, just lhs.get_num() == rhs.get_num())
    friend inline bool operator==(const IntModulo& lhs, const IntModulo& rhs){return lhs.get_num() == rhs.get_num();};
    // != operator
    friend inline bool operator!=(const IntModulo& lhs, const IntModulo& rhs){return !(lhs == rhs);};
    // < operator
    friend inline bool operator<(const IntModulo& lhs, const IntModulo& rhs){return lhs.get_num() < rhs.get_num();};
    // > operator
    friend inline bool operator>(const IntModulo& lhs, const IntModulo& rhs){return lhs.get_num() > rhs.get_num();};
    // <= operator
    friend inline bool operator<=(const IntModulo& lhs, const IntModulo& rhs){return lhs.get_num() <= rhs.get_num();};
    // >= operator
    friend inline bool operator>=(const IntModulo& lhs, const IntModulo& rhs){return lhs.get_num() >= rhs.get_num();};
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
    // subtracts from num other , with respect to given modulus > 0
    void subtract(const IntModulo& other, unsigned long long modulus);
    // multiplies num by other , with respect to given modulo > 0
    void multiply(const IntModulo& other, unsigned long long modulus);
    // divides a number by a number, with respect to given modulus > 0, throws exception if no reverse to divider
    void divide(const IntModulo& num1, unsigned long long modulus);
    // finds reversed element (return num = 0 if no reversed)
    IntModulo findReversed(unsigned long long modulus) const;
    // num = num^(exponent) (mod modulus > 0) complexity O(log exponent) using Right-to-left binary method
    void pow(unsigned long long exponent, unsigned long long modulus);
    // return string representation of num
    std::string ToString() const;
    // read num from string (std::invalid_argument if contains non digits before digits, but if string is "123d", then num := 123)
    void FromString(const std::string& input);
    // overload of >> for streams
    LIB_EXPORT friend std::istream &operator>>(std::istream& in, IntModulo& obj);

    // checks if this number is prime using Miller–Rabin primality test
    bool isPrime(int iterationsNum);

    // counts the positive integers up to num that are relatively prime to num.
    long long phi();
    // finds the smallest positive m for every integer between 1 and num that is coprime to n
    long long carmichael();
private:
    // methods
    static bool miillerTest(long long d, long long n);
};


#endif // INTMODULO_H
