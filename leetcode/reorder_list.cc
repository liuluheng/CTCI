//Given a singly linked list L : L0 → L1 → · · · → Ln−1 → Ln , reorder it
//to: L0 → Ln → L1 →
//Ln−1 → L2 → Ln−2 → · · ·
//You must do this in-place without altering the nodes’ values.
//For example, Given {1,2,3,4}, reorder it to {1,4,2,3}.
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

listNode* reverse(listNode *head) {
  if (!head) {
    return nullptr;
  }
  listNode dummy(-1);
  dummy.next = head;

  for (listNode *prev = &dummy, *cur = prev->next;
       cur->next; ) {
    listNode *next = prev->next;
    prev->next = cur->next;
    cur->next = cur->next->next;
    prev->next->next = next;
  }

  return dummy.next;
}

listNode* reorder(listNode *head) {
  if (!head) {
    return nullptr;
  }

  listNode *slow = head;
  listNode *fast = head;
  listNode *prev = nullptr;
  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = nullptr;
  slow = reverse(slow);

  listNode *new_head = head;
  while (new_head && slow) {
    prev = new_head;
    listNode *next = new_head->next;
    new_head->next = slow;
    slow = slow->next;
    new_head->next->next = next;
    new_head = next;
  }
  if (slow) {
    prev->next->next = slow;
  }

  return head;
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
  head = new listNode(6);
  head = new listNode(5, head);
  head = new listNode(4, head);
  head = new listNode(3, head);
  head = new listNode(2, head);
  head = new listNode(1, head);

  print(head);

  listNode *result = reorder(head);
  print(result);
  free_list(result);

  return 0;
}

