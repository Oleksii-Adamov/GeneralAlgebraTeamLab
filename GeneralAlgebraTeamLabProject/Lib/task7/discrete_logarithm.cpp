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

std::vector<int> discreteLogarithm(double a, double b, int p)
{
    std::vector<int> result;
    int h = floor(sqrt(p)) + 1;
    int c = IntModulo(std::pow(a, h), p).get_num();

    std::multimap<int, int> cu;
    std::multimap<int, int> bav;

    for (long long u = 1; u <= h; u++)
        cu.insert(decltype(cu)::value_type(IntModulo(std::pow(c, u), p).get_num(), u));

    for (long long v = 0; v <= h; v++)
        bav.insert(decltype(bav)::value_type(IntModulo(b * std::pow(a, v), p).get_num(), v));

    for(auto el_cu = cu.begin(); el_cu != cu.end(); el_cu++) {
        for(auto el_bav = bav.begin(); el_bav != bav.end(); el_bav++) {
            if (el_cu->first == el_bav->first && IntModulo(std::pow(a, h * el_cu->second - el_bav->second), p).get_num() == b)
                result.push_back(h * el_cu->second - el_bav->second);
        }
    }


    return result.size() ? result : std::vector<int> {-1};
}

std::vector<long long> discreteLogarithm2(int base, int result, int module) {
    int n = (int)sqrt(module) + 1;

    int baseInNPower = 1;
    for (int i = 0; i < n; i++) {
        baseInNPower = (baseInNPower * base) % module;
    }

    std::map<int, std::vector<long long>>  table;

    table[1] = {0};

    for (int i = 1, current = baseInNPower; i <= n; i++) {
        if (table[current].size() == 0) {
            table[current] = {i};
        }
        else {
            table[current].push_back(i);
        }

        current = (current * baseInNPower) % module;
    }

    std::vector<long long> answers;

   for (int j = 0, current = result; j <= n; j++) {
        if (table[current].size() > 0) {
            for (auto tempAnswer : table[current]) {
                int answer = tempAnswer * n - j;
                if(answer < module) {
                    answers.push_back(answer);
                }
            }
        }
        current = (current * base) % module;
    }

   if (answers.size() == 0) return { -1 };
   std::sort(answers.begin(), answers.end());
   answers.erase(std::unique(answers.begin(), answers.end()), answers.end());
   return answers;
}
