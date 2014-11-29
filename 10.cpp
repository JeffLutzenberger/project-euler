#include <stdio.h>
#include <string.h>

int is_prime_fast(long n) {
    if (n == 2 || n == 3) {
        return 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    } else {
        for (long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return 0;
            }
        }
        return 1;
    }
}

int is_prime(long n) {
    long max = n * 0.5 + 1;
    for(long i = 2; i < max; i++) { 
        if(n % i == 0) return 0;
    }
    return 1;
}

void sum_primes(long n) {
    long sum = 0;
    for(long i = 2; i < n; i++) {
        if(is_prime_fast(i)) {
            //printf("%li\n", i);
            sum += i;
        }
    }
    printf("sum of primes below %li: %li\n", n, sum);
}

int main() {
    sum_primes(10);
    sum_primes(2e6);
    return 1;
}
