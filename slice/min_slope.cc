#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Point {
  int x;
  int y;
};
struct Line {
  Line(Point p1, Point p2)
      : p1(p1), p2(p2) {
        k = abs((p2.y - p1.y) / (p2.x - p1.x));
      }

  int k;
  Point p1;
  Point p2;
};


int min_slope(vector<Point> &v)
{
  size_t size = v.size();
  int min = INT_MAX;
  for (size_t i = 0; i < size; i++) {
    for (size_t j = i + 1; j < size; j++) {
      Line line(v[i], v[j]);
      if (line.k < min)
        min = line.k;
    }
  }

  return min;
}

int main()
{
  vector<Point> v({{2, 3}, {3, 4}, {4, 6}, {6, 8}, {5, 7}});

  cout << min_slope(v) << endl;

  return 0;
}
