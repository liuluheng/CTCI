#include <iostream>
#include <cstring>
using namespace std;

void print(int A[], int n)
{
  for (int i = 0; i < n; i++)
    cout << A[i] << " ";
  cout << endl;
}

int inplace_circular_delete(int A[], int B[], int nA, int nB)
{
  size_t i = 0;
  int len = nA / sizeof(int);

  while (i < (nA - nB + 1) / sizeof(int)) {
    if (!memcmp(A + i, B, nB)) {
      memmove(A + i, A + i + nB / sizeof(int), nA - i * sizeof(int) - nB);
      len -= nB / sizeof(int);
      i = 0;
    }
    i++;
  }

  print(A, len);
  return len;
}

int main()
{
  int A[] = { 1, 1, 1, 1, 1, 2, 2, 3};
  int B[] = { 1, 1, 2};

  inplace_circular_delete(A, B, sizeof(A), sizeof(B));
}
