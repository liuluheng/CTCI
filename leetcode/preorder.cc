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

void preorder(TreeNode *root)
{
  if (!root) {
    return;
  }
  cout << root->val << endl;
  preorder(root->left);
  preorder(root->right);
}

void preorder2(TreeNode *root)
{
  const TreeNode *p;
  stack<const TreeNode *> s;
  p = root;
  if (p != nullptr) {
    s.push(p);
  }
  while (!s.empty()) {
    p = s.top();
    s.pop();
    cout << p->val << endl;

    if (p->right != nullptr) s.push(p->right);
    if (p->left != nullptr) s.push(p->left);
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

  //preorder(root);
  preorder2(root);
  delete_tree(root);

  right = new TreeNode(2, new TreeNode(3));
  root = new TreeNode(1, nullptr, right);
  preorder(root);
  preorder2(root);
  delete_tree(root);

  return 0;
}
