#include <string.h>
#include <iostream>
#include <string>
#include <math.h>

int main() {

    int exp = 5;
    int exp_factor = 3;
    double ans = pow(2, 1000);
   
    char str[500];
    sprintf(str, "%f", ans);
    char* token = strtok(str, ".");
    printf("%s\n", str);
    int sum = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        printf("%c ", str[i]);
        sum r= str[i] - '0';
    }

    printf("\n%i\n", sum);

    return 1;
}
