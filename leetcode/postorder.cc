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

void postorder(TreeNode *root)
{
  if (!root) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->val << endl;
}

void postorder2(TreeNode *root)
{
  const TreeNode *p = root, *q;
  stack<const TreeNode *> s;

  do {
    while (p != nullptr) { /* 往左下走 */
      s.push(p);
      p = p->left;
    }
    q = nullptr;
    while (!s.empty()) {
      p = s.top();
      s.pop();
      /* 右孩子不存在或已被访问,访问之 */
      if (p->right == q) {
        cout << p->val << endl;
        q = p; /* 保存刚访问过的结点 */
      } else {
        /* 当前结点不能访问,需第二次进栈 */
        s.push(p);
        /* 先处理右子树 */
        p = p->right;
        break;
      }
    }
  } while (!s.empty());
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

  postorder(root);
  postorder2(root);
  delete_tree(root);

  right = new TreeNode(2, new TreeNode(3));
  root = new TreeNode(1, nullptr, right);
  postorder(root);
  postorder2(root);
  delete_tree(root);

  return 0;
}
