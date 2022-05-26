#include "polinome_gcd.h"
#include "polinome_copy.h"

Polinome* Polinome::gcd(const Polinome& p, unsigned long long modulo) const {
    auto g = this->copy(), h = p.copy();

    while (!h->degree().zero) {
        auto mDivRes = g->divide(*h, modulo);
        delete g;
        g = h;
        h = mDivRes.remainder;
        delete mDivRes.quotient;
    }

    return g;
}
