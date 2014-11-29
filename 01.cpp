#include <stdio.h>

int sum_of_multiples_of_3_and_5(int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(i % 3 == 0 || i % 5 == 0) sum += i;
    }
    return sum;
}

int main() {
    printf("n = %i  sum = %i\n", 10, sum_of_multiples_of_3_and_5(10));
    printf("n = %i  sum = %i\n", 1000, sum_of_multiples_of_3_and_5(1000));
    return 1;
}
