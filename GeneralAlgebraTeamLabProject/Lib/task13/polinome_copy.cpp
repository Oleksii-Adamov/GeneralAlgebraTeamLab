#include "polinome_copy.h"

Polinome* Polinome::copy() const {
    Polinome* r = new Polinome(this->coefficients->size());

    for (size_t i = 0; i < (*r).coefficients->size(); i += 1) {
        (*(*r).coefficients)[i] = (*this->coefficients)[i];
    }

    return r;
}
