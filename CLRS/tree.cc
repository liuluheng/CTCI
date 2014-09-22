#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *parent;
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

TreeNode* tree_minimum(TreeNode *root)
{
  while (root->left) {
    root = root->left;
  }
  return root;
}

TreeNode* tree_maximum(TreeNode *root)
{
  while (root->right) {
    root = root->right;
  }
  return root;
}

TreeNode* tree_successor(TreeNode *x)
{
  if (x->right) {
    return tree_minimum(x->right);
  }
  TreeNode *p = x->parent;
  while (p && x == p->right) {
    x = p;
    p = x->parent;
  }
  return p;
}

TreeNode* tree_predecessor(TreeNode *x)
{
  if (x->left) {
    return tree_minimum(x->left);
  }
  TreeNode *p = x->parent;
  while (p && x == p->left) {
    x = p;
    p = x->parent;
  }
  return p;
}

int tree_search(TreeNode *root, int k)
{
  if (!root) {
    return 0;
  }

  if (k == root->val) {
    return k;
  }

  if (k < root->val) {
    return tree_search(root->left, k);
  } else {
    //cout << k << " " << root->val << endl;
    return tree_search(root->right, k);
  }
}

void tree_insert(TreeNode *root, TreeNode * z)
{
  TreeNode *x = root;
  TreeNode *y = nullptr;
  while (x) {
    y = x;
    if (z->val < x->val) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (z->val < y->val) {
    y->left = z;
  } else {
    y->right = z;
  }
}

void transplant(TreeNode *u, TreeNode *v)
{
  if (u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;

  v->parent = u->parent;
}

void tree_delete(TreeNode *z)
{
  if (z->left == nullptr)
    transplant(z, z->right);
  else if (z->right == nullptr)
    transplant(z, z->left);
  else {
    TreeNode *y = tree_minimum(z->right);
    if (y->parent != z) {
      transplant(y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    transplant(z, y);
    y->left = z->left;
    y->left->parent = y;
  }

  delete z;
}
    

void print(vector<vector<int>> &v)
{
  for (auto vec : v) {
    for (auto val : vec) {
      cout << val << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void levelorder(TreeNode *root, size_t level, vector<vector<int>> &v)
{
  if (!root) {
    return;
  }

  if (level > v.size()) {
    v.push_back(vector<int>());
  }

  v[level - 1].push_back(root->val);
  levelorder(root->left, level + 1, v);
  levelorder(root->right, level + 1, v);
}

int main()
{
  //TreeNode *left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  //TreeNode *right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
  TreeNode *root = new TreeNode(3);
  tree_insert(root, new TreeNode(1));
  tree_insert(root, new TreeNode(2));
  tree_insert(root, new TreeNode(4));
  tree_insert(root, new TreeNode(5));
  tree_insert(root, new TreeNode(6));

  vector<vector<int>> v;
  levelorder(root, 1, v);
  print(v);
  cout << tree_search(root, 6) << endl;
  //tree_delete(root);
  //cout << tree_search(root, 6) << endl;
  
  delete_tree(root);

  return 0;
}
