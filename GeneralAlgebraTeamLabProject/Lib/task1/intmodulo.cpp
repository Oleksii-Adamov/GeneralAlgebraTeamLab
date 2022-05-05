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

<<<<<<< Updated upstream
IntModulo IntModulo::findReversed(unsigned long long modulo) {
    unsigned long long firstNum = modulo;
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
    result.mod(modulo);
    return result;
=======
void IntModulo::divide(long long num1, unsigned long long modulo) 
{
    IntModulo other;
    other.set_num(num1);
    num *= other.findReversed(modulo).get_num();
    mod(modulo);
}

IntModulo IntModulo::findReversed(unsigned long long modulo) {
    if(modulo > 0 && this->get_num() % modulo != 0){
        unsigned long long firstNum = modulo;
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
        result.mod(modulo);
        IntModulo twin = IntModulo(this->get_num());
        twin.multiply(result, modulo); 
        if(twin.get_num() != 1)
            IntModulo result = IntModulo(0);
        return result;
    }
    else {
        IntModulo result = IntModulo(0);
        return result;
    }
>>>>>>> Stashed changes
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
