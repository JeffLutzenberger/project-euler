#include <string.h>
#include <iostream>
#include <string>
#include <math.h>

void count_sundays() {
    //1 jan 1900 was a monday
    //jan = 31
    //feb = 28 (29 on leap year) year divisible by 4 not a century unless divisible by 400
    //march = 31
    //april = 30
    //may = 31
    //june = 30
    //july = 31
    //august = 31 
    //sept = 30
    //oct = 31
    //nov = 30
    //dec = 31
    //[monday, tuesday, weds, thurs, fri, sat, sun]
    //first of month day % 7 == 0 (first of month is a sunday)
    
    //year
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days = 0;
    int ans = 0;
    for(int i = 0; i <= 1; i++) {
        //loop through months
        int leap = 0;
        if((1900 + i) % 4 == 0 && !((1900 + i) % 400 == 0)){
            leap = 1;
        }
        printf("year: %i   leap: %i\n", i + 1900, leap);
        //now loop through months
        for(int j = 0; j < 12; j++) {
            int n_days = days_in_month[j];
            if(j == 1) n_days + leap;
            for(int k = 0; k < n_days; k++) {
                //every day in month (if k == 0 and totals days % 7 == 0) 
                //then months starts on sunday
                total_days++;
                if(i > 0 && k == 0 && total_days % 7 == 0) ans++;
            }
        }
    }
    printf("number of months that started on sunday 1901-2000: %i\n", ans);
}


int main() {
    count_sundays();
    return 1;
}
