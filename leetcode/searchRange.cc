#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> searchRange(int A[], int n, int target)
{
  auto result = equal_range(A, A + n, target);
  if (*result.first != target)
    return vector<int> {-1, -1};
  else
    return vector<int> {distance(A, result.first),
                        distance(A, prev(result.second))};
}

template<typename ForwardIterator, typename T>
ForwardIterator lower_bound2(ForwardIterator begin,
                            ForwardIterator end,
                            T target)
{
  while (begin < end) {
    auto mid = next(begin, distance(begin, end)/2);
    if (*mid < target)
      begin = mid + 1;
    else if (*mid == target)
      return mid;
    else
      end = mid - 1;
  }

  return end;
}

template<typename ForwardIterator, typename T>
ForwardIterator upper_bound2(ForwardIterator begin,
                             ForwardIterator end,
                             T target)
{
  while (begin < end) {
    auto mid = next(begin, distance(begin, end)/2);
    if (*mid <= target)
      begin = mid + 1;
    else
      end = mid;
  }

  return end;
}

int main()
{
  int A[] = {3, 4, 6, 6, 8, 8, 8, 10};
  auto vec = searchRange(A, 8, 8);
  for (auto i : vec)
    cout << i << " ";
  cout << endl;

  cout << distance(A, lower_bound2(A, A + 8, 8)) << endl;
  cout << distance(A, upper_bound2(A, A + 8, 8)) << endl;
}
