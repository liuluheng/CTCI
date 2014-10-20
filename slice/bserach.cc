//Example: A sorted array has been rotated so that the elements
//might appear in the order 3 4 5 6 7 1 2.
//How would you find the minimum element?

#include <iostream> 
using namespace std;

int bsearch(int a[], int left, int right) {
  int mid;
  while (left < right) {
    mid = (left + right) >> 1;
    // oh fucking funny add '=' the SECOND test become right...
    // ANALYSIS
    // when right == left + 1, a[left] == a[mid] , this need consider
    // CONCLUDE
    // FIRST consider
    //    a[left] < a[mid]
    // THEN 
    //    a[left] == a[mid]
    // LAST
    //    a[left] > a[mid]
    // for each case 
    //  consider the '<=>' between a[mid] and a[right]
    if (a[left] <= a[mid]) {
      // add if in case the array have not rotate..
      if (a[right] > a[mid])
        return a[left];
      else
        left = mid + 1;
    } else {
      right = mid;
    }
  }

  return a[left];
}

int search(int N[], int n)
{
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    const int mid = (left + right) / 2;
    if (N[mid] > mid)
      right = mid - 1;
    else if (N[mid] < mid)
      left = mid + 1;
    else
      return mid;
  }

  return -1;
}

int search_max(int arr[], int n)
{
  int left = 0;
  int right = n - 1;
  while (left < right) {
    const int mid = (left + right) / 2;
    if (arr[mid] < arr[mid + 1])
      left = mid + 1;
    else
      right = mid;

    //cout << arr[mid] << endl;
  }

  return arr[left];
}

int main() {
  cout << "SEARCH MINIUM IN ROTATE" << endl;
  cout << "---FIRST---" << endl;
  int a[] = {7, 8, 1, 2, 3, 5, 6};
  cout << bsearch(a, 0, sizeof(a)/sizeof(a[0])-1) << endl;
  cout << "---SECOND---" << endl;
  int a2[] = {3, 5, 6, 7, 8, 1, 2};
  cout << bsearch(a2, 0, sizeof(a2)/sizeof(a2[0])-1) << endl;
  cout << "---THIRD---" << endl;
  int a3[] = {2, 3, 5, 6, 7, 8, 1};
  cout << bsearch(a3, 0, sizeof(a3)/sizeof(a3[0])-1) << endl;
  cout << "---FOUR-ARRYAY HAVE NOT ROTATE--" << endl;
  int a4[] = {1, 2, 3, 5, 6, 7, 8};
  cout << bsearch(a4, 0, sizeof(a4)/sizeof(a4[0])-1) << endl;


  cout << endl;
  cout << "SEARCH N[i] == i" << endl;
  cout << "---FIRST EXIST---" << endl;
  int N[] = {-10, -2, 0, 3, 9};
  cout << search(N, sizeof(N)/sizeof(int)) << endl;

  cout << "---SECOND NOT EXIST---" << endl;
  int N2[] = {-10, -2, 0, 2, 9};
  cout << search(N2, sizeof(N2)/sizeof(int)) << endl;

  cout << endl;
  cout << "SEARCH MAX" << endl;
  int arr[] = { 1, 2, 3, 4, 5, 6, 4, 3, 1};
  int max = search_max(arr, sizeof(arr)/sizeof(int));
  cout << max << endl;

  return 0;
}

