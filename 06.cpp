#include <stdio.h>
#include <string.h>

void difference(long n) {
    long sum_of_squares = 0;
    long square_of_sum = 0;
    for(long i = 1; i <= n; i++) {
        sum_of_squares += i*i;
        square_of_sum += i;
    }
    square_of_sum = square_of_sum * square_of_sum;

    printf("difference = %li\n", square_of_sum - sum_of_squares);
}

int main() {
    difference(100);
    return 1;
}
