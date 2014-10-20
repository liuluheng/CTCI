//美团校招2015 哈尔滨(2)
//有一组随机排列的字母数组，请编写一个时间复杂度为O(n)的算法，使得这些字母从小到大顺序排好。
//说明：字母区分大小写，相同的字母，排序后小写排在大写前。
//例如：R,B,B,b,W,W,B,R,B,w
//排序后：b,B,B,B,B,R,R,w,W,W
//1)描写思路（2分）
//2）请用你熟悉的编程语言编写代码实现（8分）
#include <iostream>
#include <cstring>
using namespace std;

string countsort(string &s)
{
  const int SIZE = 26;
  const int GAP = 32;
  int count[SIZE];
  memset(count, 0, sizeof(count));
  for (auto c : s) {
    int index = c - 'A';
    // when c is lowerletter count its number to the upper too
    if (index > SIZE)
      index -= GAP;
    count[index]++;
  }
  for (int i = 1; i < SIZE; i++) {
    count[i] += count[i - 1];
  }

  string result;
  result.reserve(s.size());

  for (auto riter = s.rbegin(); riter != s.rend(); ++riter) {
    int index = *riter - 'A';
    // when c is lowerletter, put it to the (index - 1)'s count pos..
    // great!!
    if (index > SIZE) {
      index -= GAP;
      result[count[index - 1]] = *riter;
      continue;
    }
    result[count[index] - 1] = *riter;
    count[index]--;
  }

  return result;
}

int main()
{
  string s("RBBbWWBRBw");
  cout << s << endl;
  string result = countsort(s);

  cout << result.data() << endl;

  return 0;
}
