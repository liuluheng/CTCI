#include <iostream>
#include <stack>
#include <vector>
#include <functional>
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

// 逆转路径
static void reverse(TreeNode *from, TreeNode *to) {
  TreeNode *x = from, *y = from->right, *z;
  if (from == to) return;
  while (x != to) {
    z = y->right;
    y->right = x;
    x = y;
    y = z;
  }
}

// 访问逆转后的路径上的所有结点
static void visit_reverse(TreeNode* from, TreeNode *to,
                          std::function< void(const TreeNode*) >& visit) {
  TreeNode *p = to;
  reverse(from, to);
  while (true) {
    visit(p);
    if (p == from)
      break;
    p = p->right;
  }
  reverse(to, from);
}

vector<int> postorderTraversal(TreeNode *root) {
  vector<int> result;
  TreeNode dummy(-1);
  TreeNode *cur, *prev = nullptr;
  std::function < void(const TreeNode*)> visit =
      [&result](const TreeNode *node){
        result.push_back(node->val);
      };
  dummy.left = root;
  cur = &dummy;
  while (cur != nullptr) {
    if (cur->left == nullptr) {
      prev = cur; /* 必须要有 */
      cur = cur->right;
    } else {
      TreeNode *node = cur->left;
      while (node->right != nullptr && node->right != cur)
        node = node->right;
      if (node->right == nullptr) { /* 还没线索化,则建立线索 */
        node->right = cur;
        prev = cur; /* 必须要有 */
        cur = cur->left;
      } else { /* 已经线索化,则访问节点,并删除线索 */
        visit_reverse(cur->left, prev, visit);
        prev->right = nullptr;
        prev = cur; /* 必须要有 */
        cur = cur->right;
      }
    }
  }
  return result;
}

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
  auto vec = postorderTraversal(root);

  for (auto i : vec)
    cout << i << " " ;
  cout << endl;

  delete_tree(root);

  return 0;
}
