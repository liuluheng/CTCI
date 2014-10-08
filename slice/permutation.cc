//Example: Design an algorithm to print all permutations of a string.
//For simplicity, assume all characters are unique.

#include <iostream>
#include <vector>
#include <iterator>  // ostream_iterator
#include <algorithm>

using namespace std;

vector<string> permutation(string &s, size_t n) {
  vector<string> vs;
  if (n == 0) {
    vs.push_back(s.substr(0, 1));
    return vs;
  }

  vector<string> vs2 = permutation(s, n - 1);
  for (auto str : vs2) {
    for (size_t i = 0; i <= str.length(); ++i) {
      //tmp is necessary
      string tmp = str;
      tmp.insert(i, s.substr(n, 1));
      vs.push_back(tmp);
    }
  }

  return vs;
}

int main() {
  string s = "abc";
  vector<string> vs = permutation(s, s.size() - 1);

  copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, "\n"));
  //cout << endl;

  //for_each(vs.begin(), vs.end(), [](string &s) { cout << s << endl;});
  //cout << endl;

  return 0;
}
