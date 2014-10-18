#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permutation(vector<int> &v, int index)
{
  vector<vector<int>> subsets;
  if (index == 0) {
    subsets.push_back(vector<int>({v[0]}));
    return subsets;
  }

  vector<vector<int>> subsets2 = permutation(v, index - 1);
  for (auto vi : subsets2) {
    for (size_t i = 0; i < v.size(); ++i) {
      vector<int> vtmp = vi;
      vtmp.insert(v.begin() + i, v[index]);
      subsets.push_back(vtmp);
    }
  }

  return subsets;
}

int main()
{
  vector<int> v;
  v.reserve(4);
  for (int i = 1; i <= 4; i++) {
    v.push_back(i);
  }
  auto vv = permutation(v, v.size() - 1);

  for (auto v : vv) {
    for (auto i : v) {
      cout << i << ", ";
    }
    cout << endl;
  }

  return 0;
}
