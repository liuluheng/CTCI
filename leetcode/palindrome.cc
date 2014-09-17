//Given a string, determine if it is a palindrome, considering only alphanumeric
//characters and ignoring
//cases.
//For example,
//”A man, a plan, a canal: Panama” is a palindrome.
//”race a car” is not a palindrome.
//Note: Have you consider that the string might be empty? This is a good
//question to ask during an
//interview.
//For the purpose of this problem, we define empty string as valid palindrome.
//
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool is_palindrome(string &s)
{
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  auto left = s.begin(), right = s.end();
  while (left < right) {
    if (!::isalnum(*left)) {
      ++left;
    } else if (!::isalnum(*right)) {
      --right;
    } else if (*left != *right) {
      return false;
    } else {
      ++left;
      --right;
    }
  }
  return true;
}

int main()
{
  string s = "A man, a plan, a canal: Panama";
  string s2 = "";
  cout << is_palindrome(s) << endl;
  cout << is_palindrome(s2) << endl;

  return 0;
}
