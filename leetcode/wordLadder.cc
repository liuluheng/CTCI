#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int ladderLength(string &start, string &end, unordered_set<string> &dict)
{
  queue<string> cur, next;
  unordered_set<string> visited;
  bool found = false;
  int level = 0;

  auto state_is_target = [&](const string &s) { return s == end; };
  auto state_extend = [&](const string &s) {
    //cout << "------" << s << endl;
    vector<string> result;
    for (size_t i = 0; i < s.size(); ++i) {
      string new_word(s);
      for (char c = 'a'; c <= 'z'; c++) {
        if (c == new_word[i])
          continue;
        swap(c, new_word[i]);
        if ((dict.count(new_word) > 0 || state_is_target(new_word))
            && visited.count(new_word) == 0) {
          result.push_back(new_word);
          visited.insert(new_word);
        }
        swap(c, new_word[i]);
      }
    }
    //for (auto s : result) {
    //  cout << s << endl;
    //}
    return result;
  };

  cur.push(start);
  while (!cur.empty() && !found) {
    level++;
    while (!cur.empty() && !found) {
      const string str = cur.front();
      cur.pop();
      const auto &states = state_extend(str);
      for (auto state : states) {
        next.push(state);
        if (state_is_target(state)) {
          found = true;
          break;
        }
      }
    }
    cur.swap(next);
  }

  if (found)
    return level + 1;
  else
    return 0;
}

void gen_path(unordered_map<string, vector<string>> &father,
              vector<string> &path, string &start, string &word,
              vector<vector<string>> &result)
{
  path.push_back(word);
  if (word == start) {
    result.push_back(path);
    reverse(result.back().begin(), result.back().end());
  } else {
    for (auto &f : father[word]) {
      gen_path(father, path, start, f, result); 
    }
  }
  path.pop_back();
}

vector<vector<string>> findLadders(string &start, string &end,
                                   unordered_set<string> &dict)
{
  unordered_set<string> cur, next;
  unordered_set<string> visited;
  unordered_map<string, vector<string>> father;
  bool found = false;

  auto state_is_target = [&](const string &s) { return s == end; };
  auto state_extend = [&](const string &s) {
    vector<string> result;
    for (size_t i = 0; i < s.size(); ++i) {
      string new_word(s);
      for (char c = 'a'; c <= 'z'; c++) {
        if (c == new_word[i])
          continue;
        swap(c, new_word[i]);
        if ((dict.count(new_word) > 0 || state_is_target(new_word))
            && visited.count(new_word) == 0) {
          result.push_back(new_word);
          //visited.insert(new_word);
        }
        swap(c, new_word[i]);
      }
    }
    return result;
  };

  cur.insert(start);
  // "&& !found" ???
  while (!cur.empty() /*&& !found*/) {
    for (const auto &word : cur)
      visited.insert(word);
    for (const auto &word : cur) {
      const auto &states = state_extend(word);
      for (auto state : states) {
        next.insert(state);
        father[state].push_back(word);
        if (state_is_target(state)) {
          found = true;
        }
      }
    }

    cur.clear();
    cur.swap(next);
  }

  vector<vector<string>> result;
  if (found) {
    vector<string> path;
    gen_path(father, path, start, end, result);
  }
  return result;
}

int main()
{
  unordered_set<string> dict{"hot","dot","dog","lot","log"};

  string start = "hit";
  string end = "cog";
  cout << ladderLength(start, end, dict) << endl;

  const auto result = findLadders(start, end, dict);
  for (auto v : result) {
    for (auto s : v)
      cout << s << (s == v.back() ? "" : "->");
    cout << endl;
  }

  return 0;
}
