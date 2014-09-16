//Given a linked list and a value x, partition it such that all nodes less than
//x come before nodes greater
//than or equal to x.
//You should preserve the original relative order of the nodes in each of the
//two partitions.
//For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5
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

listNode* partition(listNode *head, int x) {
  listNode left_dummy(-1);
  listNode right_dummy(-1);

  listNode *left_cur = &left_dummy;
  listNode *right_cur = &right_dummy;

  listNode *head2 = head;
  while (head2) {
    if (head2->data < x) {
      left_cur->next = head2;
      left_cur = head2;
    } else {
      right_cur->next = head2;
      right_cur = head2;
    }
    head2 = head2->next;
  }
  left_cur->next = right_dummy.next;
  right_cur->next = nullptr;

  return left_dummy.next;
}

int main()
{
  listNode *head;
  head = new listNode(2);
  head = new listNode(5, head);
  head = new listNode(2, head);
  head = new listNode(3, head);
  head = new listNode(4, head);
  head = new listNode(1, head);

  listNode *orig = head;
  print(head);

  head = orig;
  listNode *result = partition(head, 3);
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

