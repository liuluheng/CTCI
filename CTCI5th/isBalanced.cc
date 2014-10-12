#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val = 0,
           TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

// not efficient version
int getHeight(TreeNode *root)
{
  if (!root)
    return 0;

  return max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{
  if (!root)
    return true;

  int heightDiff = getHeight(root->left) - getHeight(root->right);
  if (abs(heightDiff) > 1)
    return false;
  else
    return isBalanced(root->left) && isBalanced(root->right);
}

// more efficient one
int checkHeight(TreeNode *root)
{
  if (!root)
    return 0;

  int leftHeight = checkHeight(root->left);
  if (leftHeight == -1)
    return -1;
  
  int rightHeight = checkHeight(root->right);
  if (rightHeight == -1)
    return -1;

  int heightDiff = leftHeight - rightHeight;
  if (abs(heightDiff) > 1)
    return -1;
  else 
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
}
