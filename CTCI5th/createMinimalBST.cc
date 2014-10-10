#include <iostream>
using namespace std;

struct Node {
  Node(int data = 0) : data(data) {}
  int data;
  Node *left;
  Node *right;
};

Node* createMinimalBST(int array[], int start, int end)
{
  if (end < start)
    return nullptr;

  const int mid = (start + end)/2;

  Node *node = new Node(array[mid]);
  node->left = createMinimalBST(array, start, mid - 1);
  node->right = createMinimalBST(array, mid + 1, end);

  return node;
}

void midTraversal(Node *root)
{
  if (!root)
    return;

  midTraversal(root->left);
  cout << root->data << " ";
  midTraversal(root->right);
}

int main()
{
  int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Node *root = createMinimalBST(array, 0, 9);
  midTraversal(root);
  cout << endl;
}
