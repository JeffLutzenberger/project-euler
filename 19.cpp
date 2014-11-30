#include <string.h>
#include <iostream>
#include <string>
#include <math.h>

char str[] = 
"75 \
95 64 \
17 47 82 \
18 35 87 10 \
20 4 82 47 65 \
19 1 23 75 3 34 \
88 2 77 73 7 63 67 \
99 65 4 28 6 16 70 92 \
41 41 26 56 83 40 80 70 33 \
41 48 72 33 47 32 37 16 94 29 \
53 71 44 65 25 43 91 52 97 51 14 \
70 11 33 28 77 73 17 78 39 68 17 57 \
91 71 52 38 17 14 91 43 58 50 27 29 48 \
63 66 4 68 89 53 67 30 73 16 69 87 40 31 \
4 62 98 27 23 9 70 98 73 93 38 53 60 4 23";

void make_matrix() {
    int a[15][15] = {{0}};
    char* token = strtok(str, " ");
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j <= i; j++) {
            a[i][j] = std::stoi(token);
            token = strtok(NULL, " ");
        }
    }  
    for(int i = 0; i < 15; i++){
        for(int j = 0; j <= i; j++){
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
    //now start at second from bottom row and maximize sub triangle
    for(int i = 13; i >= 0; i--) {
        for(int j = 0; j <= i; j++){
            //which is bigger j or j+1
            int sum = a[i+1][j] > a[i+1][j+1] ? a[i+1][j] : a[i+1][j+1];
            a[i][j] += sum;
        }
    } 
    for(int i = 0; i < 15; i++){
        for(int j = 0; j <= i; j++){
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
}


int main() {

    make_matrix();
    return 1;
}
