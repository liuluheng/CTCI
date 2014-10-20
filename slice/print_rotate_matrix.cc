// 逆时针旋转45°打印
// 3
// 2 6
// 1 5 9
// 4 8
// 7
//
// still not implemented..
#include <iostream>
#include <vector>
using namespace std;

void print_rotate_matrix(vector<vector<int>> vv)
{
  const auto rownum = vv.size();
  const auto colnum = vv[0].size();
  for (size_t row = 0; row < rownum; row++) {
    size_t offset = rownum - row - 1;
    for (size_t col = offset; col < colnum; col++) {
      cout << vv[row][col] << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<vector<int>> vv({
                         { 1, 2, 3},
                         { 4, 5, 6},
                         { 7, 8, 9}});

  print_rotate_matrix(vv);

  return 0;
}
