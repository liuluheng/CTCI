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

int main()
{
}
