#include "utils.h"

bool isPrime(long long  n) {
    long long divide_counter = 0;
    for (long long i = 0; i <= n; i++) 
        if (n % i == 0) divide_counter++;
    
    return divide_counter == 2;
}

bool isSquareFree(long long n) {
    if (n < 2) return false;

    for (long long i = 2; i * i <= n; i++)
        if (isPrime(n) && n % i == 0) return false;

    return true;
}

long long mobius(long long N) {
    if (N == 1) return 1;

    long long p = 0;
    for (long long i = 1; i <= N; i++) {
        if (N % i == 0 && isSquareFree(i)) {
            if (N % (i * i) == 0) 
                return 0;
            else 
                p++;
        }
    }
    return (p % 2 != 0) ? -1 : 1;
}