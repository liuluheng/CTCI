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
    if (index > SIZE)
      index -= GAP;
    count[index]++;
  }
  for (int i = 1; i < SIZE; i++) {
    count[i] += count[i - 1];
    cout << count[i] << ", ";
  }
  cout << endl;


  string result;
  result.reserve(s.size());

  //for (auto c : s) {
  for (auto riter = s.rbegin(); riter != s.rend(); ++riter) {
    int index = *riter - 'A';
    if (index > SIZE)
      index -= GAP;
    //cout << *riter;
    result[count[index]] = *riter;
    count[index]--;
  }

  cout << result << endl;
  return result;
}

int main()
{
  string s("RBBbWWBRBw");
  countsort(s);

  return 0;
}
