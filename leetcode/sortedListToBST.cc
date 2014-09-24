#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct ListNode {
  ListNode(int val = 0, ListNode *next = nullptr)
      : val(val), next(next) {}
  int val;
  ListNode *next;
};

int listLength(ListNode *head)
{
  int n = 0;
  while (head) {
    n++;
    head = head->next;
  }

  return n;
}

ListNode* nth_node(ListNode *node, int n)
{
  while(--n) {
    node = node->next;
  }

  return node;
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val = 0, 
           TreeNode *left = nullptr, TreeNode *right = nullptr) 
      : val(val), left(left), right(right) {}
};

void delete_tree(TreeNode *root)
{
  if (!root) {
    return;
  }
  delete_tree(root->left);
  delete_tree(root->right);
  delete root;
}

TreeNode* sortedListToBST(ListNode *head, int len)
{
  if (len == 0) return nullptr;
  if (len == 1) return new TreeNode(head->val);

  TreeNode *root = new TreeNode(nth_node(head, len/2 + 1)->val);
  root->left = sortedListToBST(head, len/2);
  root->right = sortedListToBST(nth_node(head, len/2 + 2), (len-1)/2);

  return root;
}

TreeNode* sortedListToBST(ListNode *head)
{
  return sortedListToBST(head, listLength(head));
}

TreeNode* sortedListToBST2(ListNode *list, int start, int end)
{
  if (start > end) return nullptr;

  int mid = start + (end - start)/2;
  TreeNode *leftChild = sortedListToBST2(list, start, mid-1);
  TreeNode *parent = new TreeNode(list->val);
  parent->left = leftChild;
  list = list->next;
  parent->right = sortedListToBST2(list, mid+1, end);

  return parent;
}

TreeNode* sortedListToBST2(ListNode *head)
{
  ListNode *p = head;
  int len = 0;
  while (p) {
    len++;
    p = p->next;
  }

  return sortedListToBST2(head, 0, len - 1);
}

void inorder(TreeNode *root)
{
  if (!root)
    return;
  inorder(root->left);
  cout << root->val << endl;
  inorder(root->right);
}

int main()
{
  ListNode *head;
  head = new ListNode(2);
  head = new ListNode(5, head);
  head = new ListNode(2, head);
  head = new ListNode(3, head);
  head = new ListNode(4, head);
  head = new ListNode(1, head);

  TreeNode *root = sortedListToBST2(head);

  inorder(root);
  delete_tree(root);

  return 0;
}
