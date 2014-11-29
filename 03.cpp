#include <stdio.h>

class Node {
    public:
    Node* next = NULL;
    long value;
};

Node* primes = new Node;

int is_prime(long n) {
    //search list of primes for this number
    Node* p = primes;
    while(p->next != NULL) {
        if(p->value == n){
            printf("%li is prime\n", n);
            return 1;
        }
        p = p->next;
    }
    long max = n * 0.5;
    for(long i = 2; i < max; i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    p = new Node();
    p->next = NULL;
    p->value = n;
    primes->next = p;   
    printf("%li is prime\n", n);
    return 1;
}

long largest_prime_factor(long n) {
    long largest_prime = 1;
    long fact1 = 1;
    long fact2 = n;
    while(fact1 < fact2) {
        bool new_factor = false;
        for(long i = fact1 + 1; i < fact2; i++) {
            if(n % i == 0) {
                //factor found
                long div = n/i;
                fact1 = i;
                fact2 = div;
                //printf("factors: %li   %li\n", fact1, fact2);
                new_factor = true;
                if(fact1 > largest_prime) {
                    //printf("checking larger prime for %li\n", fact1);
                    largest_prime = is_prime(fact1) ? fact1 : largest_prime;
                }
                if(fact2 > largest_prime) {
                    //printf("checking larger prime for %li\n", fact2);
                    largest_prime = is_prime(fact2) ? fact2 : largest_prime;
                }
                break;
            }
        }
        if(!new_factor) break;
    }
    return largest_prime;
}

int main() {
    long prime = largest_prime_factor(13195);
    printf("largest prime factor for %li = %li\n", 13195, prime);
    prime = largest_prime_factor(600851475143);
    printf("largest prime factor for %li = %li\n", 600851475143, prime);

    return 1;
}
