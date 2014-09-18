#pragma once
#include "index_matrix.h"
#include <vector>
#include <iostream>
class MatrixChainOrder {
 public:
  MatrixChainOrder(std::vector<int> inputp);
  ~MatrixChainOrder(void);

  void doDP();
  void outputFinalResult(std::ostream & out);
  void RecursiceOutput(std::ostream & out, int begin, int end);

  IndexMatrix m, s;

 private:
  MatrixChainOrder(void);
  int n;
  std::vector<int> matrixSizeSequence;
};
