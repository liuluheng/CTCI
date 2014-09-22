#include <iostream>
#include <algorithm>
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

void zigzagorder(TreeNode *root, size_t level, 
                 vector<vector<int>> &v, bool left_to_right)
{
  if (!root) {
    return;
  }

  if (level > v.size()) {
    v.push_back(vector<int>());
  }

  if (left_to_right) {
    v[level - 1].push_back(root->val);
  } else {
    v[level - 1].insert(v[level-1].begin(), root->val);
  }
  zigzagorder(root->left, level + 1, v, !left_to_right);
  zigzagorder(root->right, level + 1, v, !left_to_right);
}

vector<vector<int>> zigzagorder2(TreeNode *root)
{
  vector<vector<int>> result;
  if (!root) {
    return result;
  }

  queue<TreeNode *> cur, next;
  vector<int> level;
  cur.push(root);

  bool left_to_right = false;
  while (!cur.empty()) {
    left_to_right = !left_to_right;
    while (!cur.empty()) {
      TreeNode *node = cur.front();
      cur.pop();
      if (left_to_right) {
        level.push_back(node->val);
      } else {
        level.insert(level.begin(), node->val);
      }

      if (node->left != nullptr) next.push(node->left);
      if (node->right != nullptr) next.push(node->right);
    }
    result.push_back(level);
    level.clear();
    cur.swap(next);
  }

  return result;
}

vector<vector<int>> zigzagorder3(TreeNode *root)
{
  vector<vector<int>> result;
  if (!root) {
    return result;
  }

  queue<TreeNode *> q;
  vector<int> level;
  q.push(root);
  q.push(nullptr);

  bool left_to_right = true;
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    if (node) {
      level.push_back(node->val);
      if (node->left != nullptr) q.push(node->left);
      if (node->right != nullptr) q.push(node->right);
    } else {
      if (left_to_right) {
        result.push_back(level);
      } else {
        reverse(level.begin(), level.end());
        result.push_back(level);
      }
      left_to_right = !left_to_right;
      level.clear();

      if (q.size() > 0) q.push(nullptr);
    }
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
  zigzagorder(root, 1, v, true);
  print(v);
  v = zigzagorder2(root);
  print(v);
  v = zigzagorder3(root);
  print(v);
  delete_tree(root);

  v.clear();
  right = new TreeNode(2, new TreeNode(3));
  root = new TreeNode(1, nullptr, right);
  zigzagorder(root, 1, v, true);
  print(v);
  delete_tree(root);

  return 0;
}
