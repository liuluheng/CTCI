#include <stdio.h>

#define LEFT(i) (i << 1) + 1
#define RIGHT(i) (i << 1) + 2
#define PARENT(i) (i-1) >> 1

#define NINF -1

int a[15] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
int heapsize = 14;

void print(void)
{
    int i;
    for (i = 0; i < 15; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int heap_extract_max(int a[]);
void extractmax(void)
{
    int i;
    for (i = 0; i < 15; i++)
        printf("%d ", heap_extract_max(a));
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

int heap_maximum(int a[])
{
    return a[0];
}

int heap_extract_max(int a[])
{
    if (heapsize < 1) {
        fprintf(stderr, "heap underflow\n");
        return -1;
    }
    int max = a[0];
    a[0] = a[heapsize - 1];
    heapsize--;
    max_heapify(a, 0);
    return max;
}

void heap_increase_key(int a[], int i, int key)
{
    if (key < a[i]) {
        fprintf(stderr, "heap underflow\n");
        return;
    }

    a[i] = key;
    while (i > 0 && a[PARENT(i)] < a[i]) {
        int tmp = a[i];
        a[i] = a[PARENT(i)];
        a[PARENT(i)] = tmp;

        i = PARENT(i);
    }
}

void max_heap_insert(int a[], int key)
{
    heapsize++;
    a[heapsize - 1] = NINF;
    heap_increase_key(a, heapsize - 1, key);
}

int main(void)
{
    print();
    max_heap_insert(a, 19);

    extractmax();
    print();

    return 0;
}
    
