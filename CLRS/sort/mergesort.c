#include <stdio.h>

#define SIZE 8
#define INF  128
int A[SIZE] = {5, 2, 4, 6, 1, 3, 8, 7};
void print(void)
{
    int i;
    for (i = 0; i < SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void merge(int p, int q, int r);

void mergesort(int p, int r)
{
    if (p < r) {
        int q = (p + r) / 2;

        mergesort(p, q);
        mergesort(q + 1, r);
        merge(p, q, r);
    }
}

void merge(int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int i, L[n1 + 1], j, R[n2 + 1];
    for (i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }
    L[n1] = INF;
    R[n2] = INF;

    i = j = 0;
    int k = p;
    while (k <= r) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }
}

int main(void)
{
    mergesort(0, SIZE - 1);
    print();

    return 0;
}
