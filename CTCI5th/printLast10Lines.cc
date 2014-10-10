#include <iostream>
#include <fstream>
using namespace std;

void printLast10Lines()
{
  static const int K = 10;
  string buf[K];
  ifstream file("./compressWord.cc");
  int line = 0;

  while (file.good()) {
    getline(file, buf[line++ % K]);
  }

  int start = line > K ? line % K : 0;
  int count = min(K, line);

  for (int i = 0; i < count; i++) {
    cout << buf[(start + i) % K] << endl;
  }
}

int main()
{
  printLast10Lines();
}
