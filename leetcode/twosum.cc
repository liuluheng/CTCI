#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  unordered_map<int, int> twosum(vector<int> &a, int target) {
    int num = a.size();
    unordered_map<int, int> map, result;
    map.reserve(num);

    for (int i = 0; i < num; i++) {
      map[a[i]] = i + 1;
      if (map.find(target - a[i]) != map.end()) {
        result.insert({target - a[i], map[target - a[i]]});
        result.insert(make_pair(a[i], map[a[i]]));
      }
    }

    return result;
  }
};

int main()
{
  vector<int> a = {2, 7, 1, 8, 11, 15, 9, 0};
  int target = 9;

  Solution s;
  unordered_map<int, int> result;
  result = s.twosum(a, target);

  for (auto ret : result) {
    cout << ret.first << " "
         << ret.second << endl;
  }

  return 0;
}
