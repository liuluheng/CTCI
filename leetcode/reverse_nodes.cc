//Given a linked list, reverse the nodes of a linked list k at a time and 
//return its modified list.
//If the number of nodes is not a multiple of k then left-out nodes in the
//end should remain as it is.
//You may not alter the values in the nodes, only nodes itself may be changed.
//Only constant memory is allowed.
//For example, Given this linked list: 1->2->3->4->5
//For k = 2, you should return: 2->1->4->3->5
//For k = 3, you should return: 3->2->1->4->5
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

listNode* reverse(listNode *head, int k) {
  if (head == nullptr || head->next == nullptr || k < 2) 
    return head;

  listNode dummy(-1);
  dummy.next = head;

  listNode *prev = &dummy;
  listNode *cur = prev->next;

  while (1) {
    int m = 1;
    listNode *p = cur;
    while (p && p->next && m != k) {
      p = p->next;
      m++;
    }
    if (m != k) {
      break;
    }

    for (int i = 0; i < k - 1; i++) {
    //while (prev->next != p) {
      listNode *next = prev->next;
      prev->next = cur->next;
      cur->next = cur->next->next;
      prev->next->next = next;
    }
    prev = cur;
    cur = cur->next;
  }

  return dummy.next;
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
  listNode *result = reverse(head, 3);
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

