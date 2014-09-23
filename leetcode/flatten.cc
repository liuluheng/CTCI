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

void flatten(TreeNode *root)
{
  if (!root) return;

  flatten(root->left);
  flatten(root->right);

  if (root->left == nullptr) return;

  TreeNode *p = root->left;
  while (p->right)
    p = p->right;

  p->right = root->right;
  root->right = root->left;
  root->left = nullptr;
}


TreeNode* flatten2(TreeNode *root, TreeNode *tail)
{
  if (!root) return tail;

  root->right = flatten2(root->left, flatten2(root->right, tail));
  root->left = nullptr;

  return root;
}

TreeNode* flatten2(TreeNode *root)
{
  return flatten2(root, nullptr);
}

void flatten3(TreeNode *root)
{
  if (!root) return;
  stack<TreeNode *> s;
  s.push(root);

  while (!s.empty()) {
    auto p = s.top();
    s.pop();

    if (p->left)
      s.push(p->left);
    if (p->right)
      s.push(p->right);

    p->left = nullptr;
    if (!s.empty())
      p->right = s.top();
  }
}

void print(TreeNode *p)
{
  while (p) {
    cout << p->val << " ";
    p = p->right;
  }
  cout << endl;
}

int main()
{
  TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  TreeNode *right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
  TreeNode *root1 = new TreeNode(1, left, right);

  right = new TreeNode(2, new TreeNode(3));
  TreeNode *root = new TreeNode(1, nullptr, right);

  flatten3(root);
  flatten3(root1);
  print(root);
  print(root1);

  delete_tree(root1);
  delete_tree(root);

  return 0;
}
