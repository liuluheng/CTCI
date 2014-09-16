//Given a linked list, swap every two adjacent nodes and return its head.
//For example, Given 1->2->3->4, you should return the list as 2->1->4->3.
//Your algorithm should use only constant space. You may not modify the values
//in the list, only nodes
//itself can be changed.
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

listNode* swap_adjacent2(listNode *head)
{
  listNode *p = head;

  while (p && p->next) {
    swap(p->data, p->next->data);
    p = p->next->next;
  }

  return head;
}

listNode* swap_adjacent(listNode *head)
{
  listNode dummy(-1);
  dummy.next = head;

  for (listNode *prev = &dummy, *cur = prev->next, *next = cur->next;
       next;
       cur = cur->next, next = cur ? cur->next : nullptr) {
    prev->next = next;
    cur->next = next->next;
    next->next = cur;
    prev = cur;
  }

  return dummy.next;
}

int main()
{
  listNode *head;
  head = new listNode(5);
  head = new listNode(4, head);
  head = new listNode(3, head);
  head = new listNode(2, head);
  head = new listNode(1, head);

  print(head);

  listNode *result = swap_adjacent2(head);
  print(result);
  result = swap_adjacent(result);
  print(result);
  result = swap_adjacent2(result);
  print(result);
  free_list(result);

  return 0;
}

