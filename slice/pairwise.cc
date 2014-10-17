#include <iostream>
#include <cstring>
using namespace std;

int pairwise(char *source, int p)
{
  if (*(source + p) == '{') {
    int nl = 0;
    char *left = strchr(source + p + 1, '{');
    if (left) {
      char *prev = left;
      while (left != nullptr) {
        nl++;
        prev = left;
        left = strchr(left + 1, '{');
      }

      char *right = prev;
      while (nl--) {
        prev = right;
        right = strchr(prev + 1, '}');

        if (!right)
          return -1;
      }

      right = strchr(right + 1, '}');
      return right - source;
    }

    char *right = strchr(source + p + 1, '}');
    return right - source;
  }

#if 0
  if (*(source + p) == '}') {
    int nr = 0;
    while (p-- && *(source + p) != '}');
    char *right = source + p;

    char *prev = right;
    while (right != source) {
      nr++;
      prev = right;
      right = strchr(right + 1, '}');
      while (p-- && *(source + p) != '}');
      right = source + p;
    }

    char *left = prev;
    while (nr--) {
      prev = left;
      left = strchr(prev + 1, '{');

      if (!left)
        return -1;
    }

    left = strchr(prev + 1, '{');

    return left - source;
  }
#endif

  return -1;
}

int main()
{
  //               012345678901
  char source[] = "  {{{{{}}}}} ";
  auto len = pairwise(source, 4);
  cout << len << endl;
  len = pairwise(source, 2);
  cout << len << endl;
  len = pairwise(source, 3);
  cout << len << endl;
  len = pairwise(source, 5);
  cout << len << endl;
  len = pairwise(source, 6);
  cout << len << endl;

  return 0;
}
