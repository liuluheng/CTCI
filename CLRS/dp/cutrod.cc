#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

int p[1000], r[1000], s[1000];

void bottom_up_cut_rod(int *p, int n)
{
  r[0] = 0;
  for (int j = 1; j <= n; j++) {
    int q = -1e8;
    for (int i = 1; i <= j; i++) {
      if (q < (p[i] + r[j - i])) {
        q = p[i] + r[j - i];
        s[j] = i;
        r[j] = q;
      }
    }
  }
}

static int memoized_cut_rod_aux(int *p, int n, int *r)
{
  if (r[n] >= 0) {
    return r[n];
  }
  int q;
  if (n == 0) {
    q = 0;
  } else {
    q = -1e8;
    for (int i = 1; i <= n; i++) {
      int tmp = memoized_cut_rod_aux(p, n - i, r);
      if (q < (p[i] + tmp)) {
        q = p[i] + tmp;
        s[n] = i;
      }
    }
  }
  r[n] = q;
  return q;
}

int memoized_cut_rod(int *p, int n)
{
  memset(r, -1, sizeof(r));
  return memoized_cut_rod_aux(p, n, r);
}

void print_cut_rod_solution(int *p, int n)
{
  //bottom-up
  //bottom_up_cut_rod(p, n);
  
  //top-down
  memoized_cut_rod(p, n);
  while (n > 0) {
    cout << s[n] << " " << endl;
    n = n - s[n];
  }
}

static ostream &print(ostream &os, const int i, char c)
{
  return os << i << c;
}

int main()
{
  int n;
  std::ifstream input("cutrod.txt");
  //cin >> n;
  input >> n;
  //cout << n;
  memset(p, 0, sizeof(p));
  memset(r, 0, sizeof(r));
  memset(s, 0, sizeof(s));

  for (int i = 1; i <= n; i++) {
    //cin >> p[i];
    input >> p[i];
    //cout << p[i];
  }

  print_cut_rod_solution(p, n);

  cout << "result:\n";
  cout << "\ts:\n\t";
  for_each(begin(s), s + n + 1,
           bind(print, ref(cout), _1, ' '));
  cout << endl;
  cout << "\tr:\n\t";
  for_each(begin(r), r + n + 1,
           bind(print, ref(cout), _1, ' '));
  cout << endl;

  return 0;
}
