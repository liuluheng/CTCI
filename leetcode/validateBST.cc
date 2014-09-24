#include <iostream>
#include <vector>
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
  //cout << "delete " << root->val << endl;
  delete root;
}

bool validate(TreeNode *root, int lower, int upper)
{
  if (!root) return true;

  return root->val > lower && root->val < upper
      && validate(root->left, lower, root->val)
      && validate(root->right, root->val, upper);
}

bool validate(TreeNode *root)
{
  return validate(root, INT_MIN, INT_MAX);
}

int main()
{
  TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  TreeNode *right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
  TreeNode *root1 = new TreeNode(1, left, right);

  right = new TreeNode(2, nullptr, new TreeNode(3));
  TreeNode *root = new TreeNode(1, nullptr, right);

  cout << validate(root1) << endl;
  cout << validate(root) << endl;

  delete_tree(root1);
  delete_tree(root);
  return 0;
}
