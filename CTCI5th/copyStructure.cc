#include <iostream>
#include <map>

using namespace std;

struct Node {
  int data;
  Node *ptr1;
  Node *ptr2;
};

using NodeMap = map<Node *, Node *>;

Node* copy_recursive(Node *cur, NodeMap &nodeMap)
{
  if (cur == nullptr)
    return cur;

  auto iter = nodeMap.find(cur);
  if (iter != nodeMap.end())
    return iter->second;

  Node *node = new Node;
  nodeMap[cur] = node;
  node->ptr1 = copy_recursive(node->ptr1, nodeMap);
  node->ptr2 = copy_recursive(node->ptr2, nodeMap);

  return node;
}

Node* copy_structure(Node *cur)
{
  NodeMap nodeMap;
  return copy_recursive(cur, nodeMap);
}

int main()
{
}
