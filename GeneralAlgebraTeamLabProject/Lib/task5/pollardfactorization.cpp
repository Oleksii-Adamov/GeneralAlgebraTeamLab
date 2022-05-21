#include "pollardfactorization.h"
#include <stdlib.h>

// finds greatest common divider
static int gcd(int a, int b) {
    return b == 0 ? a : gcd (b, a % b);
}

static int rhoPollard (int N) {
    int x = rand() % (N-3) + 1;
    int y = 1, i = 0, stage = 2;
    while (gcd(N, abs(x - y)) == 1)
    {
        if (i == stage){
            y = x;
            stage = stage*2;
        }
        x = (x * x + 1) % N;
        i = i + 1;
    }
    return gcd(N, abs(x-y));
}

std::vector<int> PollardFactorization::factorize(int number) {
    std::vector<int> primeNumbers;
    while (number != 1) {
        int n = rhoPollard(number);
        primeNumbers.push_back(n);
        number /= n;
    }
    return primeNumbers;
}
