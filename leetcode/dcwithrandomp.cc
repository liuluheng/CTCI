//A linked list is given such that each node contains an additional random
//pointer which could point to
//any node in the list or null.
//Return a deep copy of the list.
//

#include <iostream>

using namespace std;

struct listNode {
  listNode(int data = 0, listNode *next = nullptr) 
      : data(data), next(next) {}
  int data;
  listNode *next;
  listNode *random;
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

listNode* deepcopy(listNode *head) {
  if (head == nullptr) 
    return head;

  listNode dummy(-1);
  dummy.next = head;

  return dummy.next;
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
  head = new listNode(8);
  head = new listNode(7, head);
  head = new listNode(6, head);
  head = new listNode(5, head);
  head = new listNode(4, head);
  head = new listNode(3, head);
  head = new listNode(2, head);
  head = new listNode(1, head);

  listNode *orig = head;
  head = orig;

  print(head);
  listNode *result = deepcopy(head);
  print(result);

  // free
  head = orig;
  while (head) {
    orig = head;
    head = head->next;
    delete orig;
  }

  return 0;
}

