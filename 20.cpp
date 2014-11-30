#include <string.h>
#include <iostream>
#include <string>
#include <math.h>

//note overflow! use python
void sum_factorial_digits(int n) {
    double fact = 1.0;
    for(int i = 1; i < n; i++) {
        fact *= (double)i;
        if((long)fact % 10 == 0) {
            printf("%f\n", fact);
            printf("divisible by 10\n");
            fact /= (double)10;
            printf("%f\n", fact);
        }
    }
    printf("%f\n", fact);
    char str[512];
    sprintf(str, "%f", fact);
    int sum = 0;
    char* token = strtok(str, ".");
    printf("%s\n", token);
    for(int i = 0; i < strlen(token); i++) {
        sum += (int)(token[i] - '0');
    }

    printf("%i\n", sum);
}


int main() {
    sum_factorial_digits(100);
    return 1;
}
