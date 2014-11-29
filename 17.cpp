#include <string.h>
#include <iostream>
#include <string>
#include <math.h>

char ones_str[][16] = {{""}, {"one"}, {"two"}, {"three"}, {"four"},
                       {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"}};
char teens_str[][16] = {{"ten"}, {"eleven"}, {"twelve"}, {"thirteen"}, {"fourteen"},
                    {"fifteen"}, {"sixteen"}, {"seventeen"}, {"eighteen"}, {"nineteen"}};
char tens_str[][16] = {{"twenty"}, {"thirty"}, {"forty"}, {"fifty"}, {"sixty"}, {"seventy"},
                       {"eighty"}, {"ninety"}};


int get_ones_count(int ones) {
    return strlen(ones_str[ones]);
}

int get_teens_count(int teens) {
    return strlen(teens_str[teens - 10]);
}

int get_tens_count(int tens) {
    return strlen(tens_str[tens / 10 - 2]);
}

int get_between_20_and_99_count(int i) {
    int ones = i - ((i / 10) * 10); 
    return get_tens_count(i) + get_ones_count(ones); 
}

int get_between_100_and_999_count(int i) {
    int sum = 0;
    //"<ones count>hundred"
    sum += get_ones_count(i / 100) + 7;
    int j = i - (i / 100) * 100;
    if(j > 0){
        //"and"
        sum += 3;
        if(j < 10) sum += get_ones_count(j);
        else if(j < 20) sum += get_teens_count(j);
        else if(j < 100) sum += get_between_20_and_99_count(j);
    } 
    return sum;
}
int main() {

    int sum = 0;
    for(int i = 1; i <= 1000; i++) {
        if(i < 10) sum += get_ones_count(i);
        else if(i < 20) sum += get_teens_count(i);
        else if(i < 100) sum += get_between_20_and_99_count(i);
        else if(i < 1000) sum += get_between_100_and_999_count(i); 
        //is 1000
        else sum += 11;
    }
   
    printf("%i\n", sum);

    return 1;
}
