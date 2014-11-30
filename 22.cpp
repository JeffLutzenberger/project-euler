#include <stdio.h>

int sum_of_factors(int n) {
    int num = n * 0.5;
    if(n == 1) return 1;
    int sum = 0; 
    for(int i = 1; i <= num; i++){
        if(n % i == 0){
            //printf("%i ", i);
            sum += i;
        }
    }
    return sum;
}

int main() {
    int a[10000] = {0};
    for(int i = 1; i < 10000; i++)
        a[i] = sum_of_factors(i);

    printf("%i\n", sum_of_factors(220));
    printf("%i\n", sum_of_factors(284));

    int sum = 0;
    for(int i = 2; i < 10000; i++){
        if(a[i] < 10000 && i == a[a[i]] && i != a[i]){
            printf("i = %i, a[i] = %i, a[a[i]] = %i\n", i, a[i], a[a[i]]);
            sum += i;
        }
    }

    printf("amicable: %i\n", sum);

    return 1;
}
