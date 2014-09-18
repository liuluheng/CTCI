#include <stdio.h>

#define LEFT(i) (i << 1) + 1
#define RIGHT(i) (i << 1) + 2
#define PARENT(i) (i-1) >> 1

int a[14] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
int heapsize = 14;
int heaplength = 14;

void print(void)
{
    int i;
    for (i = 0; i < 14; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void max_heapify(int a[], int i)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = 0;

    if (l < heapsize && a[l] > a[i])
        largest = l;
    else
        largest = i;
    if (r < heapsize && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        int tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;

        max_heapify(a, largest);
    }
}

void build_maxheap(int a[])
{
    int i;
    for (i = heapsize/2; i >= 0; i--)
        max_heapify(a, i);
}

void heapsort(int a[])
{
    build_maxheap(a);
    int i;
    for (i = heaplength - 1; i > 0; i--) {
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;

        heapsize--;
        max_heapify(a, 0);
    }
}

int main(void)
{
    print();
    heapsort(a);
    print();

    return 0;
}
    
