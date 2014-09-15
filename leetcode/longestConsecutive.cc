#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> map;
    int size = num.size();
    int l = 1;
    for (int i = 0; i < size; i++) {
      if (map.find(num[i]) != map.end()) continue;
      map[num[i]] = 1;
      if (map.find(num[i] - 1) != map.end()) {
        l = max(l, mergeCluster(map, num[i] - 1, num[i]));
      }
      if (map.find(num[i] + 1) != map.end()) {
        l = max(l, mergeCluster(map, num[i], num[i] + 1));
      }
    }

    for (auto val : map) {
      if (val.second == l)
        cout << val.first << ",";
    }
    cout << endl;
    return size == 0 ? 0 : l;
  }

 private:
  int mergeCluster(unordered_map<int, int> &map, int left, int right) {
    cout << left << " " << right << endl;
    int upper = right + map[right] - 1;
    int lower = left - map[left] + 1;
    int length = upper - lower + 1;
    map[upper] = length;
    map[lower] = length;
    return length;
  }
};

int main()
{
  vector<int> v = { 45, 2, 3, 4, 1, 56, 9, 8};

  Solution s;
  cout << s.longestConsecutive(v) << endl;
   
  return 0;
}
