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

template<typename BidiIt>
TreeNode* buildTree(BidiIt in_first, BidiIt in_last,
                    BidiIt post_first, BidiIt post_last) {
  if (in_first ==in_last) return nullptr;
  if (post_first == post_last) return nullptr;
  const auto val = *prev(post_last);
  TreeNode* root = new TreeNode(val);
  auto in_root_pos = find(in_first, in_last, val);
  auto left_size = distance(in_first, in_root_pos);
  auto post_left_last = next(post_first, left_size);
  root->left = buildTree(in_first, in_root_pos, 
                         post_first, post_left_last);
  root->right = buildTree(next(in_root_pos), in_last, post_left_last,
                          prev(post_last));
  return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  return buildTree(begin(inorder), end(inorder),
                   begin(postorder), end(postorder));
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
