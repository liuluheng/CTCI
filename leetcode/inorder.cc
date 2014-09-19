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

void inorder(TreeNode *root)
{
  if (!root) {
    return;
  }
  inorder(root->left);
  cout << root->val << endl;
  inorder(root->right);
}

void inorder2(TreeNode *root)
{
  const TreeNode *p = root;
  stack<const TreeNode *> s;

  while (!s.empty() || p != nullptr) {
    if (p != nullptr) {
      s.push(p);
      p = p->left;
    } else {
      p = s.top();
      s.pop();
      cout << p->val << endl;
      p = p->right;
    }
  }
}

void delete_tree(TreeNode *root)
{
  if (!root) {
    return;
  }
  delete_tree(root->left);
  delete_tree(root->right);
  cout << "delete " << root->val << endl;
  delete root;
}

int main()
{
  TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  TreeNode *right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
  TreeNode *root = new TreeNode(1, left, right);

  //inorder(root);
  inorder2(root);
  delete_tree(root);

  right = new TreeNode(2, new TreeNode(3));
  root = new TreeNode(1, nullptr, right);
  //inorder(root);
  inorder2(root);
  delete_tree(root);

  return 0;
}
