#include <iostream>
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

int balancedHeight(TreeNode *root)
{
  if (!root) return 0;

  int left = balancedHeight(root->left);
  int right = balancedHeight(root->right);

  if (left < 0 || right < 0 || abs(left - right) > 1) return -1;

  return max(left, right) + 1;
}

bool isBalanced(TreeNode *root)
{
  return balancedHeight(root) >= 0;
}

int main()
{
  TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  TreeNode *right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
  TreeNode *root1 = new TreeNode(1, left, right);

  right = new TreeNode(2, new TreeNode(3));
  TreeNode *root = new TreeNode(1, nullptr, right);

  cout << isBalanced(root) << endl;
  cout << isBalanced(root1) << endl;

  delete_tree(root1);
  delete_tree(root);

  return 0;
}
