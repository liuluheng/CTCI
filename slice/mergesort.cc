#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v) {
  for (auto i : v)
    cout << i << " ";
  cout << endl;
}

void merge(vector<int>& v, int p, int r) {
  const int mid = (p + r) / 2;
  vector<int> left(v.begin() + p, v.begin() + mid + 1);
  vector<int> right(v.begin() + mid + 1, v.begin() + r + 1);

  auto leftlen = left.size();
  auto rightlen = right.size();
  size_t l = 0, r2 = 0;
  int i = p;
  while (l < leftlen && r2 < rightlen) {
    if (left[l] < right[r2])
      v[i++] = left[l++];
    else
      v[i++] = right[r2++];
  }
  while (l < leftlen) {
    v[i++] = left[l++];
  }
}

void mergesort(vector<int>& v, int p, int r) {
  if (p < r) {
    const int mid = (p + r) / 2;
    mergesort(v, p, mid);
    mergesort(v, mid + 1, r);
    merge(v, p, r);
  }
}

void mergesortIter(vector<int>& v) {
  const auto size = v.size();
  for (size_t gap = 2; gap <= size; gap *= 2) {
    for (size_t i = 0; i < size; i += gap) {
      if (i + gap - 1 < size)
        merge(v, i, i + gap - 1);
      else
        merge(v, i - gap, size - 1);
      // print(v);
    }
  }
}

int main() {
  cout << " ----ODD---- " << endl;
  vector<int> v({3, 5, 8, 10, 2, 44, 33, 58, 22});
  print(v);
  // mergesort(v, 0, v.size() - 1);
  mergesortIter(v);
  print(v);

  cout << " ----EVEN---- " << endl;
  vector<int> v2({3, 5, 8, 10, 2, 44, 58, 22});
  print(v2);
  // mergesort(v, 0, v.size() - 1);
  mergesortIter(v2);
  print(v2);

  return 0;
}
