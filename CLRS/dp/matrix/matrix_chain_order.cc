#include "matrix_chain_order.h"

#define MAX 0x0fffffff

using namespace std;
MatrixChainOrder::MatrixChainOrder(vector<int> inputp)
:m(inputp.size() - 1), 
    s(inputp.size() - 1), 
    matrixSizeSequence(inputp.begin(), inputp.end())
{
  n = matrixSizeSequence.size() - 1;
}

MatrixChainOrder::~MatrixChainOrder(void)
{
}

void MatrixChainOrder::doDP()
{
  for (int i = 1; i <= n; i++) {
    m(i, i) = 0;
  }
  for (int l = 2; l <= n; l++)
    for (int i = 1; i <= n - l + 1; i++) {
      int j = l + i - 1;
      m(i, j) = MAX;
      for (int k = i; k < j; k++) {
        int current = m(i, k) + m(k + 1, j) +
            +matrixSizeSequence[i - 1] * +matrixSizeSequence[j] * matrixSizeSequence[k];
        if (m(i, j) > current) {
          m(i, j) = current;
          s(i, j) = k;
        }
      }
    }
}

void MatrixChainOrder::outputFinalResult(std::ostream & out)
{
  RecursiceOutput(out, 1, n);
}

void MatrixChainOrder::RecursiceOutput(ostream & out, int begin, int end)
{
  if (begin == end) {
    out << "A" << begin;
  } else {
    out << "( ";
    RecursiceOutput(out, begin, s(begin, end));
    RecursiceOutput(out, s(begin, end) + 1, end);
    out << " )";
  }
}
