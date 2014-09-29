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

      cout << "---" << endl;
      for (auto s : path)
        cout << s << " ";
      cout << endl;

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

vector<vector<string>> partition(string &&s)
{
  vector<vector<string>> result;
  vector<string> path;
  dfs(s, path, result, 0, 1);
  return result;
}

void dfs(string &s, vector<string> &path, vector<vector<string>> &result,
         size_t start)
{
  if (start == s.size()) {

      cout << "---" << endl;
      for (auto s : path)
        cout << s << " ";
      cout << endl;

    result.push_back(path);
    return;
  }
  for (size_t i = start; i < s.size(); ++i) {
    if (isPalindrome(s, start, i)) {
      path.push_back(s.substr(start, i - start + 1));
      dfs(s, path, result, i + 1);
      path.pop_back();
    }
  }
}

vector<vector<string>> partition2(string &&s)
{
  vector<vector<string>> result;
  vector<string> path;
  dfs(s, path, result, 0);
  return result;
}

vector<vector<string>> partition3(string &&s)
{
  const int n = s.size();
  bool p[n][n];
  fill_n(&p[0][0], n * n, false);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      p[i][j] = (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]));
    }
  }

  vector<vector<string>> sub_palins[n];
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      if (p[i][j]) {
        const string palindrome = s.substr(i, j - i + 1);
        if (j + 1 < n) {
          for (auto v : sub_palins[j + 1]) {
            v.insert(v.begin(), palindrome);
            sub_palins[i].push_back(v);
          }
        } else {
          sub_palins[i].push_back(vector<string> { palindrome });
        }
      }
    }
  }

  return sub_palins[0];
}

int main()
{
  auto vv = partition3("aab");
  for (auto v : vv) {
    for (auto s : v) {
      cout << s << " ";
    }
    cout << endl;
  }

  return 0;
}
