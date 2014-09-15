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

void free_list(listNode *head)
{
  listNode *orig;
  while (head) {
    orig = head;
    head = head->next;
    delete orig;
  }
}

void add_list(listNode *first, listNode *second)
{
  listNode result;
  listNode *res_iter = &result;
  int c = 0;
  for (listNode *pa = first, *pb = second;
       pa != nullptr || pb != nullptr;
       pa = pa == nullptr ? nullptr : pa->next,
       pb = pb == nullptr ? nullptr : pb->next,
       res_iter = res_iter->next) {
    c += pa->data + pb->data;
    res_iter->next = new listNode(c%10);
    c /= 10;
  }
  if (c) {
    res_iter->next = new listNode(c);
  }

  print(result.next);
}

int main()
{
  listNode *head;

  head = new listNode(3);
  head = new listNode(4, head);
  head = new listNode(2, head);
  listNode *first = head;
  print(first);

  head = new listNode(4);
  head = new listNode(6, head);
  head = new listNode(5, head);
  listNode *second = head;
  print(second);

  add_list(first, second);

  free_list(first);
  free_list(second);

  return 0;
}

