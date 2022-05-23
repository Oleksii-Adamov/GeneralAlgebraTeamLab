#include "pollardfactorization.h"
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <stdexcept>

// finds greatest common divider
static int gcd(int a, int b) {
    return b == 0 ? a : gcd (b, a % b);
}

static bool isPrime(int a) {
    for (int i = 2; i <= sqrt(a); ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

static int F(int x, int a, int mod) {
    return (x * x + (1 + 2 * a)) % mod;
}

static std::vector<int> rhoPollard(int N) {
    if (N < 1) {
        throw std::invalid_argument(N + " is less than 1");
    }
    if (N == 1) {
        return std::vector<int>{1};
    }
    if (N % 2 == 0) {
        std::vector<int> t = rhoPollard(N / 2);
        t.push_back(2);
        return t;
    }
    std::vector<int> ans;
    int x = 2;
    int y = 2;
    int gcd1;
    int a = rand() % 10;
    do {
        x = F(x, a, N);
        y = F(F(y, a, N), a, N);
        gcd1 = gcd(N, abs(x - y));
    } while (gcd1 == 1);

    if (isPrime(gcd1)) {
        ans.push_back(gcd1);
    } else {
        std::vector<int>  t = rhoPollard(gcd1);
        ans.insert(ans.end(), t.begin(), t.end());
    }

    int zvor = N / gcd1;
    if (isPrime(zvor)) {
        ans.push_back(zvor);
    } else {
        std::vector<int>  t = rhoPollard(zvor);
        ans.insert(ans.end(), t.begin(), t.end());
    }

    return ans;
}

std::vector<int> PollardFactorization::factorize(int number) {
    std::vector<int> primeNumbers = rhoPollard(number);
    sort(primeNumbers.begin(), primeNumbers.end());
    return primeNumbers;
}
