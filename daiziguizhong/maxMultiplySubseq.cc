#include <iostream>
using namespace std;

int maxProduct(int A[], int n)
{
  int max = A[0];
  int min = A[0];
  int a = max;

  for (int i = 1; i < n; i++) {
    int tmpMax = max * A[i];
    int tmpMin = min * A[i];
    max = std::max(tmpMax, std::max(tmpMin, A[i]));
    min = std::min(tmpMax, std::min(tmpMin, A[i]));
    a = std::max(max, a);
  }

  return a;
}

int main()
{
  int A[] = { 2, 3, -2, 4};
  int m = maxProduct(A, sizeof(A)/sizeof(A[0]));

  cout << m << endl;

  return 0;
}
