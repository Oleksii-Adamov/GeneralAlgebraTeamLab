#ifndef POLLARDFACTORIZATION_H
#define POLLARDFACTORIZATION_H

#include "Lib_global.h"
#include <vector>

class LIB_EXPORT PollardFactorization
{
public:
    /**
     * @brief factorize use the Rho-Pollard's algo.
     * @param number a number to take prime numbers of.
     * @return a vector of prime numbers
     */
    static std::vector<long long> factorize(long long number);
};

#endif // POLLARDFACTORIZATION_H
