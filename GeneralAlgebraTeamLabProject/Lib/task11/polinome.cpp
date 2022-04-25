#include "polinome.h"

Polinome::Polinome() {}

Polinome::Polinome(int power) {
    for(int i = 0; i < power; ++i) {
        coefficients.emplace_back(IntModulo());
    }
}

Polinome::Polinome(std::vector<IntModulo> coefficients) {
    this->coefficients = coefficients;
}

Polinome Polinome::add(const Polinome& polinome, unsigned long long modulo) {
    Polinome result = Polinome();
    unsigned long long maxPower = std::max(this->coefficients.size(), polinome.coefficients.size());
    for(unsigned long long i = 0; i < maxPower; ++i) {
        IntModulo addend1 = (i < this->coefficients.size()) ? this->coefficients[i] : IntModulo();
        IntModulo addend2 = (i < polinome.coefficients.size()) ? polinome.coefficients[i] : IntModulo();
        addend1.add(addend2, modulo);
        result.coefficients.emplace_back(addend1);
    }
    return result;
}

Polinome Polinome::subtract(const Polinome &polinome, unsigned long long modulo) {
    Polinome result = Polinome();
    unsigned long long maxPower = std::max(this->coefficients.size(), polinome.coefficients.size());
    for(unsigned long long i = 0; i < maxPower; ++i) {
        IntModulo minuend = (i < this->coefficients.size()) ? this->coefficients[i] : IntModulo();
        IntModulo subtrahend = (i < polinome.coefficients.size()) ? polinome.coefficients[i] : IntModulo();
        minuend.substract(subtrahend, modulo);
        result.coefficients.emplace_back(minuend);
    }
    return result;
}

Polinome Polinome::multiply(const Polinome& polinome, unsigned long long modulo) {
    Polinome result = Polinome(this->coefficients.size() + polinome.coefficients.size());
    for(unsigned long long i = 0; i < this->coefficients.size(); ++i) {
        for(unsigned long long j = 0; j < polinome.coefficients.size(); ++j) {
            IntModulo factor = IntModulo(this->coefficients[i]);
            factor.multiply(polinome.coefficients[j], modulo);
            result.coefficients[i + j].add(factor, modulo);
        }
    }
    return result;
}
