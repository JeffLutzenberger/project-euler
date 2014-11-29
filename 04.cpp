#include <stdio.h>
#include <string.h>

int is_palindrome(int n) {
    char str[16];
    sprintf(str, "%i", n);
    //now see if the string is a palindrome
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] != str[len-1-i]) return 0;
    }
    return 1;
}

void large_palindrome() {
    int p1 = 0;
    int p2 = 0;
    int pal = 0;
    for(int i = 100; i < 999; i++){
        for(int j = i+1; j < 999; j++) {
            int res = i * j;
            if(is_palindrome(res) && res > pal) {
                p1 = i;
                p2 = j;
                pal = res;
            }
        }
    }
    printf("largest palindrome: %i * %i = %i\n", p1, p2, pal);
}

int main() {
    large_palindrome();
    return 1;
}
