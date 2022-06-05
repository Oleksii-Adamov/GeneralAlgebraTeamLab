#include <iostream>
#include <cmath>
#include <map>
#include <string_view>
//#include "../utils.h"
#include "task1/intmodulo.h"
#include "discrete_logarithm.h"
#include <vector>
#include <algorithm>
#include <unordered_set>

/*template<class M>
void print(const std::string_view rem, const M& mmap)
{
    std::cout << rem << " ";
    for (const auto & e : mmap)
        std::cout << "{" << e.first << "," << e.second << "} ";
    std::cout << '\n';
}
*/

std::vector<long long> discreteLogarithm(long long a, long long b, unsigned long long p)
{
    std::vector<long long> result;
    long long h = floor(sqrt(p)) + 1;
    IntModulo C(a);
    C.pow(h,p);
    long long c = C.get_num();

    std::multimap<long long, long long> cu;
    std::multimap<long long, long long> bav;

    for (long long u = 1; u <= h; u++) {
        IntModulo cu_key(c);
        cu_key.pow(u,p);
        cu.insert(decltype(cu)::value_type(cu_key.get_num(), u));
    }

    for (long long v = 0; v <= h; v++) {
        IntModulo bav_key(a);
        bav_key.pow(v,p);
        IntModulo B(b);
        bav_key.multiply(B, p);
        bav.insert(decltype(bav)::value_type(bav_key.get_num(), v));
    }
    for(auto el_cu = cu.begin(); el_cu != cu.end(); el_cu++) {
        for(auto el_bav = bav.begin(); el_bav != bav.end(); el_bav++) {
            IntModulo a_buf(a);
            a_buf.pow(h * el_cu->second - el_bav->second, p);
            if (el_cu->first == el_bav->first
                && a_buf.get_num() == b
                && (h * el_cu->second - el_bav->second < p))
                    result.push_back(h * el_cu->second - el_bav->second);
        }
    }

    std::sort(result.begin(), result.end());
    auto last = std::unique(result.begin(),result.end());
    result.erase(last, result.end());

    return result.size() ? result : std::vector<long long> {-1};
}

// Algorithm
// We have base, result and module
// base ^ n = result mod module
// We need to find n

// Solution: 
// let m = sqrt(module) + 1
// we can write n as n = i*m - j, where 0 <= i <= m and  0 <= j <= m
// then base^(i*m) mod module = result * base^j mod module
// create map and calc base^(i*m) mod module and write in pairs like: {base^(i*m) mod module : i}
// calculate result * base^j mod module and if this value exists in table return i*m - j

std::vector<unsigned long long> discreteLogarithm2(long base, long result, long module)
{
    long n = (long)sqrt(module) + 1;

    unsigned long long baseInNPower = 1;
    for (long i = 0; i < n; i++)
    {
        baseInNPower = (baseInNPower * base) % module;
    }

    std::map<unsigned long long, std::vector<long>> table;

    table[1] = {0};
    unsigned long long current = baseInNPower;
    for (long i = 1; i <= n; i++)
    {
        if (table[current].size() == 0) {
            table[current] = {i};
        }
        else {
            table[current].push_back(i);
        }

        current = (current * baseInNPower) % module;
    }

    std::vector<unsigned long long> answers;

    unsigned long long current2 = result;
    for (long j = 0; j <= n; j++)
    {
        // check if result * base ^j is in the table
        if (table[current2].size() > 0) {
            for (auto tempAnswer : table[current2]) {
                unsigned long long answer = tempAnswer * n - j;
                if(answer < module) {
                    answers.push_back(answer);
                }
            }
        }
        current2 = (current2 * base) % module;
    }

   std::sort(answers.begin(), answers.end());
   answers.erase(std::unique(answers.begin(), answers.end()), answers.end());
   return answers;
}
