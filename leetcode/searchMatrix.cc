#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &Matrix, int target)
{
  if (Matrix.empty())
    return false;

  const size_t rows = Matrix.size();
  const size_t cols = Matrix.front().size();
  int first = 0, last = rows * cols;

  while (first < last) {
    int mid = first + (last - first) / 2;
    int value = Matrix[mid/cols][mid%cols];
    cout << first << " "
         << mid << " "
         << last << " "
         << value << endl;
    if (value < target)
      first = mid + 1;
    else if (value > target)
      last = mid; // mid - 1 is wrong... when search 3
    else
      return true;
  }

  return false;
}

int main()
{
  vector<vector<int>> Matrix = {
    { 1, 3, 5, 7},
    { 10, 11, 16, 20},
    { 23, 30, 34, 50}
  };

  cout << searchMatrix(Matrix, 1) << endl;
  cout << searchMatrix(Matrix, 3) << endl;
  cout << searchMatrix(Matrix, 50) << endl;


  return 0;
}
