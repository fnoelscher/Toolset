/*    
    C++ / STL Matrix Class - preferred version

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

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

template <class T>
class Matrix {
 
public:
  Matrix(unsigned int cols,
	 unsigned int rows)
  {
    this->matrix = new std::vector< std::vector<T> >();
  }

  ~Matrix() 
  {
    delete this->matrix;
  }

  std::vector<T>& operator[](unsigned int index)
  {
    return this->matrix[index];
  }

private:
  std::vector< std::vector<T> > *matrix; // 2D - scalable to 3D/4D?

};

#endif
