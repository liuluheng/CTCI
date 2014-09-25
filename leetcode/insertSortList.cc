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

listNode* findpos(listNode *p, listNode *head)
{
  while (head->next) {
    if (head->next->data >= p->data)
      return head;

    head = head->next;
  }
  return head;
}

listNode* insertsort(listNode *list)
{
  listNode dummy(-1);
  dummy.next = list;

  listNode *p = list->next;
  listNode *prev = list;
  while (p) {
    listNode *pos = findpos(p, &dummy);
    prev->next = p->next;
    p->next = pos->next;
    pos->next = p;
    prev = p;
    p = prev->next;
  }

  return dummy.next;
}

int main()
{
  listNode *head;
  head = new listNode(2);
  head = new listNode(3, head);
  head = new listNode(4, head);
  head = new listNode(6, head);
  head = new listNode(1, head);
  head = new listNode(5, head);

  listNode *result = insertsort(head);
  print(result);
  free_list(result);

  //listNode *head2;
  //head2 = new listNode(6);
  //head2 = new listNode(4, head2);
  //head2 = new listNode(2, head2);

  return 0;
}
