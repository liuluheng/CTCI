#include <iostream>
#include <vector>
#include <fstream>
#include "matrix_chain_order.h"

using namespace std;

int main()
{
  vector<int>p;
  ifstream cin("matrix.in");
  int num;
  cin >> num;
  int single;
  for (int i = 0; i < num; i++) {
    cin >> single;
    p.push_back(single);
  }
  MatrixChainOrder matrixChain(p);
  matrixChain.doDP();
  cout << " print the m:\n";
  matrixChain.m.print();
  cout << " print the s:\n";
  matrixChain.s.print();
  cout << " print the result:\n";
  matrixChain.outputFinalResult(cout);

  return 0;
}
