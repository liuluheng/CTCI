//Given a sorted linked list, delete all duplicates such that each element
//appear only once.
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.
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
  while (head) {
    cout << head->data;
    head = head->next;
  }
  cout << endl;
}

void recur(listNode *prev, listNode *cur)
{
  //key
  if (cur == nullptr) return;

  if (prev->data == cur->data) {
    prev->next = cur->next;
    delete cur;
    recur(prev, prev->next);
  } else {
    recur(prev->next, cur->next);
  }
}

listNode* removedup_recur(listNode *head) {
  if (!head) {
    return nullptr;
  }
  listNode dummy(-1);
  dummy.next = head;

  listNode *prev = &dummy;
  listNode *cur = prev->next;
  recur(prev, cur);

  return dummy.next;
}

listNode* removedup(listNode *head) {
  if (!head) {
    return nullptr;
  }

  for (listNode *prev = head, *cur = head->next;
       cur;) {
    if (prev->data == cur->data) {
      prev->next = cur->next;
      delete cur;
      cur = prev->next;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }

  return head;
}

int main()
{
  listNode *head;
  head = new listNode(3);
  head = new listNode(3, head);
  head = new listNode(2, head);
  head = new listNode(2, head);
  head = new listNode(1, head);
  head = new listNode(1, head);

  listNode *orig = head;
  print(head);

  head = orig;
  listNode *result = removedup_recur(head);
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

