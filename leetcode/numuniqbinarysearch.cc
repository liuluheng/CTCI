#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n)
{
  vector<int> f(n + 1, 0);

  f[0] = 1;
  f[1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      f[i] += f[j - 1] * f[i - j];
    }
  }

  return f[n];
}

int main()
{
  cout << numTrees(1) << endl;
  cout << numTrees(2) << endl;
  cout << numTrees(3) << endl;

  return 0;
}
