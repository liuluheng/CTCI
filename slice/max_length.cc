#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int max_length(vector<int> v)
{
  int min = INT_MAX;
  int len = 1;
  const auto size = v.size();

  for (size_t L = 1; L <= size; L++) {
    for (size_t i = 0; i + L - 1 < size; i++) {
      int sum = 0;
      for (size_t j = i; j < i + L; j++) {
        sum += v[j];
      }
      sum = abs(sum);
      if (sum <= min) {
        min = sum;
        len = L;
      }
    }
  }

  return len;
}

int max_length(const string &key, const string &text)
{
  unordered_map<char, bool> hashtable;
  hashtable.reserve(key.size());
  int start = 0;
  int end = 0;
  for (auto c : key)
    hashtable[c] = true;

  int len = 1;
  const auto size = text.size();

  for (size_t L = 1; L <= size; L++) {
    for (size_t i = 0; i + L - 1 < size; i++) {
      size_t j = i;
      unordered_map<char, bool> visited;
      visited.reserve(L);
      for (; j < i + L; j++) {
        char c = text[j];
        if (!hashtable[c] || visited[c])
          break;

        visited[c] = true;
      }
      if (j == i + L) {
        start = i;
        end = j - 1;
        len = L;
      }
    }
  }

  cout << string(text, start, end) << endl;
  return len;
}

int main()
{
  cout << "---FIRST---" << endl;
  vector<int> v({1, 2, -2, 1, 3, -4});
  int min = max_length(v);
  cout << min << endl;

  cout << "---SECOND---" << endl;
  string key("bcd");
  string text("acbdacbbdb");
  min = max_length(key, text);
  cout << min << endl;

  return 0;
}
