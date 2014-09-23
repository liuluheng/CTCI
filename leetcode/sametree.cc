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

bool issametree(TreeNode *p, TreeNode *q)
{
  if (!p && !q) return true;
  else if (!p || !q) return false;
  else 
    return p->val == q->val 
        && issametree(p->left, q->left)
        && issametree(p->right, q->right);
}

bool issametree2(TreeNode *p, TreeNode *q)
{
  stack<TreeNode*> s;
  s.push(p);
  s.push(q);

  while (!s.empty()) {
    auto p = s.top(); s.pop();
    auto q = s.top(); s.pop();

    if (!p && !q) continue;
    if (!p || !q) return false;
    if (p->val != q->val) return false;

    s.push(p->left);
    s.push(q->left);

    s.push(p->right);
    s.push(q->right);
  }

  return true;
}

int main()
{
  TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  TreeNode *right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
  TreeNode *root1 = new TreeNode(1, left, right);

  right = new TreeNode(2, new TreeNode(3));
  TreeNode *root = new TreeNode(1, nullptr, right);

  cout << issametree(root, root) << endl;
  cout << issametree2(root, root) << endl;

  cout << issametree(root, root1) << endl;
  cout << issametree2(root, root1) << endl;

  delete_tree(root1);
  delete_tree(root);

  return 0;
}
