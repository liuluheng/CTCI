#include <iostream>
#include <vector>
using namespace std;

void printPare(vector<string> &vs, string &s,
               int left, int right, int count)
{
  if (left < 0 || right < left)
    return;

  if (left == 0 && right == 0) {
    // interesting... if no '\0' no output for s..
    // need s.c_str();
    cout << s.c_str() << endl;
    vs.push_back(s);
  } else {
    if (left > 0) {
      s[count] = '(';
      printPare(vs, s, left - 1, right, count + 1);
    }
    if (right > left) {
      s[count] = ')';
      printPare(vs, s, left, right - 1, count + 1);
    }
  }
}

int main()
{
  int n = 3;
  vector<string> vs;
  string s;
  printPare(vs, s, n, n, 0);

  return 0;
}
