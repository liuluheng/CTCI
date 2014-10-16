#include <iostream>
using namespace std;

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

int main()
{
  int arr[] = { 1, 2, 3, 4, 5, 6, 4, 3, 1};

  int max = search_max(arr, sizeof(arr)/sizeof(int));

  cout << max << endl;
}
