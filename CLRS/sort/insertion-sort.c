#include <stdio.h>

#define SIZE 7

int main(void)
{
    int A[SIZE] = {5, 2, 4, 6, 1, 3, 9};
    int i, j, key;

    for (j = 0; j < SIZE; j++) {
        key = A[j];

        i = j - 1;
        while (i > -1 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }

    for (i = 0; i < SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");
}
