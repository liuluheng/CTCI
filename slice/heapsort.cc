#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

template <typename T>
class Heap {
 public:
  Heap() : v(1, INT_MIN), heap_size(0) {}
  Heap(initializer_list<T> il) : v(il), heap_size(0)
  { v.insert(v.begin(), INT_MIN); }

  template <typename RandomAccessIterator>
  void push_heap(RandomAccessIterator first,
                 RandomAccessIterator last);
  void pop_heap();
  void make_heap();
  void sort_heap();

  void print() {
    for (auto i : v)
      cout << i << " ";
    cout << endl;
  }

 private:
  void adjust_heap(int holeIndex);

  int PARENT(int i) {
    return i >> 1;
  }
  int LEFT(int i) {
    return i << 1;
  }
  int RIGHT(int i) {
    return (i << 1) + 1;
  }

  vector<T> v;
  size_t heap_size;
};

template <typename T>
void Heap<T>::adjust_heap(int holeIndex) {
  size_t l = LEFT(holeIndex);
  size_t r = RIGHT(holeIndex);
  int largest = holeIndex;

  if (l <= heap_size && v[l] > v[largest])
    largest = l;

  if (r <= heap_size && v[r] > v[largest])
    largest = r;

  if (largest != holeIndex) {
    swap(v[holeIndex], v[largest]);
    adjust_heap(largest);
  }
}

template <typename T>
void Heap<T>::pop_heap() {
  swap(v[1], v[heap_size]);
  heap_size--;
  adjust_heap(1);
}

template <typename T>
template <typename RandomAccessIterator>
void Heap<T>::push_heap(RandomAccessIterator first,
                        RandomAccessIterator last) {
  T value = *(last - 1);
  auto holeIndex = ++heap_size;
  auto parent = PARENT(holeIndex);

  // the v[parent] < value makes it a max-heap
  while (holeIndex > 1 && v[parent] < value) {
    v[holeIndex] = v[parent];
    holeIndex = parent;
    parent = PARENT(holeIndex);
  }
  v[holeIndex] = value;
}

template <typename T>
void Heap<T>::make_heap() {
  heap_size = v.size() - 1;
  for (int i = heap_size / 2; i > 0; i--) {
    adjust_heap(i);
  }
}

template <typename T>
void Heap<T>::sort_heap() {
  while (heap_size)
    pop_heap();
}

int main()
{
  Heap<int> h({2, 3, 8, 6, 10, 4, 1});
  h.make_heap();
  h.print();
  h.sort_heap();
  h.print();
  //h.push_heap();

  return 0;
}
