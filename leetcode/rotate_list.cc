//Given a list, rotate the list to the right by k places, where k is
//non-negative.
//For example: Given 1->2->3->4->5->nullptr and k = 2, return
//4->5->1->2->3->nullptr.
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

listNode* rotate(listNode *head, int k)
{
  if (!head || !k) {
    return head;
  }
  listNode *p = head;
  int len = 1;
  while (p->next) {
    len++;
    p = p->next;
  }
  k = len - k%len;
  p->next = head;

  for (int step = 0; step < k; step++) {
    p = p->next;
  }
  head = p->next;
  p->next = nullptr;

  return head;
}

int main()
{
  listNode *head;
  //Given 1->2->3->3->4->4->5, return 1->2->5.
  head = new listNode(5);
  head = new listNode(4, head);
  head = new listNode(4, head);
  head = new listNode(3, head);
  head = new listNode(3, head);
  head = new listNode(2, head);
  head = new listNode(1, head);

  print(head);

  listNode *result = rotate(head, 3);
  print(result);
  free_list(result);

  return 0;
}

