#include <string.h>
#include <iostream>
#include <string>
#include <map>

long collatz(long n, std::map<long, long> &collatz_map) {
    long res = n;
    long length = 1;
    while(res != 1) {
        //look it up here...
        //if(collatz_map[res] != 0){
        //    length += collatz_map[res];
        //    return length;
        //}
        if(res % 2 == 0) res = res / 2;
        else res = 3 * res + 1;
        length++;
    }
    // add it to the map here
    collatz_map[n] = length;
    // show content:
    //for (std::map<long,long>::iterator it=collatz_map.begin(); it!=collatz_map.end(); ++it)
    //    std::cout << it->first << " => " << it->second << '\n';
    return length;
}

int largest_4x4(int a[][20], int i_start, int j_start) {
    int largest = 0;
}
int main() {
    std::map<long, long> collatz_map;
    long max_length = 0;
    long i_max_length = 0;
    for(long i = 1; i < 1e6; i++) {
        long length = collatz(i, collatz_map);
        if(length > max_length){
            max_length = length;
            i_max_length = i;
        }
    }
    printf("max length is %li occurs for number %li\n", max_length, i_max_length);
    return 1;
}
