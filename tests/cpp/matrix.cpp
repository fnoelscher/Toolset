#include "../../basics/matrix/matrix.hpp"

int main(int argc, char **argv)
{
  Matrix<int> m(16,16);

  // assign values
  m[0][2] = 23;

  return 0;
}


