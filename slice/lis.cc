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

int main()
{
  int A[] = {0, 2, 4, 3, 6, 5, 7, 1};
  cout << lis(A, 7) << endl;

  return 0;
}
