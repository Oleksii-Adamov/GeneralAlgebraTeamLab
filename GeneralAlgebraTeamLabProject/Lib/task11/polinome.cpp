#include "polinome.h"

std::vector<IntModulo>* convert(const std::string& writtenPolinome);

Polinome::Polinome() {
    std::vector<IntModulo>* vec = new std::vector<IntModulo>();
    coefficients = vec;
}

Polinome::Polinome(int power) {
    coefficients = new std::vector<IntModulo>();
    for(int i = 0; i < power; ++i) {
        coefficients->emplace_back();
    }
}

Polinome::Polinome(std::vector<IntModulo>* coefficients) {
    this->coefficients = coefficients;
}

Polinome::Polinome(const std::string& writtenPolinome) {
    this->coefficients = convert(writtenPolinome);
}

Polinome::~Polinome() {
    delete coefficients;
}

Polinome Polinome::add(const Polinome& polinome, unsigned long long modulus) {
    Polinome result = Polinome();
    unsigned long long maxPower = std::max(this->coefficients->size(), polinome.coefficients->size());
    for(unsigned long long i = 0; i < maxPower; ++i) {
        IntModulo addend1 = (i < this->coefficients->size()) ? (*this->coefficients)[i] : IntModulo();
        IntModulo addend2 = (i < polinome.coefficients->size()) ? (*polinome.coefficients)[i] : IntModulo();
        addend1.add(addend2, modulus);
        result.coefficients->push_back(addend1);
    }
    return result;
}

Polinome Polinome::subtract(const Polinome &polinome, unsigned long long modulus) {
    Polinome result = Polinome();
    unsigned long long maxPower = std::max(this->coefficients->size(), polinome.coefficients->size());
    for(unsigned long long i = 0; i < maxPower; ++i) {
        IntModulo minuend = (i < this->coefficients->size()) ? (*this->coefficients)[i] : IntModulo();
        IntModulo subtrahend = (i < polinome.coefficients->size()) ? (*polinome.coefficients)[i] : IntModulo();
        minuend.subtract(subtrahend, modulus);
        result.coefficients->push_back(minuend);
    }
    return result;
}

Polinome Polinome::multiply(const Polinome& polinome, unsigned long long modulus) {
    Polinome result = Polinome(this->coefficients->size() + polinome.coefficients->size());
    for(unsigned long long i = 0; i < this->coefficients->size(); ++i) {
        for(unsigned long long j = 0; j < polinome.coefficients->size(); ++j) {
            IntModulo factor = IntModulo((*this->coefficients)[i]);
            factor.multiply((*polinome.coefficients)[j], modulus);
            (*result.coefficients)[i + j].add(factor, modulus);
        }
    }
    return result;
}

std::string Polinome::toString() {
    std::string result = "";
    for (int power = coefficients->size() - 1; power >= 0; power--) {
        if ((*this->coefficients)[power].get_num() != 0) {
            if (!result.empty()) result.append(" + ");
            if ((*this->coefficients)[power].get_num() > 1 || power == 0) {
                result.append((*this->coefficients)[power].ToString());
            }
            if (power > 0) result.append("x");
            if  (power > 1) result.append("^").append(std::to_string(power));
        }
    }
    if (result.empty()) result.append("0");

    return result;
}

Polinome Polinome::derivative(unsigned long long modulus) {
    Polinome result = Polinome(this->coefficients->size() - 1);
    for (unsigned long long power = 1; power < this->coefficients->size(); power++) {
        IntModulo factor = IntModulo(power);
        factor.multiply((*this->coefficients)[power], modulus);
        (*result.coefficients)[power - 1].add(factor, modulus);
    }
    return result;
}

IntModulo Polinome::evaluate(IntModulo x, unsigned long long modulus){
    if (this->coefficients->size() == 0)
        return IntModulo();

    IntModulo res((*this->coefficients)[this->coefficients->size()-1]);

    for (unsigned long long power = this->coefficients->size()-1; power > 0; power--) {
        res.multiply(x, modulus);
        res.add((*this->coefficients)[power-1], modulus);
    }

    return res;
}

bool Polinome::operator== (const Polinome& polinome) const {
    unsigned long long i = 0;
    for(; i < std::min(this->coefficients->size(), polinome.coefficients->size()); ++i) {
        if((*this->coefficients)[i].get_num() != (*polinome.coefficients)[i].get_num()) {
            return false;
        }
    }
    for(; i < this->coefficients->size(); ++i) {
        if((*this->coefficients)[i].get_num() != 0) {
            return false;
        }
    }
    for(; i < polinome.coefficients->size(); ++i) {
        if((*polinome.coefficients)[i].get_num() != 0) {
            return false;
        }
    }
    return true;
}

struct PolinomeItem {
    int coefficient = -1;
    int power = 0;
};

std::vector<PolinomeItem> getPolinomCoefs(const std::string& writtenPolinome) {
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
            std::string exception_message = "invalid argument: ";
            exception_message += writtenPolinome[i];
            throw std::invalid_argument(exception_message);
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
    int result = -1;
    for (std::size_t i = 0; i < coefficients.size(); ++i) {
        if (coefficients[i].power == power) {
            if (result == -1) {
                result = coefficients[i].coefficient;
            } else {
                throw std::invalid_argument("invalid argument: at least two parts have the same power of x.");
            }
        }
    }
    if (result == -1)
        return 0;
    else
        return result;
}

std::vector<IntModulo>* convert(const std::string& writtenPolinome) {
    std::vector<PolinomeItem> coefficients = getPolinomCoefs(writtenPolinome);
    std::vector<IntModulo>* answer = new std::vector<IntModulo>();
    int power = maxPower(coefficients);
    for (int i = 0; i < power + 1; ++i) {
        answer->push_back(IntModulo(coefOfPower(coefficients, i)));
    }
    return answer;
}

std::vector<long long> Eratosthene(long long M)
{
    //store prime numbers
    bool isPrime[M+1];

//initialize prime numbers
    for (long long i = 0; i <= M + 1; i++) {
        isPrime[i] = true;
    }

    for(long long k=2; k*k<=M;k++){
        if(isPrime[k]==true){
               //update all multiples if k non prime
            for(int i=k*k; i<=M;i++){
                isPrime[i]=false;
            }
        }
    }
    //prime numbers<M
    std::vector<long long> prime;
    for(int i=2; i<=M;i++){
        if(isPrime[i]){
            prime.pushback(i);
        }
    }
    return prime;
}

// Function to check whether the three
// conditions of Eisenstein's
// Irreducibility criterion for prime P
bool check(std::vector<IntModulo>* coefficients, long long P, long long N)
{
    if (coefficients[0].get_num() % P == 0)
        return 0;

    for (int i = 1; i < N; i++)
        if (coefficients[i].get_num() % P)
            return 0;

    if (coefficients[N - 1].get_num() % (P * P) == 0)
        return 0;

    return 1;
}
// Function to check for Eisensteins
// Irreducubility Criterion
bool checkIrreducibilty(std::vector<IntModulo>* coefficients, long long N)
{
    std::reverse(coefficients.begin(), coefficients.end());
    // Stores the largest element in A
    int M = -1;

    // Find the maximum element in A
    for (int i = 0; i < N; i++) {
        M = max(M, coefficients[i].get_num());
    }

    // Stores all the prime numbers
    vector<long long> primes
        = Eratosthene(M + 1);

    // Check if any prime
    // satisfies the conditions
    for (int i = 0;
        i < primes.size(); i++) {

        // Function Call to check
        // for the three conditions
        if (check(coefficients, primes[i], N)) {
            return 1;
        }
    }
    return 0;
}
