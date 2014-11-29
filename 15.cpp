#include <string.h>
#include <iostream>
#include <string>
#include <map>

void pascals_triangle() {
    //start with a n by n matrix 
    const int n = 21;
    long mat[n][n] = {{1}};
    for(long i = 0; i < n; i ++){
        for(long j = 0; j < n; j++) {
            if(i == 0 || j == 0) mat[i][j] = 1;
            else mat[i][j] = mat[i-1][j] + mat[i][j-1];
        }
    }

    printf("%li\n", mat[n-1][n-1]);
}

int main() {
    pascals_triangle();    
    return 1;
}
