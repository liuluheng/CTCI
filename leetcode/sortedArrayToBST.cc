#include <iostream>
#include <vector>
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

template<typename RandomAccessIterator>
TreeNode* sortedArrayToBST(RandomAccessIterator begin,
                           RandomAccessIterator end)
{
  const auto length = distance(begin, end);
  if (length <= 0) return nullptr;

  auto mid = begin + length/2;
  TreeNode *root = new TreeNode(*mid);
  root->left = sortedArrayToBST(begin, mid);
  root->right = sortedArrayToBST(mid + 1, end);

  return root;
}

TreeNode* sortedArrayToBST(vector<int>& num)
{
  return sortedArrayToBST(num.begin(), num.end());
}

void inorder(TreeNode *root)
{
  if (!root)
    return;
  inorder(root->left);
  cout << root->val << endl;
  inorder(root->right);
}

int main()
{
  vector<int> vec;
  for (int i = 0; i < 10; ++i)
    vec.push_back(i);

  TreeNode *root = sortedArrayToBST(vec);

  inorder(root);
  delete_tree(root);

  return 0;
}
