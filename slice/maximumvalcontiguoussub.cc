#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int max(int a, int b)
{
  return a > b ? a : b;
}

int mvcs(int arr[], int n)
{
  int M[n];
  memset(&M[0], 0, sizeof(M));
  M[0] = arr[0];
  int start = 0;
  int end = 0;
  int maximum = 0;
  for (int j = 1; j < n; ++j) {
    if (M[j - 1] + arr[j] < arr[j]) {
      start = j;
    }
    M[j] = max(M[j - 1] + arr[j], arr[j]);
    if (M[j] > maximum) {
      maximum = M[j];
      end = j;
    }
  }

  for (auto v : M)
    cout << v << " ";
  cout << endl;

  return M[n-1];
}

int main()
{
  int arr[] = {1, 2, 3, -1, 100, -2};
  cout << mvcs(arr, sizeof(arr)/sizeof(arr[0])) << endl;

  return 0;
}
