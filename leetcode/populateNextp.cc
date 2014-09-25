#include <iostream>

using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root, TreeLinkNode *sibling)
{
  if (!root)
    return;
  else
    root->next = sibling;

  connect(root->left, root->right);
  if (sibling)
    connect(root->right, sibling->left);
  else
    connect(root->right, nullptr);
}

TreeLinkNode* connect(TreeLinkNode *root)
{
  connect(root, nullptr);
  return root;
}

void connect2(TreeLinkNode *root)
{
  if (!root)
    return;

  TreeLinkNode dummy(-1);
  for (TreeLinkNode *cur = root, *prev = &dummy;
       cur; cur = cur->next) {
    if (cur->left) {
      prev->next = cur->left;
      prev = prev->next;
    }
    if (cur->right) {
      prev->next = cur->right;
      prev = prev->next;
    }
  }
  connect(dummy.next);
}

void connect22(TreeLinkNode *root)
{
  while (root) {
    TreeLinkNode *next = nullptr, *prev = nullptr;
    for (; root; root = root->next) {
      if (!next) 
        next = root->left ? root->left : root->right;
      if (root->left) {
        if (prev)
          prev->next = root->left;
        prev = root->left;
      }
      if (root->right) {
        if (prev)
          prev->next = root->right;
        prev = root->right;
      }
    }
    root = next;
  }
}

int main()
{
}
