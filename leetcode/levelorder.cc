#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val = 0, 
           TreeNode *left = nullptr, TreeNode *right = nullptr) 
      : val(val), left(left), right(right) {}
};

void levelorder(TreeNode *root, size_t level, vector<vector<int>> &v)
{
  if (!root) {
    return;
  }

  if (level > v.size()) {
    v.push_back(vector<int>());
  }

  v[level - 1].push_back(root->val);
  levelorder(root->left, level + 1, v);
  levelorder(root->right, level + 1, v);
}

vector<vector<int>> levelorder2(TreeNode *root)
{
  vector<vector<int>> result;
  if (!root) {
    return result;
  }

  queue<TreeNode *> cur, next;
  vector<int> level;
  cur.push(root);

  while (!cur.empty()) {
    while (!cur.empty()) {
      TreeNode *node = cur.front();
      cur.pop();
      level.push_back(node->val);
      if (node->left != nullptr) next.push(node->left);
      if (node->right != nullptr) next.push(node->right);
    }
    result.push_back(level);
    level.clear();
    cur.swap(next);
  }

  return result;
}

void delete_tree(TreeNode *root)
{
  if (!root) {
    return;
  }
  delete_tree(root->left);
  delete_tree(root->right);
  //cout << "delete " << root->val << endl;
  delete root;
}

void print(vector<vector<int>> &v)
{
  for (auto vec : v) {
    for (auto val : vec) {
      cout << val << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main()
{
  TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  TreeNode *right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
  TreeNode *root = new TreeNode(1, left, right);

  vector<vector<int>> v;
  levelorder(root, 1, v);
  print(v);
  v = levelorder2(root);
  print(v);
  delete_tree(root);

  v.clear();
  right = new TreeNode(2, new TreeNode(3));
  root = new TreeNode(1, nullptr, right);
  levelorder(root, 1, v);
  print(v);
  delete_tree(root);

  return 0;
}
