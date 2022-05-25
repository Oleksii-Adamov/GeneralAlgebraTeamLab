#ifndef POLINOME_DIVISION_HPP
#define POLINOME_DIVISION_HPP

#include <vector>
#include "../task1/intmodulo.h"
#include "../task11/polinome.h"
#include "division_result.hpp"
#include "polinome_degree.hpp"

DivisionResult<Polinome> Polinome::divide(const Polinome& divider, unsigned long long modulus) const {
    Polinome rem(this->coefficients->size());
    Polinome div(divider.coefficients->size());

    auto remCfs = *rem.coefficients;
    auto divCfs = *div.coefficients;

    for (size_t i = 0; i < remCfs.size(); i += 1) {
        IntModulo el((*this->coefficients)[i]);
        el.mod(modulus);
        remCfs[i] = el;
    }

    for (size_t i = 0; i < divCfs.size(); i += 1) {
        IntModulo el((*div.coefficients)[i]);
        el.mod(modulus);
        divCfs[i] = el;
    }

    auto dividerDegreeResult = divider.degree();
    if (dividerDegreeResult.zero) {
       throw "Division by zero";
    };
    auto divDeg = dividerDegreeResult.value;

    Polinome quotient("0");

    auto degDiff = (long long)this->degree().value - (long long)divDeg;

    while(degDiff >= 0) {
        unsigned long long remDeg = degDiff + divDeg;
        if (remCfs[remDeg] == 0) {
            continue;
        }

        auto mul = IntModulo(remCfs[remDeg]);
        mul.divide(divCfs[divDeg], modulus);

        auto substractat = std::vector<IntModulo>();
        substractat.reserve(remDeg + 1);

        for (auto j = 0; j < degDiff; j += 1) {
            substractat.emplace_back(IntModulo(0));
        }

        for (unsigned long long j = 0; j <= divDeg; j += 1) {
            auto subCf = IntModulo(divCfs[j]);
            subCf.multiply(IntModulo(mul), modulus);
            substractat.emplace_back(subCf);
        }

        rem.subtract(Polinome(&substractat), modulus);

        degDiff -= 1;
    }

    return {quotient, rem};
}

#endif // POLINOME_DIVISION_HPP
