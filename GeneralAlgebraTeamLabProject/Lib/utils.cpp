#include "utils.h"

bool isPrime(unsigned long long n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int mobius(unsigned long long  N) {
    if (N == 1)
        return 1;
    int p = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0 && isPrime(i)) {
            if (N % (i * i) == 0)
                return 0;
            else
                p++;
        }
    }
    return (p % 2 != 0) ? -1 : 1;
}