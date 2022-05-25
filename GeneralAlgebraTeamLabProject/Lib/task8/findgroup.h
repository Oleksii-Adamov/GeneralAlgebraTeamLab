#ifndef FINDGROUP_H
#define FINDGROUP_H

#include "Lib_global.h"
#include "task1/intmodulo.h"
#include <vector>
#include <string>
#include <map>

class LIB_EXPORT FindGroup
{
public:
    FindGroup(const std::string& multiplicativeGroup);
private:
    IntModulo groupOrder;
    int degree = 0;
    std::vector<std::vector<IntModulo>> group;
    std::map<IntModulo, IntModulo> factorizationMap;
public:
    void SetGroup(const std::string& multiplicativeGroup);
    void FindPrimeFactorization();
    int get_degree();
    IntModulo get_groupOrder();
};

#endif // FINDGROUP_H
