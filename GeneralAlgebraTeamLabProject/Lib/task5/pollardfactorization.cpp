#include "pollardfactorization.h"
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <stdexcept>

// finds greatest common divider
static long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd (b, a % b);
}

static bool isPrime(long long a) {
    for (long long i = 2; i <= sqrt(a); ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

static long long F(long long x, long long a, long long mod) {
    return (x * x + (1 + 2 * a)) % mod;
}

static std::vector<long long> rhoPollard(long long N) {
    if (N < 1) {
        throw std::invalid_argument(N + " is less than 1");
    }
    if (N == 1) {
        return std::vector<long long>{1};
    }
    if (N % 2 == 0) {
        std::vector<long long> t = rhoPollard(N / 2);
        t.push_back(2);
        return t;
    }
    std::vector<long long> ans;
    long long x = 2;
    long long y = 2;
    long long gcd1;
    long long a = rand() % 10;
    do {
        x = F(x, a, N);
        y = F(F(y, a, N), a, N);
        gcd1 = gcd(N, abs(x - y));
    } while (gcd1 == 1);

    if (isPrime(gcd1)) {
        ans.push_back(gcd1);
    } else {
        std::vector<long long>  t = rhoPollard(gcd1);
        ans.insert(ans.end(), t.begin(), t.end());
    }

    long long zvor = N / gcd1;
    if (isPrime(zvor)) {
        ans.push_back(zvor);
    } else {
        std::vector<long long>  t = rhoPollard(zvor);
        ans.insert(ans.end(), t.begin(), t.end());
    }

    return ans;
}

std::map<long long, int> PollardFactorization::factorize(long long number) {
    std::vector<long long> primeNumbers = rhoPollard(number);
    sort(primeNumbers.begin(), primeNumbers.end());
    std::map<long long, int> primeNumbersMap;
    for (long long i : primeNumbers) {
        if (i != 1) {
            // if the element is not found
            if (primeNumbersMap.find(i) == primeNumbersMap.end()) {
                primeNumbersMap.insert(std::pair(i, 1));
            } else {
                primeNumbersMap[i]++;
            }
        }
    }
    return primeNumbersMap;
}
