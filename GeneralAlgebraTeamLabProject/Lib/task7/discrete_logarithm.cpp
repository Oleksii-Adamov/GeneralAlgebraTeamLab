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
int discreteLogarithm(double a, double b, int p)
{
    int h = floor(sqrt(p)) + 1;
    int c = IntModulo(std::pow(a, h), p).get_num();

    std::multimap<int, int> cu;
    std::multimap<int, int> bav;

    for(int u = 1; u <= h; u++)
        cu.insert(decltype(cu)::value_type(IntModulo(std::pow(c, u), p).get_num(), u));

    for(int v = 0; v<= h; v++)
        bav.insert(decltype(bav)::value_type(IntModulo(b * std::pow(a, v), p).get_num(), v));

    for(auto el_cu = cu.begin(); el_cu != cu.end(); el_cu++) {
        for(auto el_bav = bav.begin(); el_bav != bav.end(); el_bav++) {
            if (el_cu->first == el_bav->first && IntModulo(std::pow(a, h * el_cu->second - el_bav->second), p).get_num() == b)
                return h * el_cu->second - el_bav->second;
        }
    }


    return -1;
}
