#include <iostream>
using namespace std;

struct Node {
  Node(int data = 0, 
       Node *left = nullptr,
       Node *right = nullptr) 
      : val(data)
      , left(left)
      , right(right) {
      }
  int val;
  Node *left;
  Node *right;
};

Node* inorder(Node *root, Node *the_node)
{
  static Node *next  = nullptr;
  if (!root)
    return next;

  static bool found = false;
  inorder(root->left, the_node);
  if (found) {
    next = root;
    found = false;
    return next;
  }
  if (root == the_node)
    found = true;
  inorder(root->right, the_node);

  return next;
}

void inorder(Node *root)
{
  if (!root)
    return;
  inorder(root->left);
  cout << root->val << endl;
  inorder(root->right);
}

Node* morrisInorder(Node *root, Node *the_node)
{
  Node *result = nullptr;
  Node *cur = root;
  Node *prev = nullptr;
  while (cur) {
    if (cur->left) {
      prev = cur->left;
      while (prev->right && prev->right != cur)
        prev = prev->right;

      if (prev->right) {
        //cout << cur->val << endl;
        if (cur == the_node) {
          result = cur->right;
        }
        prev->right = nullptr;
        cur = cur->right;
      } else {
        prev->right = cur;
        cur = cur->left;
      }
    } else {
      //cout << cur->val << endl;
      if (cur == the_node) {
        result = cur->right;
      }
      cur = cur->right;
    }
  }

  return result;
}

Node* find_parent(Node *root, Node *the_node)
{
  static Node *parent = nullptr;
  if (!root)
    return parent;

  find_parent(root->left, the_node);
  if (root->left == the_node ||
      root->right == the_node) {
    parent = root;
    return parent;
  }
  find_parent(root->right, the_node);

  return parent;
}

enum Method {
  RECURSIVE,
  MORRIS,
  PARENT
};

Node* find_next(Node *root, Node *the_node, enum Method method)
{
  if (the_node->right) {
    Node *node = the_node->right;
    while (node->left)
      node = node->left;

    return node;
  } else {
    switch (method) {
      case RECURSIVE:
        cout << "----RECURSIVE INORDER----" << endl;
        return inorder(root, the_node);
      case MORRIS:
        cout << "----MORRIS INORDER----" << endl;
        return morrisInorder(root, the_node);
      case PARENT: {
        cout << "----PARENT----" << endl;
        Node *parent = find_parent(root, the_node);
        while (parent && parent->right == the_node) {
          the_node = parent;
          parent = find_parent(root, the_node);
        }

        return parent;
      }
      default:
        return nullptr;
    }
  }
}

int main()
{
  Node *root = new Node(4);
  Node *node = new Node(3);
  root->left = new Node(2, nullptr, node);
  root = new Node(5, root);

  Node *next = find_next(root, node, RECURSIVE);
  if (next)
    cout << next->val << endl;
  next = find_next(root, node, MORRIS);
  if (next)
    cout << next->val << endl;
  next = find_next(root, node, PARENT);
  if (next)
    cout << next->val << endl;

  return 0; 
}
