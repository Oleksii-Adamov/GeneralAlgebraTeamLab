#include "polinome_degree.h"

DegreeResult Polinome::degree() const {
    auto coeffs = this->coefficients;
    for (unsigned long long i = coeffs->size() - 1; i != ULLONG_MAX; i -= 1) {
        if ((*coeffs)[i].get_num() != 0) {
            return {false, i};
        }
    }
    return {true, 0};
}
