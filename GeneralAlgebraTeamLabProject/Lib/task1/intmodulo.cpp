#include "intmodulo.h"
#include <numeric>
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

IntModulo::IntModulo(long long num, unsigned long long modulus)
    : num(num)
{
    mod(modulus);
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

void IntModulo::mod(unsigned long long modulus)
{
    // check for zero
    if (modulus == 0)
        throw std::invalid_argument("modulus = 0");
    if (num < 0) {
        long long abs_num = -num;
        // add floor(abs_num / modulus) * modulus
        num += (abs_num / modulus) * modulus;
        // taking another step if needed
        if (num < 0)
            num += modulus;
    }
    else
        num %= modulus;
}

void IntModulo::add(const IntModulo& other, unsigned long long modulus)
{
    num += other.get_num();
    mod(modulus);
}

void IntModulo::subtract(const IntModulo& other, unsigned long long modulus)
{
    num -= other.get_num();
    mod(modulus);
}
void IntModulo::multiply(const IntModulo& other, unsigned long long modulus)
{
    num *= other.get_num();
    mod(modulus);
}

void IntModulo::divide(const IntModulo& other, unsigned long long modulus)
{
    IntModulo reversed = other.findReversed(modulus);
    if (reversed.num == 0) {
        throw std::logic_error("divider has no reverse");
    }
    multiply(reversed, modulus);
}

IntModulo IntModulo::findReversed(unsigned long long modulus) const {
    if(std::gcd(this->get_num(), modulus) == 1 && this->get_num() > 0){
        unsigned long long firstNum = modulus;
        unsigned long long secondNum = this->get_num();
        int firstNumComposition[] = {1, 0};
        int secondNumComposition[] = {0, 1};
        while(secondNum != 1) {
            unsigned long long div = firstNum / secondNum;
            for(int i = 0; i < 2; ++i) {
                firstNumComposition[i] -= div * secondNumComposition[i];
                std::swap(firstNumComposition[i], secondNumComposition[i]);
            }
            firstNum -= div * secondNum;
            std::swap(firstNum, secondNum);
        }
        IntModulo result = IntModulo(secondNumComposition[1]);
        result.mod(modulus);
        IntModulo twin = IntModulo(this->get_num());
        twin.multiply(result, modulus);
        if(twin.get_num() != 1)
            result = IntModulo(0);
        return result;
    }
    else {
        IntModulo result = IntModulo(0);
        return result;
    }
}

std::string IntModulo::ToString() const
{
    return std::to_string(num);
}

std::istream &operator>>(std::istream& in, IntModulo& obj)
{
    long long input_num;
    in >> input_num;
    obj.set_num(input_num);
    return in;
}

void IntModulo::FromString(const std::string& input)
{
    num = std::stoll(input);
}

IntModulo::IntModulo(const std::string& input)
{
    FromString(input);
}

void IntModulo::pow(long long exponent, unsigned long long modulus)
{
    // fast modular exponentiation O(log exponent) using Right-to-left binary method
    //https://en.wikipedia.org/wiki/Modular_exponentiation#Right-to-left_binary_method
    if (modulus == 1) {
        num = 0;
        return;
    }
    // throws exception if modulus = 0
    mod(modulus);
    // negative exponentiation is positive exponentiation of inverse element
    if (exponent < 0) {
        IntModulo reversed = this->findReversed(modulus);
        if (reversed.get_num() == 0) {
            throw std::logic_error("element has no reverse");
        }
        num = reversed.get_num();
        exponent *= -1;
    }
    // base_in_pow = base^(2^i)
    unsigned long long base_in_pow = num;
    unsigned long long result = 1;
    // result = product(base^(bit(i)*2^i)) (mod m), i=0,n-1, bit(i) = i-th bit from end(least significant, right)
    while (exponent > 0) {
        // if right bit is 1
        if (exponent % 2 == 1) {
            result *= base_in_pow;
            result %= modulus;
        }
        base_in_pow *= base_in_pow;
        base_in_pow %= modulus;
        // delete right bit
        exponent = exponent >> 1;
    }
    num = result;
}
