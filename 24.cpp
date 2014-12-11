#include <stdio.h>

void swap (int a[], int i, int j) {
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void do_perm() {
    int perm[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int count = 1;
    int numPerm = 1000000;
    while (count < numPerm) {
        int N = 10;
        int i = N-1;
        while (perm[i - 1] >= perm[i]) {
            i = i - 1;
        }
        int j = N;
        while (perm[j - 1] <= perm[i - 1]) {
            j = j - 1;
        }
        swap(perm, i - 1, j - 1);

        i++;
        j = N;
        while (i < j) {
            swap(perm, i - 1, j - 1);
            i++;
            j--;
        }
        count++;
    }

    for (int k = 0; k < 10; k++) {
        printf("%i", perm[k]);
    }
    printf("\n");
}

int main () {
    do_perm ();
    return 1;
}

