#include <iostream>
//#include <string>
#include <algorithm>
using namespace std;

string addbinary(string &a, string &b)
{
  size_t size = a.size() > b.size() ? a.size() : b.size();
  string result;
  result.reserve(size);

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int carry = 0;
  for (auto itera = a.begin(), iterb = b.begin();
       itera != a.end() || iterb != b.end();
       itera = itera == a.end() ? a.end() : itera + 1,
       iterb = iterb == b.end() ? b.end() : iterb + 1) {
    const int ai = itera == a.end() ? 0 : *itera - '0';
    const int bi = iterb == b.end() ? 0 : *iterb - '0';
    const int val = (ai + bi + carry)%2;
    carry = (ai + bi + carry)/2;
    result.insert(result.begin(),  val + '0');
  }
  if (carry) {
    result.insert(result.begin(), '1');
  }

  return result;
}

int main()
{
  string a = "11";
  string b = "1";
  cout << addbinary(a, b) << endl;

  return 0;
}
