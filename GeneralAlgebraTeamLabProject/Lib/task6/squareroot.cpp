#include "squareroot.h"

SquareRoot::SquareRoot()
{

}



// finding a square root of a, modulo p
std::pair<long long, long long> SquareRoot::sqrt(long long a, long long p)
{
    if (isPrime(p))
        return sqrtPrimeP(a, p);
    else
        return sqrtNonPrimeP(a, p);
}


bool SquareRoot::isPrime(long long n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}



// for prime p
std::pair<long long, long long> SquareRoot::sqrtPrimeP(long long a, long long p)
{
    return std::make_pair(7ll, -7ll);
}

// for non prime p
std::pair<long long, long long> SquareRoot::sqrtNonPrimeP(long long a, long long p)
{
    return std::make_pair(7ll, -7ll);
}


