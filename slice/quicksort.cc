#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print(vector<int> &v)
{
  for (auto i : v)
    cout << i << " ";
  cout << endl;
}

int partition2(vector<int> &v, int left, int right)
{
  const int pivot = v[(left + right) / 2];

  while (left <= right) {
    while (v[left] < pivot)
      left++;

    while (v[right] > pivot)
      right--;
    
    if (left <= right) {
      swap(v[left++], v[right--]);
    }
  }

  // print(v);
  return left;
}

void quicksort2(vector<int> &v, int start, int end)
{
  stack<int> s;
  s.push(start); s.push(end);
  while (!s.empty()) {
    end = s.top(); s.pop();
    start = s.top(); s.pop();
    if (start < end) {
      int q = partition2(v, start, end);
      s.push(start); s.push(q - 1); // q - 1 !!!
      s.push(q); // q !!!
      s.push(end);
    }
  }
}

int partition_baidu(vector<int> &v, int j, int r)
{
  int i = j - 1;
  int pivot = v[r];
  int right = r - 1;
  while (i < right) { // < not <=
    if (v[j] < pivot)
      swap(v[++i], v[j++]);
    else
      swap(v[j], v[right--]); // not j++
  }
  swap(v[++i], v[r]); // ++i!!

  return i;
}

int partition_startAsPivot(vector<int> &v, int start, int end)
{
  int pivot = v[start];
  int boundry = start;

  for (int i = start + 1; i <= end; i++) {
    if (v[i] < pivot)
      swap(v[++boundry], v[i]);
  }
  swap(v[boundry], v[start]);

  //print(v);
  // return ++boundry; 也可以，boundry is at the right position,
  // its left < boundry and right > boundry;
  return boundry;
}

int partition_endAsPivot(vector<int> &v, int start, int end)
{
  int pivot = v[end];
  int boundry = start - 1;

  for (int i = start; i < end; i++) {
    if (v[i] < pivot)
      swap(v[++boundry], v[i]);
  }
  swap(v[++boundry], v[end]);

  // print(v);
  return boundry;
}

void quicksort(vector<int> &v, int start, int end)
{
  stack<int> s;
  s.push(start); s.push(end);
  while (!s.empty()) {
    end = s.top(); s.pop();
    start = s.top(); s.pop();
    if (start < end) {
      //int q = partition(v, start, end);
      int q = partition_startAsPivot(v, start, end);
      s.push(start); s.push(q - 1); // q - 1 !!
      s.push(q + 1); // q !!!
      s.push(end);
    }
  }
}

int main()
{
  vector<int> v({3, 5, 8 , 10, 2, 44, 33, 58, 22});
  print(v);
  quicksort(v, 0, v.size() - 1);
  print(v);

  return 0;
}
