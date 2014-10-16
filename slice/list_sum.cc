#include <iostream>
using namespace std;

struct Node {
  Node(int data = 0)
      : val(data), next(nullptr)
  {}
  int val;
  Node *next;
};

void print(Node *head)
{
  Node *node = head;
  while (node) {
    cout << node->val;
    node = node->next;
  }
  cout << endl;
}

Node* reverse(Node *head)
{
  Node dummy;
  dummy.next = head;
  Node *prev = &dummy;
  Node *cur = head;
  while (cur->next) {
    Node *next = cur->next->next;
    cur->next->next = prev->next;
    prev->next = cur->next;
    cur->next = next;
  }

  return dummy.next;
}

Node* sum(Node *left, Node *right)
{
  Node dummy;
  Node *result = &dummy;
  int c = 0;
  left = reverse(left);
  right = reverse(right);

  while (left && right) {
    int s = left->val + right->val + c;
    Node *node = new Node(s % 10);
    node->next = result->next;
    result->next = node;
    c = s / 10;

    left = left->next;
    right = right->next;
  }

  while (left) {
    int s = left->val + c;
    Node *node = new Node(s / 10);
    node->next = result->next;
    result->next = node;
    c = s % 10;

    left = left->next;
  }
  while (right) {
    int s = right->val + c;
    Node *node = new Node(s / 10);
    node->next = result->next;
    result->next = node;
    c = s % 10;

    right = right->next;
  }

  if (c) {
    Node *node = new Node(c);
    node->next = result->next;
    result->next = node;
  }

  return dummy.next;
}

int main()
{
  Node *left = new Node(2);
  Node *node = new Node(3);
  left->next = node;
  node->next = new Node(4);

  Node *right = new Node(7);
  node = new Node(8);
  right->next = node;
  node->next = new Node(9);

  cout << "sum of ";
  print(left); 
  cout << " and ";
  print(right);
  cout << " is ";

  Node *summ = sum(left, right);
  print(summ);

  return 0;
}
