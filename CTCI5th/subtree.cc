
struct Node {
  Node (int data = 0) : data_(data) {}
  int data_;
  Node *left_;
  Node *right_;
};

bool match(Node *n1, Node *n2)
{
  if (!n1 && !n2) {
    return true;
  } else if (!n1 || !n2) {
    return false;
  } else if (n1->data_ != n2->data_) {
    return false;
  } else {
    return match(n1->left_, n2->left_) &&
           match(n1->right_, n2->right_);
  }
}

bool subtree(Node *n1, Node *n2)
{
  if (!n1 && !n2) {
    return true;
  } else if (!n1 || !n2) {
    return false;
  } else if (n1->data_ != n2->data_) {
    return subtree(n1->left_, n2) ||
           subtree(n1->right_, n2);
  } else {
    return match(n1, n2);
  }
}

int main()
{
}

