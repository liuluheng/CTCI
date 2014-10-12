#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TrieNode {
  TrieNode(int n = 0) : val(n) {}
  int val;
  vector<TrieNode *> subs;
};

void minM(int n, TrieNode *trieNode)
{
  if (n == 0)
    return;

  for (int i = 2; i <= 9; i++) {
    if (n % i)
      continue;

    TrieNode *tmp = new TrieNode(i);
    trieNode->subs.push_back(tmp);
    minM(n / i, tmp);
  }
}

void pathCombine(TrieNode *root, vector<int> &cur, 
                 vector<vector<int>> &result)
{
  if (!root)
    return;

  cur.push_back(root->val);

  if (!root->subs.empty()) {
    for (auto t : root->subs) {
      pathCombine(t, cur, result);
    }
  } else {
    result.push_back(cur);
  }

  cur.pop_back();
}

int func(int n)
{
  TrieNode *root = new TrieNode();
  minM(n, root);

  vector<int> vm;
  if (!root->subs.empty()) {
    vm.reserve(root->subs.size());

    TrieNode *p = root;

    vector<vector<int>> result;
    vector<int> cur;
    for (auto t : p->subs) {
      pathCombine(t, cur, result);
    }

    int m = 0;
    for (auto v : result) {
      // maybe silly..
      int n2 = 1;
      for (auto i : v) {
        m = m * 10 + i;
        n2 = n2 * i;
      }

      if (n2 != n)
        continue;

      //cout << m << endl;
      //m 至少为两位数
      if ((m / 10) == 0) 
        continue;

      vm.push_back(m);
      sort(vm.begin(), vm.end());
      m = 0;
    }
  }

  if (!vm.empty()) {
    return *vm.begin();
  }  else {
    return -1;
  }
}

int main()
{
  vector<int> vi({36, 100, 24, 33, 56, 55, 255, 200, 355});
  for (auto n : vi) {
    cout << n << ": " << func(n) << endl;
  }

  return 0;
}
