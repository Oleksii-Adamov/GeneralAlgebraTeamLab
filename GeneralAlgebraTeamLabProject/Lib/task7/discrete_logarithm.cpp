#include <iostream>
#include <cmath>
#include <map>
#include <string_view>
//#include "../utils.h"
#include "task1/intmodulo.h"
#include "discrete_logarithm.h"

/*template<class M>
void print(const std::string_view rem, const M& mmap)
{
    std::cout << rem << " ";
    for (const auto & e : mmap)
        std::cout << "{" << e.first << "," << e.second << "} ";
    std::cout << '\n';
}
*/
long long discreteLogarithm(long long a, long long b, long long p)
{
    long long h = floor(sqrt(p)) + 1;
    long long c = IntModulo(std::pow(a, h), p).get_num();

    std::multimap<int, int> cu;
    std::multimap<int, int> bav;

    for (long long u = 1; u <= h; u++)
        cu.insert(decltype(cu)::value_type(IntModulo(std::pow(c, u), p).get_num(), u));

    for (long long v = 0; v <= h; v++)
        bav.insert(decltype(bav)::value_type(IntModulo(b * std::pow(a, v), p).get_num(), v));

    for(auto el_cu = cu.begin(); el_cu != cu.end(); el_cu++) {
        for(auto el_bav = bav.begin(); el_bav != bav.end(); el_bav++) {
            if (el_cu->first == el_bav->first && IntModulo(std::pow(a, h * el_cu->second - el_bav->second), p).get_num() == b)
                return h * el_cu->second - el_bav->second;
        }
    }


    return -1;
}

long long discreteLogarithm2(long long base, long long result, long long module)
{
    long long n = (long long)sqrt(module) + 1;

    long long baseInNPower = 1;
    for (long long i = 0; i < n; i++)
    {
        baseInNPower = (baseInNPower * base) % module;
    }

    std::map<long long, long long> table;

    for (long long i = 1, current = baseInNPower; i <= n; i++) {
        if (!table[current]) {
            table[current] = i;
        }

        current = (current * baseInNPower) % module;
    }

    for (long long j = 0, current = result; j <= n; j++)
    {
        if (table[current]) {
            long long answer = table[current] * n - j;
            if (answer < module) {
                return answer;
            }

        }
        current = (current * base) % module;
    }

    return -1;
}
