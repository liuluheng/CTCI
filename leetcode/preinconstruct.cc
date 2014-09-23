#include <iostream>
#include <vector>
#include <algorithm>
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

template<typename InputIterator>
TreeNode* buildTree(InputIterator pre_first, InputIterator pre_last,
                    InputIterator in_first, InputIterator in_last) {
  if (pre_first == pre_last) return nullptr;
  if (in_first == in_last) return nullptr;
  auto root = new TreeNode(*pre_first);
  auto inRootPos = find(in_first, in_last, *pre_first);
  auto leftSize = distance(in_first, inRootPos);
  root->left = buildTree(next(pre_first), next(pre_first, leftSize + 1),
                         in_first, next(in_first, leftSize));
  root->right = buildTree(next(pre_first, leftSize + 1), pre_last,
                          next(inRootPos), in_last);
  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  return buildTree(begin(preorder), end(preorder),
                   begin(inorder), end(inorder));
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

  print(root);
  print(root1);

  delete_tree(root1);
  delete_tree(root);

  return 0;
}
