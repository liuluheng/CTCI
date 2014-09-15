//Reverse a linked list from position m to n. Do it in-place and in 
//one-pass.
//For example: Given 1->2->3->4->5->nullptr, m = 2 and n = 4,
//return 1->4->3->2->5->nullptr.
//Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ gth 
//length of list.
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

void reverse(listNode *head, int m, int n) {
  listNode dummy(-1);
  dummy.next = head;
  listNode *prev = &dummy;

  for (int i = 0; i < m - 1; i++) {
    prev = prev->next;
  }
  listNode * const head2 = prev;

  prev = head2->next;
  listNode *cur = prev->next;

  for (int i = m; i < n; i++) {
    prev->next = cur->next;
    cur->next = head2->next;
    head2->next = cur;
    cur = prev->next;
  }

  print(head2);
}

int main()
{
  listNode *head;
  head = new listNode(5);
  head = new listNode(4, head);
  head = new listNode(3, head);
  head = new listNode(2, head);
  head = new listNode(1, head);

  listNode *orig = head;
  head = orig;

  print(head);
  reverse(head, 1, 5);

  // free
  head = orig;
  while (head) {
    orig = head;
    head = head->next;
    delete orig;
  }

  return 0;
}

