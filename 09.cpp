#include <stdio.h>
#include <string.h>

void pythagorean_triplet(int n) {
    for(int a = 1; a < n; a++){
        for(int b = a + 1; b < n; b++){
            for(int c = b + 1; c < n; c++){
                if(a + b + c == n && a*a + b*b == c*c){
                    printf("%i  %i  %i\n", a, b, c);
                    printf("%i\n", a * b * c);
                    return;
                }
            }
        }
    }
}

int main() {
    pythagorean_triplet(12);
    pythagorean_triplet(1000);
    return 1;
}
