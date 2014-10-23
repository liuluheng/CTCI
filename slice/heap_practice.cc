// longtu bishiti(10.20)
// 设计数据结构，保存列表(整数与其频率）
// 整数集合数据流，数据流不断写入的任意时刻,可以做到
// 1）确认频率最高的整数
// 2）能将这个整数很快从列表中移除。
// 
// Thus the children of the node at position n would be at 
// positions 2n and 2n+1 in a one-based array, (parents of n is at n / 2)
// or 2n+1 and 2n+2 in a zero-based array. (parents of n is at (n - 1) / 2)
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
  Record(int key, int count = 0) : key(key), count(count) {}
  // for heap
  bool operator< (const Record rhs) { return count < rhs.count; }
  // not used
  bool operator==(const Record rhs) { return key == rhs.key; }
  // for find
  bool operator==(const int key_to_find) { return key == key_to_find; }
  int key;
  int count;
};
ostream& operator<<(ostream &os, const Record &record)
{
  os << record.key << " : " << record.count;
  return os;
}

class Records {
 public:
  // Time Complexity O(n)
  void insert(int key) {
    //time consuming
    auto iter = find(vr.begin(), vr.end(), key);
    if (iter != vr.end()) {
      iter->count++;
      // O(n)
      //make_heap(vr.begin(), vr.end());
      // O(log(n)) now
      push_heap(vr.begin(), iter + 1);
    } else {
      vr.push_back(Record(key, 1));
      // O(log(n))
      push_heap(vr.begin(), vr.end());
    }
  }

  // O(log(n))
  Record extractMax() {
    pop_heap(vr.begin(), vr.end());
    auto maxRecord = vr.back();
    vr.pop_back();
    return maxRecord;
  }

  void print() {
    cout << "key : count" << endl;
    for (auto record : vr)
      cout << record << endl;
  }

 private:
  vector<Record> vr;
};

int main()
{
  vector<int> dataSet({2, 3, 4, 2, 3, 2});
  Records records;

  for (auto key : dataSet) {
    records.insert(key);
  }
  records.print();

  cout << "extractMax" << endl;
  cout << records.extractMax() << endl;

  records.print();
  
  return 0;
}
