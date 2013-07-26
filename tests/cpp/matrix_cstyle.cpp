/*    
    Basic tests for 2D matrix - not very useful yet

    Copyright (C) 2013  H. F. Noelscher

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <assert.h>

#include "../../basics/matrix/matrix_cstyle.hpp"

int main(int argc, char **argv)
{
  int sizex = 16;
  int sizey = 24;

  CMatrix<int> mat(sizex, sizey);

  for(int i = 0; i < sizey; i++)
    {
      for(int j = 0; j < sizex; j++)
	{
	  mat[i][j] = i * j;
	}
    }

  // mat.print();

  // integrity?
  for(int i = 0; i < sizey; i++)
    {
      for(int j = 0; j < sizex; j++)
	{
	  assert( mat[i][j] == i * j );
	}
    }

  // check square matrix detection
  assert(! mat.isSquareMatrix());

  // check hasSameDimensions
  CMatrix<int> dimtest(2,2);
  assert(! dimtest.hasSameDimensions(mat) );
  assert( mat.hasSameDimensions(mat) );

  // check multiplication
  
  CMatrix<int> first(16,16);
  CMatrix<int> second(16,16);

  first[2][2] = 2;
  second[2][2] = 3;

  // returning multiplication not yet implemented
  // Matrix<int> multiplied = first * second;
  // assert(multiplied[2][2] == 6);
  
  first.multInPlace(second);
  assert( first[2][2] == 6 ); // TBD: extend!

  return 0;
}
