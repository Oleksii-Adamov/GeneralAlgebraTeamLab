#ifndef POLLARDFACTORIZATION_H
#define POLLARDFACTORIZATION_H

#include <vector>

class PollardFactorization
{
public:
    /**
     * @brief factorize use the Rho-Pollard's algo.
     * @param number a number to take prime numbers of.
     * @return a vector of prime numbers
     */
    static std::vector<int> factorize(int number);
};

#endif // POLLARDFACTORIZATION_H
