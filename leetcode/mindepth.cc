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

int minDepth(TreeNode *root, bool hasbrother)
{
  if (!root) return hasbrother ? INT_MAX : 0;

  return 1 + min(minDepth(root->left, root->right != nullptr),
                 minDepth(root->right, root->left != nullptr));
}

int minDepth(TreeNode *root)
{
  return minDepth(root, false);
}

int minDepth2(TreeNode* root) {
  if (root == nullptr)
    return 0;
  int result = INT_MAX;
  stack<pair<TreeNode*, int>> s;
  s.push(make_pair(root, 1));
  while (!s.empty()) {
    auto node = s.top().first;
    auto depth = s.top().second;
    s.pop();
    if (node->left == nullptr && node->right == nullptr)
      result = min(result, depth);
    if (node->left && result > depth) // 深度控制,剪枝
      s.push(make_pair(node->left, depth + 1));
    if (node->right && result > depth) // 深度控制,剪枝
      s.push(make_pair(node->right, depth + 1));
  }
  return result;
}


int main()
{
  TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  TreeNode *right = new TreeNode(3);
  TreeNode *root1 = new TreeNode(1, left, right);

  right = new TreeNode(2, nullptr, new TreeNode(3));
  TreeNode *root = new TreeNode(1, nullptr, right);

  cout << minDepth(root) << endl;
  cout << minDepth(root1) << endl;
  cout << minDepth2(root) << endl;
  cout << minDepth2(root1) << endl;

  delete_tree(root1);
  delete_tree(root);
  return 0;
}
