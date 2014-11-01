#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int> &vi, size_t step, vector<int> &path,
             vector<vector<int>> &result) {
  if (step == vi.size()) {
    result.push_back(path);
    return;
  }
  subsets(vi, step + 1, path, result);
  path.push_back(vi[step]);
  subsets(vi, step + 1, path, result);
  path.pop_back();
}

vector<vector<int>> subsets(vector<int> &vi)
{
  vector<vector<int>> result;
  vector<int> path;

  subsets(vi, 0, path, result);

  return result;
}

int main()
{
  vector<int> vi{1, 2, 3};

  auto vvi = subsets(vi);

  for (auto v : vvi) {
    cout << "[";
    for (auto i : v) {
      cout << i << ", ";
    }
    cout << "]";
  }
  cout << endl;

  return 0;
}
