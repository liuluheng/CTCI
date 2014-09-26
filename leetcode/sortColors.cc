#include <iostream>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

void sortColors(int A[], int n)
{
  int count[3] = { 0 };

  for (int i = 0; i < n; i++) {
    count[A[i]]++;
  }
  
  for (int i = 0, index = 0; i < 3; i++) {
    for (int j = 0; j < count[i]; j++) {
      A[index++] = i;
    }
  }

  return;
}

void sortColors2(int A[], int n)
{
  int red = 0, blue = n - 1;
  for (int i = 0; i < blue + 1;) {
    if (A[i] == 0)
      swap(A[i++], A[red++]);
    else if (A[i] == 2)
      swap(A[i], A[blue--]);
    else
      i++;
  }
}

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator partition2(ForwardIterator first, ForwardIterator last,
                          UnaryPredicate pred) {
  auto pos = first;
  for (; first != last; ++first)
    if (pred(*first))
      swap(*first, *pos++);
  return pos;
}

void sortColors3(int A[], int n)
{
  partition2(partition2(A, A + n, bind(equal_to<int>(), _1, 0)), 
            A + n, bind(equal_to<int>(), _1, 1));
}

int main()
{
  int A[] = {0, 2, 1, 2, 0, 1, 2, 1};
  sortColors3(A, 8);

  for (auto i : A)
    cout << i << " ";
  cout << endl;

  return 0;
}
