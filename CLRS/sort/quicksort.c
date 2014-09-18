#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10] = {2, 5, 1, 9, 0, 3, 6, 7, 4, 8};

void print(void)
{
    int i;
    for (i = 0; i < 10; i++) 
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    int j;
    for (j = p; j < r; j++) {
        if (a[j] <= x) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return i + 1;
}


int Random(int p, int r)
{
    srandom(time(NULL));
    return (p + (random() % (r - p + 1)));
}

int random_partition(int a[], int p, int r)
{
    int i = Random(p, r);
    swap(&a[i], &a[r]);
    return partition(a, p, r);
}

void quicksort(int a[], int p, int r)
{
    if (p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

void random_quicksort(int a[], int p, int r)
{
    if (p < r) {
        int q = random_partition(a, p, r);
        random_quicksort(a, p, q - 1);
        random_quicksort(a, q + 1, r);
    }
}

int main(void)
{
    print();
    random_quicksort(a, 0, 9);
    print();
    printf("%d\n", Random(0, 10));

    return 0;
}
