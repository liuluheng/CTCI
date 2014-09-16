//Given a sorted linked list, delete all nodes that have duplicate numbers,
//leaving only distinct numbers
//from the original list.
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.
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

listNode* removedup_recur(listNode *head) {
  if (!head || !head->next) {
    return head;
  }

  listNode *p = head->next;
  if (head->data == p->data) {
    while (p && p->data == head->data) {
      listNode *tmp = p;
      p = p->next;
      delete tmp;
    }
    delete head;
    return removedup_recur(p);
  } else {
    head->next = removedup_recur(head->next);
    return head;
  }
}

listNode* removedup(listNode *head) {
  if (!head) {
    return nullptr;
  }

  listNode dummy(-1);
  dummy.next = head;

  bool dup = false;
  for (listNode *prev = &dummy, *cur = prev->next;
       cur;) {
    while (cur->next && cur->data == cur->next->data) {
      dup = true;
      listNode *tmp = cur->next;
      delete cur;
      cur = tmp;
    } 
    if (dup) {
      dup = false;
      prev->next = cur->next;
      delete cur;
      cur = prev->next;
      continue;
    }
    prev = cur;
    cur = cur->next;
  }

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
  //Given 1->2->3->3->4->4->5, return 1->2->5.
  head = new listNode(5);
  head = new listNode(4, head);
  head = new listNode(4, head);
  head = new listNode(3, head);
  head = new listNode(3, head);
  head = new listNode(2, head);
  head = new listNode(1, head);

  print(head);

  listNode *result = removedup_recur(head);
  print(result);
  free_list(result);

  //
  //Given 1->1->1->2->3, return 2->3.
  head = new listNode(3);
  head = new listNode(2, head);
  head = new listNode(1, head);
  head = new listNode(1, head);
  head = new listNode(1, head);

  print(head);

  result = removedup_recur(head);
  print(result);
  free_list(result);

  return 0;
}

