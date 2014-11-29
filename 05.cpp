#include <stdio.h>
#include <string.h>

void evenly_divisible(int n) {
    int num = n;
    while(1){
        int i = n;
        for(i = n; i > 2; i--) {
            if(num % i != 0) {
                num+=n;
                break;
            }
        }
        if(i == 2) {
            printf("largest evenly divisible by 1 - %i = %i\n", n, num);
            return;
        }
    }
}

int main() {
    evenly_divisible(10);
    evenly_divisible(20);
    return 1;
}
