#ifndef SQUAREROOT_H
#define SQUAREROOT_H

#include "Lib_global.h"

class LIB_EXPORT SquareRoot
{
public:
    SquareRoot();
    std::pair<long long, long long> sqrt(long long a, long long p);
};

#endif // SQUAREROOT_H
