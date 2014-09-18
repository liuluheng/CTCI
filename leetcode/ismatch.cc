#include <iostream>
using namespace std;

bool ismatch(const char *s, const char *p)
{
  while (*s) {
    const char *p_old = p - 1;
    if (*s != *p) {
      if (*p == '.') {
        p++;
        if (*p == '*') {
          p++;
          return true;
        }
      }
      if (*p_old == *s && *p == '*') {
        s++;
        continue;
      }

      while (*p && *p != *s) {
        p++;
      }
      if (*p && *p == *s) {
        continue;
      }

      return false;
    }
    s++; p++;
  }
  return true;
}

int main()
{
  cout << ismatch("aa", "a") << endl;
  cout << ismatch("aa", "aa") << endl;
  cout << ismatch("aaa", "aa") << endl;
  cout << ismatch("aaa", "a*") << endl;
  cout << ismatch("aaa", ".*") << endl;
  cout << ismatch("abb", ".*") << endl;
  cout << ismatch("aab", "c*a*b") << endl;

  return 0;
}
