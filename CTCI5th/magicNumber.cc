// ../slice/bsearch.cc have the iterative one
#include <iostream>
#include <vector>
using namespace std;

int magicSearch(int arr[], int start, int end, vector<int> &result)
{
  //vector<int> result;
  if (start > end || start < 0)
    return -1;

  const int midIndex = (start + end) / 2;
  const int midValue = arr[midIndex];
  if (midIndex == midValue) {
    //return midIndex;
    result.push_back(midValue);
  }

  const int leftIndex = min(midIndex - 1, midValue);
  int left = magicSearch(arr, start, leftIndex, result);
  if (left >= 0)
    return left;

  const int rightIndex = max(midIndex + 1, midValue);
  int right = magicSearch(arr, rightIndex, end, result);
  if (right >= 0)
    return right;

  return right;
}

int main()
{
  int arr[] = { -10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
  vector<int> result;
  magicSearch(arr, 0, sizeof(arr)/sizeof(int), result);
  for (auto i : result)
    cout << i << ", ";
  cout << endl;

  return 0;
}
