#include <iostream>
using namespace std;

// A(n) = 1+x+x^2+x^3+...+x^n(n为整数且>=0)
int An(int x, int n)
{
  int tmp = x + 1;
  for (int i = 0; i < n - 1; i++) {
    tmp = tmp * x + 1;
  }

  return tmp;
}

int main()
{
  cout << An(2, 3) << endl;

  return 0;
}
