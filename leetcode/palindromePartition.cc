#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string &s, size_t start, size_t end)
{
  while (start < end && s[start] == s[end]) {
    start++;
    end--;
  }
  return start >= end;
}

void dfs(string &s, vector<string> &path, vector<vector<string>> &result,
         size_t prev, size_t start)
{
  if (start == s.size()) {
    if (isPalindrome(s, prev, start - 1)) {
      path.push_back(s.substr(prev, start - prev));
      result.push_back(path);
      path.pop_back();
    }
    return;
  }
  dfs(s, path, result, prev, start + 1);
  if (isPalindrome(s, prev, start - 1)) {
    path.push_back(s.substr(prev, start - prev));
    dfs(s, path, result, start, start + 1);
    path.pop_back();
  }
}

vector<vector<string>> partition(string s)
{
  vector<vector<string>> result;
  vector<string> path;
  dfs(s, path, result, 0, 1);
  return result;
}

int main()
{
  auto vv = partition("aab");
  for (auto v : vv) {
    for (auto s : v) {
      cout << s << " ";
    }
    cout << endl;
  }

  return 0;
}
