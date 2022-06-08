#include "polinome_division.h"
#include <QDebug>

DivisionResult<Polinome> Polinome::divide(const Polinome& divider, unsigned long long modulus) const {
    Polinome* rem = new Polinome(this->coefficients->size());
    Polinome div(divider.coefficients->size());

    for (size_t i = 0; i < (*rem).coefficients->size(); i += 1) {
        IntModulo el((*this->coefficients)[i]);
        el.mod(modulus);
        (*(*rem).coefficients)[i] = el;
    }

    for (size_t i = 0; i < div.coefficients->size(); i += 1) {
        IntModulo el((*divider.coefficients)[i]);
        el.mod(modulus);
        (*div.coefficients)[i] = el;
    }

    auto dividerDegreeResult = divider.degree();
    if (dividerDegreeResult.zero) {
       throw std::logic_error("Division by zero");
    };
    auto divDeg = dividerDegreeResult.value;

    auto degDiff = (long long)this->degree().value - (long long)divDeg;

    Polinome *quotient = new Polinome(degDiff + 1);

    while(degDiff >= 0) {
        unsigned long long remDeg = degDiff + divDeg;
        if ((*(*rem).coefficients)[remDeg] == 0) {
            degDiff -= 1;
            continue;
        }

        auto mul = IntModulo((*(*rem).coefficients)[remDeg]);
        mul.divide((*div.coefficients)[divDeg], modulus);
        (*(*quotient).coefficients)[degDiff] = mul;

        Polinome substractat(remDeg + 1);

        for (auto j = 0; j < degDiff; j += 1) {
            (*substractat.coefficients)[j] = IntModulo(0);
        }

        for (unsigned long long j = 0; j <= divDeg; j += 1) {
            auto subCf = IntModulo((*div.coefficients)[j]);
            subCf.multiply(IntModulo(mul), modulus);
            (*substractat.coefficients)[j + degDiff] = subCf;
        }

        auto substracted = (*rem).subtract(substractat, modulus);
        for (size_t i = 0; i < substracted.coefficients->size(); i += 1) {
            (*(*rem).coefficients)[i] = (*substracted.coefficients)[i];
        }

        degDiff -= 1;
    }

    DivisionResult<Polinome> result{quotient, rem};
    return result;
}
