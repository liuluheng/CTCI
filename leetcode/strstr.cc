#include <iostream>
using namespace std;

char *strStr(const char *haystack, const char *needle)
{
  const char *p_advance = haystack;
  for (const char *p1 = needle + 1; *p1; p1++, p_advance++)

  for (const char *p = haystack; *p_advance; p_advance++) {
    const char *p_old = p;
    const char *needle2 = needle;
    while (*p && *needle2 && *p == *needle2) {
      p++; needle2++;
    }
    if (!*needle2) {
      return (char *)p_old;
    }
    
    p = p_old + 1;
  }

  return nullptr;
}

int main()
{
  char a[] = "hello";
  char b[] = ", shhelloit";

  cout << strStr(b, a) << endl;

  return 0;
}
