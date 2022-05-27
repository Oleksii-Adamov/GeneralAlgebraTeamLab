#include "intmodulo.h"
#include <random>
#include "task5/pollardfactorization.h"
#include <numeric>
#include <stdexcept>
#include <string>
#include <algorithm>

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

// optimal to use > 5 iterations
bool IntModulo::isPrime(int iterationsNum)
{
    if(iterationsNum < 1) throw std::invalid_argument("iterationsNum can`t be negative.");

    unsigned long long n = this->get_num();

    // Corner cases
    if (n <= 1 || n == 4)
        return false;

    if (n <= 3)
        return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    unsigned long long d = this->get_num() - 1;

    while (d % 2 == 0) {
        d /= 2;
    }

    for (int i = 0; i < iterationsNum; i++) {
        if (!this->miillerTest(d, n)) {
            return false;
        }
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

std::optional<std::pair<IntModulo, IntModulo>> IntModulo::sqrt_prime(unsigned long long modulus) const {
    IntModulo a(*this);

    if (a.get_num() > modulus-1)
        throw std::invalid_argument("modulus-1 must be greater or equal to the number");
    if (modulus % 1 != 0)
        throw std::invalid_argument("modulus should be integer");

    if (legendreSymbol(a.get_num(), modulus) == -1)
        return std::nullopt;

    // case p == 3 (mod 4) (Algorithm 3.36)
    if (modulus % 4 == 3) {
        IntModulo r(*this);
        r.pow((modulus+1)/4, modulus);
        IntModulo neg(r.get_num());
        neg.multiply(IntModulo(-1), modulus);
        return std::make_pair(r, neg);
    }

    // case p == 5 (mod 8) (Algorithm 3.37)
    if (modulus % 8 == 5) {
        IntModulo d(*this);
        d.pow((modulus-1)/4, modulus);
        IntModulo r(*this);
        if (d.get_num() == 1){
            r.pow((modulus+3)/8, modulus);
            IntModulo neg(r.get_num());
            neg.multiply(IntModulo(-1), modulus);
            return std::make_pair(r, neg);
        } else if (d.get_num() == modulus-1) {
            IntModulo r2(*this);
            r.multiply(IntModulo(2ll), modulus);
            r2.multiply(IntModulo(4ll), modulus);
            r2.pow((modulus-5)/8, modulus);
            r.multiply(r2, modulus);
            IntModulo neg(r.get_num());
            neg.multiply(IntModulo(-1), modulus);
            return std::make_pair(r, neg);
        }
    }


    // (Algorithm 3.34)

    // random numbers
    const int range_from  = 1;
    const int range_to    = modulus-1;

    std::random_device                        rand_dev;
    std::mt19937                              generator(rand_dev());
    std::uniform_int_distribution<long long>  distr(range_from, range_to);

    IntModulo b;
    do {
        b.set_num(distr(generator));
    } while (legendreSymbol(b.get_num(), modulus) != -1);

    IntModulo s(0);
    unsigned long long t = modulus - 1;
    while (t % 2 == 0 && s.get_num() < 10) {
        t /= 2;
        s.add(IntModulo(1), LLONG_MAX);
    }

    IntModulo rev = a.findReversed(modulus);

    IntModulo c;
    IntModulo temp(b);
    temp.pow(t, modulus);
    c.set_num(temp.get_num());

    IntModulo r(a.get_num());
    r.pow((t+1)/2, modulus);

    for (long long i = 1; i <= s.get_num()-1; i++)
    {
        IntModulo d(r);
        d.pow(2, modulus);
        d.multiply(rev, modulus);
        d.pow(std::pow(2, s.get_num()-i-1), modulus);

        if (modulus - d.get_num() == 1)
            r.multiply(c, modulus);

        c.pow(2, modulus);
    }

    IntModulo neg(r.get_num());
    neg.multiply(IntModulo(-1), modulus);
    return std::make_pair(r, neg);
}

void extended_gcd_step(int r1, int r2, int x1, int x2, int y1, int y2, int &gcd, int &a, int &b) {
    int r3 = r1 - r2 * (r1 / r2);
    int x3 = x1 - x2 * (r1 / r2);
    int y3 = y1 - y2 * (r1 / r2);
    if (r3)
        extended_gcd_step(r2, r3, x2, x3, y2, y3, gcd, a, b);
    else {
        gcd = r2;
        a = x2;
        b = y2;
    }
}

void extended_gcd(int r1, int r2, int &gcd, int &a, int &b) {
    extended_gcd_step(r1 > r2 ? r1 : r2, r1 < r2 ? r1 : r2, 1, 0, 0, 1, gcd, r1 > r2 ? a : b, r1 < r2 ? a : b);
}

std::optional<std::pair<IntModulo, IntModulo>> IntModulo::sqrt(unsigned long long modulus) const
{
    auto factors = PollardFactorization::factorize(modulus);

    if (factors.size() == 0) {
        return std::nullopt;
    }

    if (factors.size() == 1 /*&& factors.begin()->second == 1*/) {
        // Case I: prime modulus
        return this->sqrt_prime(factors.begin()->first);
    } else {
        // Case II: composite modulus
        auto n = this->get_num();

        // take any 2 factors, that are not divisors of n
        long long p = 0, q = 0;
        for (auto it = factors.begin(); it != factors.end(); it++) {
            if (n % it->first != 0) {
                if (p == 0) {
                    p = it->first;
                } else if (q == 0) {
                    q = it->first;
                    break;
                }
            }
        }

        if (p == 0 || q == 0) {
            throw "Strange";
        }

        //find roots
        auto p_roots = IntModulo(n, p).sqrt_prime(p);
        auto q_roots = IntModulo(n, q).sqrt_prime(q);
        auto r = p_roots->first.get_num();
        auto s = q_roots->first.get_num();

        // find multipliers
        int gcd, c, d;
        extended_gcd(r, s, gcd, c, d);

        //compute true roots
        int x = (r*d*q + s*c*p) % modulus;
        //int y = (r*d*q - s*c*p) % modulus;
        return std::make_pair(x, -x);
    }
}

// Private methods
bool IntModulo::miillerTest(long long d, long long n)
{
    // Pick a random number in [2..n-2]
    unsigned long long a = 2 + rand() % (n - 4);

    // Compute x^d % n
    IntModulo x = IntModulo(a);
    x.pow(d, n);

    if (x.get_num() == 1 || x.get_num() == n - 1)
        return true;

    // Keep squaring x while one of the following doesn't happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n - 1) {
        x.multiply(x, n);

        d *= 2;

        if (x.get_num() == 1)
            return false;
        if (x.get_num() == n - 1)
            return true;
    }

    return false;
}

long long IntModulo::phi()
{
    if(num < 1) throw std::invalid_argument("Num can`t be less than 1.");
    long long result = num, tmp = num;

    // Consider all prime factors of n and subtract
    // their multiples from result
    for(int i = 2; i * i <= tmp; ++i) {
        // Check if p is a prime factor.
        if (tmp % i == 0) {
            // If yes, then update n and result
            while (tmp % i == 0) tmp /= i;
            result -= result / i;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (tmp > 1) result -= result / tmp;

    return result;
}

long long IntModulo::carmichael()
{
    long long result = 1;
    for (auto [p, e] : PollardFactorization::factorize(this->num)) {
        long long lambda = std::pow(p, e - 1) * (p - 1);
        if (p == 2 && e >= 3) lambda /= 2;
        result = result / std::gcd(result, lambda) * lambda;
    }
    return result;
}
