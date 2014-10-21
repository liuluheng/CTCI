#include <iostream>
using namespace std;

int countWays(int n, int map[])
{
  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else if (map[n] > 0) 
    return map[n];
  else {
    map[n] = countWays(n - 1, map) +
             countWays(n - 2, map) +
             countWays(n - 3, map);
    return map[n];
  }
}

int main()
{
  static const int N = 36;
  int map[N] = { 0 };
  int methods = countWays(N, map);

  cout << N << " steps have ";
  cout << methods << " methods" << endl;

  return 0;
}
