#include <string.h>
#include <iostream>
#include <string>
#include <map>

std::map<long, long> factors_map;

//factors_map[1] = 1;
//factors_map[2] = 2;

long calc_triangle(long n) {
    long sum = 0;
    for(long i = 1; i <= n; i++)
        sum += i;
    return sum;
}

long calc_factors(long n) {
    long num = n;
    if(n == 1) return 1;
    long facts = 0; 
    for(long i = 1; i < num; i++){
        if(n % i == 0){
            num = n / i;
            //printf("num = %li, div = %li\n", num, i);
            facts += 2;
        }
    }
    return facts;
}

void triangle_numbers(long n_factors) {
    long factors = 0;
    long i_triangle = 1;
    long triangle = 0;
    while(factors < n_factors){
        //get a triangle number
        triangle = calc_triangle(i_triangle);
        factors = calc_factors(triangle);
        //printf("triangle number %li =  %li: it has %li factors\n", i_triangle, triangle, factors);
        i_triangle++;
    }
    printf("%li has %li factors\n", triangle, factors);
}

int main() {
    triangle_numbers(500);
    return 1;
}
