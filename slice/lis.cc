#include <iostream>
using namespace std;

int lis(int A[], int n)
{
  int len[n + 1];
  for (int i = 0; i <= n; i++)
    len[i] = 1;

  for (int L = 2; L <= n - 1; L++) {
    for (int i = 1; i <= n - L + 1; i++) {
      int j = i + L -1;
      //wrong??
      if (A[j] >= A[j -1]) {
        if (L == 2)
          len[j] = 2;
        else
          len[j] = len[j - 1] + 1;
      } else {
        len[j] = len[j - 1];
      }
    }
  }

  for (auto i : len)
    cout << i << " ";
  cout << endl;

  return len[n];
}

int lis2(int A[], int n)
{
  int d[n];
  for (int i = 0; i < n; i++) {
    d[i] = 1;
    for (int j = 0; j < i; j++) {
      if (A[j] <= A[i] && d[j] + 1 > d[i] )
        d[i] = d[j] + 1;
    }
  }

  for (auto i : d)
    cout << i << " ";
  cout << endl;

  return d[n - 1];
}

int main()
{
  int A[] = {/*-1,*/ 5, 3, 4, 8, 6, 7};
  cout << lis(A, 6) << endl;
  cout << lis2(A, 6) << endl;

  return 0;
}
