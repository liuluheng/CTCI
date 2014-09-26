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

listNode* merge(listNode *l1, listNode *l2)
{
  listNode dummy(-1);
  listNode *p = &dummy;
  while (l1 && l2) {
    if (l1->data < l2->data) {
      p->next = l1;
      l1 = l1->next;
    } else {
      p->next = l2;
      l2 = l2->next;
    }
    p = p->next;
  }
  p->next = l1 ? l1 : l2;

  return dummy.next;
}

listNode* sortList(listNode *head)
{
  if (!head || !head->next)
    return head;

  listNode *fast, *slow;
  fast = head;
  slow = head;
  while (fast && fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }

  fast = slow->next;
  slow->next = nullptr;
  slow = head;

  listNode *l1 = sortList(slow);
  listNode *l2 = sortList(fast);

  return merge(l1, l2);
}

int main()
{
  listNode *head;
  head = new listNode(2);
  head = new listNode(3, head);
  head = new listNode(4, head);
  head = new listNode(6, head);
  head = new listNode(7, head);
  head = new listNode(1, head);
  head = new listNode(5, head);

  listNode *result = sortList(head);
  print(result);
  free_list(result);

  //listNode *head2;
  //head2 = new listNode(6);
  //head2 = new listNode(4, head2);
  //head2 = new listNode(2, head2);

  return 0;
}
