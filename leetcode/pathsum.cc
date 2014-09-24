#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val = 0, 
           TreeNode *left = nullptr, TreeNode *right = nullptr) 
      : val(val), left(left), right(right) {}
};

void delete_tree(TreeNode *root)
{
  if (!root) {
    return;
  }
  delete_tree(root->left);
  delete_tree(root->right);
  delete root;
}

bool hasPathSum(TreeNode *root, int sum)
{
  if (!root)
    return false;

  if (root->left == nullptr && root->right == nullptr)
    return root->val == sum;

  return hasPathSum(root->left, sum - root->val)
      || hasPathSum(root->right, sum - root->val);
}

void pathSum(TreeNode *root, int gap, 
             vector<int>& cur, vector<vector<int>>& result)
{
  if (!root) return;

  cur.push_back(root->val);

  if (root->left == nullptr && root->right == nullptr) {
    if (gap == root->val)
      result.push_back(cur);
  }

  pathSum(root->left, gap - root->val, cur, result);
  pathSum(root->right, gap - root->val, cur, result);

  cur.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
  vector<vector<int>> result;
  vector<int> cur;
  pathSum(root, sum, cur, result);
  return result;
}

int main()
{
  TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  TreeNode *right = new TreeNode(3);
  TreeNode *root1 = new TreeNode(1, left, right);

  right = new TreeNode(2, nullptr, new TreeNode(3));
  TreeNode *root = new TreeNode(1, nullptr, right);

  cout << hasPathSum(root, 2) << endl;
  cout << hasPathSum(root1, 7) << endl;

  auto vv = pathSum(root1, 7);
  for (auto v : vv) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }

  delete_tree(root1);
  delete_tree(root);
  return 0;
}
