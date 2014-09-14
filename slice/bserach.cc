#include <iostream>
#include <algorithm>

using namespace std;

//Example: A sorted array has been rotated so that the elements 
//might appear in the order 3 4 5 6 7 1 2. 
//How would you find the minimum element?

int bsearch(int a[], int left, int right)
{
  int mid;
  while (left < right) {
    mid = (left + right) >> 1;
    //cout << mid << endl;
    if (a[left] < a[mid]) {
      left = mid;
    } else {
      while (a[left] > a[mid]) {
        left++;
      }
      return a[left];
    }
  }

  return -1;
}

int main()
{
  int a[] = {3, 5, 6, 7, 8, 1, 2};

  cout << bsearch(a, 0, sizeof(a)/sizeof(a[0])-1) << endl;

  return 0;
}

