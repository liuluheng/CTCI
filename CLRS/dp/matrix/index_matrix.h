#pragma once
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

class IndexMatrix {
  public:
    IndexMatrix(int length);
    ~IndexMatrix(void);
    const int &operator() (int i, int j) const;
    int &operator() (int i, int j);
    void print();

  private:
     IndexMatrix(void);
     boost::numeric::ublas::matrix<int> m;
};
