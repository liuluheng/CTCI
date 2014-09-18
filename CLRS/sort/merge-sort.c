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
    int q;
    if (p < r) {
        q = (p + r) / 2;
        printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n",
                p, q, q+1, r,
                A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7]);
        mergesort(p, q);
        mergesort(q + 1, r);

        merge(p, q, r);
        printf("merge (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n",
                p, q, q+1, r,
                A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7]);
    }
}

void merge(int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int i, L[n1 + 1], j, R[n2 + 1];
    for (i = 0; i < n1; i++) {
        L[i] = A[p + i];
        printf("L[%d]:%d ", i, L[i]);
    }
    printf("\n");
    for (j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
        printf("R[%d]:%d ", j, R[j]);
    }
    printf("\n");
    L[n1] = INF;
    R[n2] = INF;

    i = j = 0;
    int k = p;
    while (k <= r) {
        if (L[i] <= R[j]) {
            A[k++] = L[i];
            i++;
        } else {
            A[k++] = R[j];
            j++;
        }
    }
}

int main(void)
{
    mergesort(0, SIZE - 1);
    print();

    return 0;
}
