#include <iostream>
using namespace std;

struct listNode {
  listNode(int data = 0, listNode *next = nullptr) 
      : data(data), next(next) {}
  int data;
  listNode *next;
};

listNode* merge(listNode *a, listNode *b)
{
  listNode dummy(-1);
  listNode *p = &dummy;

  while (a && b) {
    if (a->data < b->data) {
      p->next = a;
      a = a->next;
    } else {
      p->next = b;
      b = b->next;
    }
    p = p->next;
  }

  p->next = a != nullptr ? a : b;

  return dummy.next;
}

void print(listNode *head)
{
  listNode *head2 = head;
  while (head2) {
    cout << head2->data;
    head2 = head2->next;
  }
  cout << endl;
}

void free_list(listNode *head)
{
  listNode *orig;
  while (head) {
    orig = head;
    head = head->next;
    delete orig;
  }
}

int main()
{
  listNode *head;
  head = new listNode(5);
  head = new listNode(3, head);
  head = new listNode(1, head);

  listNode *head2;
  head2 = new listNode(6);
  head2 = new listNode(4, head2);
  head2 = new listNode(2, head2);

  listNode *result = merge(head, head2);
  print(result);
  free_list(result);

  return 0;
}
