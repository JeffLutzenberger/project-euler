#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_CHARS = 64;

void print_array(char a[][MAX_CHARS], int len) {
    for(int i = 0; i < len; i++)
        printf("%s\n", a[i]);
    printf("\n");
}

void copy_array(char a[][MAX_CHARS], int i_start, int i_end, char b[][MAX_CHARS]){
    for(int i = i_start; i < i_end; i++) strcpy(a[i], b[i]);
}

void merge(char a[][MAX_CHARS], int i_start, int i_middle, int i_end, char b[][MAX_CHARS]) {
    int i1 = i_start;
    int i2 = i_middle;
    for(int i = i_start; i < i_end; i++){
        if(i1 < i_middle && (strcmp(a[i1], a[i2]) < 0 || i2 >= i_end))
            strcpy(b[i], a[i1++]);
        else strcpy(b[i], a[i2++]);
    }
}

void split_and_merge(char a[][MAX_CHARS], int i_start, int i_end, char b[][MAX_CHARS]) {
    if(i_end - i_start < 2) return;
    int i_middle = (i_start + i_end) * 0.5;
    split_and_merge(a, i_start, i_middle, b);
    split_and_merge(a, i_middle, i_end, b);
    merge(a, i_start, i_middle, i_end, b);
    copy_array(a, i_start, i_end, b);
}

void merge_sort(char a[][MAX_CHARS], int len, char b[][MAX_CHARS]) {
    split_and_merge(a, 0, len, b);
}

int word_worth(char a[]) {
    int len = strlen(a);
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += (int)(a[i] - 'A') + 1;
    }
    return sum;
}

int main() {
    char a[][MAX_CHARS] = {"CHRIS", "JEFF", "DAVEY", "FAITH", "JOHN"};
    char b[5][MAX_CHARS];
    merge_sort(a, 5, b);
    //print_array(a, 5);

    //now read in our file and convert to array of strings
    char* str = 0;
    long length;
    FILE* fp;
    fp = fopen("names.txt", "r");
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    str = (char*)malloc(length);
    if (str){
        fread (str, 1, length, fp);
    }
    fclose (fp);
    int i_names = 0;
    char* token = strtok(str, ",\"");
    char names[5163][MAX_CHARS];
    while(token != NULL) {
        //printf("%s ", token);
        strcpy(names[i_names], token);
        token = strtok(NULL, ",\"");
        i_names++;
    }
    //printf("num names = %i", i_names);
    char temp_names[5163][MAX_CHARS];
    merge_sort(names, 5163, temp_names);
    //print_array(names, 5163);
    char colin[] = "COLIN";
    printf("%s is worth: %i\n", colin, word_worth(colin));
    long sum = 0;
    for(int i = 0; i < 5163; i++) {
        sum += ((long)(i + 1) * (long)word_worth(names[i]));
    }
    printf("total: %li\n", sum);
    return 1;
}
