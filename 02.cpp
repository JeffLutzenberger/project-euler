#include <stdio.h>

void sum_of_even_fib(int n) {
    int fib1 = 1;
    int fib2 = 2;
    int fib_next = 3;
    int sum = 2;
    while(fib_next = fib1 + fib2 < n) {
        fib_next = fib1 + fib2;
        if(fib_next % 2 == 0) sum += fib_next;
        fib1 = fib2;
        fib2 = fib_next;
    }
    printf("sum of even fib terms: %i\n", sum);
}

int main() {
    sum_of_even_fib(4e6);
    return 1;
}
