#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kthPermutation(int n, int k)
{
  vector<int> seq;
  seq.reserve(n);
  for (int i = 1; i <= n; ++i)
    seq.push_back(i);

  while (--k && next_permutation(seq.begin(), seq.end()));
  return seq;
}

int main()
{
  int n = 4;
  int k = 3;

  auto v = kthPermutation(n, k);

  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
