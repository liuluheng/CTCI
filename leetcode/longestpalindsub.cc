#include <iostream>
#include <algorithm>
using namespace std;

string longestpalindsub(string &str)
{
  const int n = str.size();
  bool f[n][n];
  fill_n(&f[0][0], n * n, false);

  int start = 0;
  int max_len = 1;
  for (int i = 0; i < n; ++i) {
    f[i][i] = true;
    for (int j = 0; j < i; ++j) {
      if (str[j] == str[i] && (f[j+1][i-1] || i == j+1)) {
        f[j][i] = true;
        if (max_len < i - j + 1) {
          start = j;
          max_len = i - j + 1;
        }
      }
    }
  }

  return str.substr(start, max_len);
}

int main()
{
  string s = "zhangliuluhenggnehuluiltao";
  cout << longestpalindsub(s) << endl;

  return 0;
}
