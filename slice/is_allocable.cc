#include <iostream>
#include <queue>
using namespace std;

bool is_allocable(queue<int> &disk, queue<int> &partition)
{
  while (!partition.empty()) {
    int part = partition.front();
    partition.pop();
    while (!disk.empty()) {
      int capacity = disk.front();
      if (capacity >= part) {
        disk.front() -= part;
        break;
      } else {
        disk.pop();
      }
    }
    if (disk.empty())
      return false;
  }

  return true;
}

int main()
{
  queue<int> disk({120, 120, 120});
  queue<int> partition({60, 60, 80, 20, 80});
  cout << is_allocable(disk, partition) << endl;
  queue<int> partition2({60, 80, 80, 20, 80});
  cout << is_allocable(disk, partition2) << endl;

  return 0;
}

