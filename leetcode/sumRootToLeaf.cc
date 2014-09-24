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

int dfs(TreeNode *root, int sum)
{
  if (!root)
    return 0;

  if (root->left == nullptr && root->right == nullptr)
    return sum * 10 + root->val;

  return dfs(root->left, sum * 10 + root->val)
       + dfs(root->right, sum * 10 + root->val);
}

int sumNumbers(TreeNode *root)
{
  return dfs(root, 0);
}

int main()
{
  TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  TreeNode *right = new TreeNode(3);
  TreeNode *root1 = new TreeNode(1, left, right);

  right = new TreeNode(2, nullptr, new TreeNode(3));
  TreeNode *root = new TreeNode(1, nullptr, right);

  cout << sumNumbers(root1) << endl;
  cout << sumNumbers(root) << endl;

  delete_tree(root1);
  delete_tree(root);
  return 0;
}
