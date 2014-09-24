#include <iostream>
#include <vector>
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

int numTrees(int n)
{
  vector<int> f(n + 1, 0);

  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      f[i] += f[j - 1] * f[i - j];
    }
  }

  return f[n];
}

vector<TreeNode *> generate(int start, int end)
{
  vector<TreeNode *> subTree;
  if (start > end) {
    subTree.push_back(nullptr);
    return subTree;
  }

  for (int k = start; k <= end; ++k) {
    vector<TreeNode *> leftSubs = generate(start, k - 1);
    vector<TreeNode *> rightSubs = generate(k + 1, end);
    for (auto i : leftSubs) {
      for (auto j : rightSubs) {
        TreeNode *node = new TreeNode(k);
        node->left = i;
        node->right = j;
        subTree.push_back(node);
      }
    }
  }

  return subTree;
}

vector<TreeNode *> generate(int n)
{
  return generate(1, n);
}

int main()
{
  cout << numTrees(1) << endl;
  cout << numTrees(2) << endl;
  cout << numTrees(3) << endl;


  return 0;
}
