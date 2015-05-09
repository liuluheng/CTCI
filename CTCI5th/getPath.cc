#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Point {
  Point(int x = -1, int y = -1) : x(x), y(y) {}
  bool operator==(const Point rhs) { return x == rhs.x && y == rhs.y; }
  int x;
  int y;
};

vector<Point> badPoint{{Point(1, 1), Point(0, 1)}};

bool isFree(int x, int y)
{
  return find(badPoint.begin(), badPoint.end(), Point(x, y)) 
              == badPoint.end();
}

bool getPath(int x, int y, vector<Point *> &path, 
             unordered_map<Point *, bool> cache)
{
  Point *p = new Point(x, y);

  // already visit 
  // (x-1, y-1)
  if (cache.find(p) != cache.end())
    return cache[p];

  path.push_back(p);
  if (x == 0 && y == 0)
    return true; // find a path;

  bool success = false;
  if (x >= 1 && isFree(x - 1, y))
    success = getPath(x - 1, y, path, cache);

  if (!success && y >= 1 && isFree(x, y - 1))
    success = getPath(x, y - 1, path, cache);

  if (!success) {
    // erase-remove for seq container
    // erase(iter++) for associ container(set, map) ..
    path.erase(remove(path.begin(), path.end(), p),
               path.end());
  }

  cache[p] = success;

  return success;
}

int main()
{
  vector<Point *> path;
  unordered_map<Point *, bool> cache;

  if (getPath(2, 2, path, cache)) {
    for (auto iter = path.rbegin(); iter != path.rend(); iter++) {
      cout << "(" << (*iter)->x << ", " 
           << (*iter)->y << ") ";
    }
    cout << endl;
  }

  return 0;
}
