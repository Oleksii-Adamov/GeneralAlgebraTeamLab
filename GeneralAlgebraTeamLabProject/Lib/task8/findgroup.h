#ifndef FINDGROUP_H 
#define FINDGROUP_H

#include "Lib_global.h"
#include "task1/intmodulo.h"
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class LIB_EXPORT FindGroup
{
public:
    FindGroup(IntModulo order);
private:
    IntModulo groupOrder;
    int degree = 0;
    std::vector<IntModulo> group;
    std::map<IntModulo, IntModulo> factorizationMap;

    void SetGroup(int order);
    void FindPrimeFactorization();
public:
    bool FindGroupGenerator(int elem);
    int get_degree();
    long long get_groupOrder();
    IntModulo ElementOrder(IntModulo elem);
};

#endif // FINDGROUP_H
