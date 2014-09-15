//Given an array S of n integers, are there elements a, b, c in S such that 
//a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//Note:
//• Elements in a triplet (a, b, c) must be in non-descending order. (ie, a  b ≤ c)
//• The solution set must not contain duplicate triplets.
//For example, given array S = {-1 0 1 2 -1 -4}.
//A solution set is:
//(-1, 0, 1)
//(-1, -1, 2)
//
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//暴力法,效率不高
class Solution0 {
 public:
   vector<vector<int>> threeSum(vector<int> &vi, int target) {
    vector<vector<int>> result;

    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for (auto first = vi.begin(); first != prev(vi.end(), 2); ++first) {
      for (auto third = prev(vi.end()); third > first; --third) {
        while (third > first) {
          //cout << "fir " << *first << *third << endl;
          for (auto second = prev(third); second > first; --second) {
            if (*second == target - *first - *third) {
              //cout << "push" << *first << *second << *third << endl;
              result.push_back({*first, *second, *third});
            }
          }
          --third;
        }
      }
    }

    sort(result.begin(), result.end());
    auto unique_end = unique(result.begin(), result.end());
    result.erase(unique_end, result.end());
    return result;
  }
};

// LeetCode, 3Sum
// 先排序,然后左右夹逼,时间复杂度 O(n^2),空间复杂度 O(1)
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& num) {
    vector<vector<int>> result;
    if (num.size() < 3) return result;
    sort(num.begin(), num.end());
    const int target = 0;
    auto last = num.end();
    for (auto a = num.begin(); a < prev(last, 2); ++a) {
      auto b = next(a);
      auto c = prev(last);
      while (b < c) {
        if (*a + *b + *c < target) {
          ++b;
        } else if (*a + *b + *c > target) {
          --c;
        } else {
          result.push_back({ *a, *b, *c });
          ++b;
          --c;
        }
      }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
  }
};

void print(vector<vector<int>> &result)
{
  for (auto ret : result) {
    cout << "( ";
    for (auto ret2 : ret) {
      cout << ret2 << ", ";
    }
    cout << ")";
  }
  cout << endl;
}

int main()
{
  vector<int> a = {-1, 0, 1, 2, -1, -4};
  Solution s;
  vector<vector<int>> result;
  result = s.threeSum(a);
  print(result);

  a = {1, 2, 1, 2, 1, 4};
  int target = 5;

  Solution0 s0;
  result = s0.threeSum(a, target);

  print(result);

  return 0;
}
