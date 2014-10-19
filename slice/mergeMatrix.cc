#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &result)
{
  for (auto i : result)
    cout << i << ", ";
  cout << endl;
}

void merge(vector<int> &result, int i, int j)
{
  const int gap = j - i;
  vector<int> left(result.begin() + i, result.begin() + j);
  vector<int> right(result.begin() + j, result.begin() + j + gap);
  size_t l = 0;
  size_t r = 0;
  auto index = i;
  while (l < left.size() && r < right.size()) {
    if (left[l] < right[r])
      result[index++] = left[l++];
    else
      result[index++] = right[r++];
  }
  while (l < left.size())
    result[index++] = left[l++];

  //print(result);
}

void mergeMatrix(vector<vector<int>> &vv)
{
  vector<int> result;
  const int n = vv[0].size();
  const int m = vv.size();
  vv.reserve(m * n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      result.push_back(vv[i][j]);
    }
  }

  for (int gap = n; gap < m * n; gap *= 2) {
    for (int i = 0; i + gap < m * n; i += 2 * gap) {
      merge(result, i, i + gap);
    }
  }

  print(result);
}

int main()
{
  vector<vector<int>> vv({
                         { 1, 2, 3},
                         { 2, 4, 6},
                         { 3, 6, 9},
                         { 4, 8, 12}});

  mergeMatrix(vv);

  return 0;
}
