#include <stdio.h>
#include <string.h>

int is_prime(long n) {
    long max = n;
    for(long i = 2; i < max; i++) { 
        if(n % i == 0) return 0;
    }
    return true;
}

void find_prime(int nth) {
    long last_prime = 1;
    long count = 2;
    int primes = 0;
    while(primes < nth) {
        //check all numbers
        if(is_prime(count)){
            primes++;
            printf("%ith prime = %li\n", primes, count);
        }
        count++;
    }
}

int main() {
    find_prime(10001);
    return 1;
}
