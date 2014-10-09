#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  for (int layer = 0; layer < n / 2; layer++) {
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; i++) {
      int offset = i - first;

      int top = matrix[first][i];
      matrix[first][i] = matrix[last - offset][first];
      matrix[last - offset][first] = matrix[last][last - offset];
      matrix[last][last - offset] = matrix[i][last];
      matrix[i][last] = top;
    }
  }
}

void print(vector<vector<int>> &matrix)
{
  for (auto v : matrix) {
    for (auto i : v)
      cout << i << " ";
    cout << endl;
  }
  cout << endl;
}

int main()
{
  vector<vector<int>> matrix({
                             {1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16},
                             });

  print(matrix);
  rotate(matrix);
  print(matrix);

  return 0;
}
