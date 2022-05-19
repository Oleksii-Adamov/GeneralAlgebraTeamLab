#include "intmodulo.h"
#include <random>
#include <stdexcept>
#include <string>

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

void IntModulo::substract(const IntModulo& other, unsigned long long modulus)
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
    multiply(other.findReversed(modulus), modulus);
}

IntModulo IntModulo::findReversed(unsigned long long modulus) const {
    if(modulus > 0 && this->get_num() % modulus != 0){
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

void IntModulo::pow(unsigned long long exponent, unsigned long long modulus)
{
    // fast modular exponentiation O(log exponent) using Right-to-left binary method
    //https://en.wikipedia.org/wiki/Modular_exponentiation#Right-to-left_binary_method
    if (modulus == 1) {
        num = 0;
        return;
    }
    // throw expeption if modulus = 0
    mod(modulus);
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

bool isPrime(unsigned long long n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (unsigned long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

long long legendreSymbol(unsigned long long a, unsigned long long n)
{
    if (a == 1)
    {
        return 1;
    }
    if ((a % 2 == 0) && (a != 0))
    {
        return legendreSymbol(a / 2, n) * pow(-1, (n * n - 1) / 8);
    }
    if (a % 2 != 0)
    {
        return legendreSymbol(n % a, a) * pow(-1, (a - 1) * (n - 1) / 4);
    }
    return 0;
}


std::optional<std::pair<IntModulo, IntModulo>> IntModulo::sqrt(unsigned long long p)
{
    if (isPrime(p))
    {
        if (this->get_num() > p-1)
            throw std::invalid_argument("modulus-1 must be greater or equal to the number");
        if (p % 1 != 0)
            throw std::invalid_argument("modulus should be integer");

        if (legendreSymbol(this->get_num(), p) == -1)
            return std::nullopt;

        // random numbers
        const int range_from  = 1;
        const int range_to    = p-1;

        std::random_device                        rand_dev;
        std::mt19937                              generator(rand_dev());
        std::uniform_int_distribution<long long>  distr(range_from, range_to);

        IntModulo b;
        do {
            b.set_num(distr(generator));
        } while (legendreSymbol(b.get_num(), p) != -1);

        std::cout << "b: " << b.get_num() << std::endl;

        IntModulo s(0);
        unsigned long long t = p - 1;
        while (t % 2 == 0 && s.get_num() < 10) {
            t /= 2;
            s.add(IntModulo(1), LLONG_MAX);
        }

        std::cout << p-1 << " = " << " 2 ^ " << s.get_num() << " * " << t << std::endl;

        IntModulo rev = this->findReversed(p);

        IntModulo c;
        IntModulo temp(b);
        temp.pow(t, p);
        c.set_num(temp.get_num());

        IntModulo r(this->get_num());
        r.pow((t+1)/2, p);

        for (long long i = 1; i <= s.get_num()-1; i++)
        {
            IntModulo d(r);
            d.pow(2, ULLONG_MAX);
            d.multiply(rev, ULLONG_MAX);
            d.pow(std::pow(2, s.get_num()-i-1), p);

            if (p - d.get_num() == 1)
                r.multiply(c, p);

            c.pow(2, p);
        }

        IntModulo neg(-r.get_num());
        return std::make_pair(r, neg);
    }
    else
    {
        // АНДРЕЕЕЕЙ
        return std::nullopt;
    }
}
