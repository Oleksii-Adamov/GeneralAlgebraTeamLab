#include "polinome.h"

std::vector<IntModulo> convert(std::string writtenPolinome);

Polinome::Polinome() {
    std::vector<IntModulo> vec;
    coefficients = vec;
}

Polinome::Polinome(int power) {
    coefficients = std::vector<IntModulo>();
    for(int i = 0; i < power; ++i) {
        coefficients.emplace_back(IntModulo());
    }
}

Polinome::Polinome(std::vector<IntModulo> coefficients) {
    this->coefficients = coefficients;
}

Polinome::Polinome(std::string writtenPolinome) {
    this->coefficients = convert(writtenPolinome);
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

bool Polinome::operator== (const Polinome& polinome) const {
    unsigned long long i = 0;
    for(; i < std::min(this->coefficients.size(), polinome.coefficients.size()); ++i) {
        if(this->coefficients[i].get_num() != polinome.coefficients[i].get_num()) {
            return false;
        }
    }
    for(; i < this->coefficients.size(); ++i) {
        if(this->coefficients[i].get_num() != 0) {
            return false;
        }
    }
    for(; i < polinome.coefficients.size(); ++i) {
        if(polinome.coefficients[i].get_num() != 0) {
            return false;
        }
    }
    return true;
}

struct PolinomeItem {
    int coefficient = -1;
    int power = 0;
};

std::vector<PolinomeItem> getPolinomCoefs(std::string writtenPolinome) {
    std::vector<PolinomeItem> coefficients;
    for (std::size_t i = 0; i < writtenPolinome.length(); ++i) {
        while (writtenPolinome[i] == ' ' || writtenPolinome[i] == '+') ++i;
        PolinomeItem item;
        while (writtenPolinome[i] >= '0' && writtenPolinome[i] <= '9') {
            if (item.coefficient == -1) item.coefficient = 0;
            item.coefficient = item.coefficient * 10 + writtenPolinome[i] - '0';
            ++i;
        }
        while (writtenPolinome[i] == ' ') ++i;
        if (writtenPolinome[i] != 'x') {
            if (writtenPolinome[i] == '+' || writtenPolinome[i] == '\0') {
                coefficients.push_back(item);
                continue;
            }
            //throw std::invalid_argument("invalid argument: " + writtenPolinome[i]);
            throw "Invalid argument";
        }
        ++i;
        while (writtenPolinome[i] == ' ') ++i;
        if (writtenPolinome[i] == '^') {
            ++i;
            while (writtenPolinome[i] == ' ') ++i;
            while (writtenPolinome[i] >= '0' && writtenPolinome[i] <= '9') {
                item.power = item.power * 10 + writtenPolinome[i] - '0';
                ++i;
            }
        } else {
            item.power = 1;
        }
        if (item.coefficient == -1) item.coefficient = 1;
        coefficients.push_back(item);
        while (writtenPolinome[i] == ' ') ++i;
    }
    return coefficients;
}

int maxPower(std::vector<PolinomeItem> coefficients) {
    int max = 0;
    for (std::size_t i = 0; i < coefficients.size(); ++i) {
        if (max < coefficients[i].power)
            max = coefficients[i].power;
    }
    return max;
}

int coefOfPower(std::vector<PolinomeItem> coefficients, int power) {
    for (std::size_t i = 0; i < coefficients.size(); ++i) {
        if (coefficients[i].power == power) return coefficients[i].coefficient;
    }
    return 0;
}

std::vector<IntModulo> convert(std::string writtenPolinome) {
    std::vector<PolinomeItem> coefficients = getPolinomCoefs(writtenPolinome);
    std::vector<IntModulo> answer;
    int power = maxPower(coefficients);
    for (int i = 0; i < power + 1; ++i) {
        answer.push_back(IntModulo(coefOfPower(coefficients, i)));
    }
    return answer;
}
