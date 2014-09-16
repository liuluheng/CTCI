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

listNode* add_list(listNode *first, listNode *second)
{
  listNode result;
  listNode *res_iter = &result;
  int c = 0;
  for (listNode *pa = first, *pb = second;
       pa != nullptr || pb != nullptr;
       pa = pa == nullptr ? nullptr : pa->next,
       pb = pb == nullptr ? nullptr : pb->next,
       res_iter = res_iter->next) {
    const int ai = pa == nullptr ? 0 : pa->data;
    const int bi = pb == nullptr ? 0 : pb->data;
    c += ai + bi;
    res_iter->next = new listNode(c%10);
    c /= 10;
  }
  if (c) {
    res_iter->next = new listNode(c);
  }

  return result.next;
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

  listNode *sum = add_list(first, second);
  print(sum);

  free_list(first);
  free_list(second);

  return 0;
}

