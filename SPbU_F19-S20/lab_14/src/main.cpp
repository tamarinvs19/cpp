#include <iostream>
#include "matrix.h"

int main()
{
    matrix::Matrix m(2, 3);
    std::cout << m;
    m.load("matr");
    std::cout << m;
    return 0;
}
