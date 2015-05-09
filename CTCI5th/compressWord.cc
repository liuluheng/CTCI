#include <iostream>

using namespace std;

string itoa(int count)
{
  string s;
  while (count) {
    int m = count % 10;
    s.insert(s.begin(), m + '0');
    count /= 10;
  }

  return s;
}

int compressCount(const string &s)
{
  char c = s[0];
  int count = 1;
  int size = 0; // size start from 0
  // i start form 1, s[0] is used
  for (size_t i = 1; i < s.size(); i++) {
    if (s[i] == c) {
      count++;
    } else {
      size += 1 + itoa(count).size();
      c = s[i];
      count = 1;
    }
  }
  size += 1 + itoa(count).size();

  return size;
}

int compressWord(string &s)
{
  if (s.empty()) {
    return 0;
  }

  size_t size = compressCount(s);
  if (size >= s.size())
    return size;

  string result;
  int count = 1;
  char c = s[0];
  result.push_back(c);
  for (size_t i = 1; i < s.size(); i++) {
    if (s[i] == c) {
      count++;
    } else {
      result.append(itoa(count));
      c = s[i];
      result.push_back(c);
      count = 1;
    }
  }
  result.append(itoa(count));

  s.swap(result);
  return size;
}

int main()
{
  string s("aabbbccaaaaaaaaaaaaaaaaaaaaaaa");

  cout << s << endl;
  cout << compressWord(s) << endl;
  cout << s << endl;

  cout << endl;

  string s2("abcd");
  cout << s2 << endl;
  cout << compressWord(s2) << endl;
  cout << s2 << endl;

  string s3("");
  cout << s3 << endl;
  cout << compressWord(s3) << endl;
  cout << s3 << endl;
}
