#include "index_matrix.h"
#include <iostream>
#include <iomanip>

IndexMatrix::IndexMatrix(void)
{
}

IndexMatrix::IndexMatrix(int length):m(length, length)
{
    for (int i = 0; i < m.size1(); i++)
        for (int j = 0; j < m.size2(); j++)
            m(i, j) = 0;
}

IndexMatrix::~IndexMatrix(void)
{
}

const int &IndexMatrix::operator() (int i, int j) const {
    return m(i - 1, j - 1);
} 

int &IndexMatrix::operator() (int i, int j)
{
    return m(i - 1, j - 1);
}

void IndexMatrix::print()
{
    for (int i = 0; i < m.size1(); i++) {
        for (int j = 0; j < m.size2(); j++)
            std::cout << std::setw(7) << m(i, j) << " ";
        std::cout << "\n";
    }
}
