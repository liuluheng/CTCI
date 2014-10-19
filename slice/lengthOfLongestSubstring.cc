#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s)
{
  bool exist[256] = { false };
  int i = 0;
  int j = 0;
  const int len = s.size();
  int maxlen = 1;
  while (j < len) {
    if (exist[(int)s[j]]) {
      maxlen = max(maxlen, j - i);
      while (s[i] != s[j]) {
        exist[(int)s[i]] = false;
        i++;
      }
      i++;
      j++;
    } else {
      exist[(int)s[j]] = true;
      j++;
    }
  }
  maxlen = max(maxlen, j - i);

  return maxlen;
}

int main()
{
  string s("aadbsddddefgsl");
  int len = lengthOfLongestSubstring(s);
  cout << len << endl;

  return 0;
}
