#ifndef FINDGROUP_H 
#define FINDGROUP_H

#include "Lib_global.h"
#include "task1/intmodulo.h"
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <set>

class LIB_EXPORT FindGroup
{
public:
    FindGroup(IntModulo order);
private:
    IntModulo groupOrder; //порядок елемента групи. Якщо 0, тоді група має нескінченний порядок
    int degree = 0; //степінь групи
    IntModulo groupGenerator;
    std::vector<IntModulo> group; //елементи групи
    // std::map<IntModulo, IntModulo> factorizationMap; //розклад степеню групи на прості множники

    void SetGroup(int order);
    // void FindPrimeFactorization();
public:
    bool FindGroupGenerator(IntModulo elem);
    int get_degree();
    long long get_groupOrder();
    IntModulo ElementOrder(IntModulo elem); //elem - any number
};

#endif // FINDGROUP_H