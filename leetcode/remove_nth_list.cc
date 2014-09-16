//Given a linked list, remove the nth node from the end of list and return its
//head.
//For example, Given linked list: 1->2->3->4->5, and n = 2.
//After removing the second node from the end, the linked list becomes
//1->2->3->5.
//Note:
//• Given n will always be valid.
//• Try to do this in one pass.
//

#include <iostream>

using namespace std;

struct listNode {
  listNode(int data = 0, listNode *next = nullptr) 
      : data(data), next(next) {}
  int data;
  listNode *next;
};

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

listNode* remove_nth(listNode *head, int n)
{
  listNode dummy(-1);
  dummy.next = head;

  listNode *p = &dummy;
  listNode *q = &dummy;
  for (int i = 0; i < n; i++) {
    p = p->next;
  }
  while (p->next) {
    p = p->next;
    q = q->next;
  }

  listNode *tmp = q->next;
  q->next = q->next->next;
  delete tmp;

  return dummy.next;
}

int main()
{
  listNode *head;
  //Given 1->2->3->3->4->4->5, return 1->2->3->3->4->5.
  head = new listNode(5);
  head = new listNode(4, head);
  head = new listNode(4, head);
  head = new listNode(3, head);
  head = new listNode(3, head);
  head = new listNode(2, head);
  head = new listNode(1, head);

  print(head);

  listNode *result = remove_nth(head, 3);
  print(result);
  free_list(result);

  return 0;
}

