#include <iostream>
using namespace std;

void merge(int A[], int m, int B[], int n)
{
  int idxa = m - 1, idxb = n - 1, idxcur = m + n - 1;
  while (idxa >= 0 && idxb >= 0) {
    A[idxcur--] = A[idxa] > B[idxb] ? A[idxa--] : B[idxb--];
  }
  while (idxb >= 0) {
    A[idxcur--] = B[idxb--];
  }
}

int main()
{
  int A[20] = { 1, 3, 5, 7, 9, 11 };
  int B[5] = { 2, 4, 6, 8, 10};

  merge(A, 6, B, sizeof(B)/sizeof(B[0]));

  for (auto i : A) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
