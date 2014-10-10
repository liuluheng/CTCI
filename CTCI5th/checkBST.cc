#include <iostream>
#include <climits>
using namespace std;

struct Node {
  Node(int data = 0) : data(data) {}
  int data;
  Node *left;
  Node *right;
};

//preorder...
int last_printed = INT_MIN;
bool checkBST(Node *root)
{
  if (!root)
    return true;

  if (!checkBST(root->left))
    return false;

  if (root->data <= last_printed)
    return false;
  last_printed = root->data;

  if (!checkBST(root->right))
    return false;

  return true;
}

bool checkBST2(Node *root, int min, int max)
{
  if (!root)
    return true;

  if (root->data < min || root->data >= max)
    return false;

  if (!checkBST2(root->left, min, root->data) ||
      !checkBST2(root->right, root->data, max))
    return false;

  return true;
}

bool checkBST2(Node *root)
{
  return checkBST2(root, INT_MIN, INT_MAX);
}

int main()
{
}
