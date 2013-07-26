/*    
    Runtime-Allocated 2D-Matrix - very basic - not even using stl
       -- this is more c than c++ actually

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


#ifndef MATRIX_CSTYLE_HPP
#define MATRIX_CSTYLE_HPP

#include <stdio.h>     // for printf
#include <stdlib.h>    // for malloc / free
#include <string.h>    // for memset

template <class T>
class CMatrix {

public:
  
  CMatrix(unsigned int cols,
	 unsigned int rows)
  {
    size_t tsize = sizeof(T);

    // allocate one chunk of data -> better memory locality
    this->data = (T*) malloc( rows * cols * tsize);

    // allocate array of pointers, the actual matrix
    this->array = (T**) malloc( rows * sizeof(*array));

    if(! this->data)
      {
	printf("An error occured allocating memory\n");
      }
    if(! this->array)
      {
	printf("An error occured allocating memory (2)\n");
      }

    // zero memory
    memset(this->data, 0, (rows * cols * tsize));    

    // create internal array of pointers
    for(unsigned int i = 0; i < rows; i++)
      {
	this->array[i] = &data[i * cols];
      }

    this->sizey = rows;
    this->sizex = cols;
  }

  ~CMatrix()
  {
    // frees everything - valgrind checked
    free(this->array);
    free(this->data);
  }

  /* --------
    OPERATORS
     --------
  */

  T* operator [](unsigned int index)
  {
    return this->array[index];
  }

  // provides matrix multiplication or dot-product, if sizes are not equal
  // not yet implemented
  CMatrix& operator *(CMatrix &other)
  {
    if(this->hasSameDimensions(other))
      return this->mult(other);
    else
      return this->dotProduct(other);
  }


  /* ---------
    OPERATIONS
     ---------
  */

  CMatrix& mult(CMatrix &other)
  {
    // not yet implemented
    printf("Method 'mult' not yet implemented");
    return other; 
  }

  CMatrix& dotProduct(CMatrix &other)
  {
    // not yet implemented
    printf("Method 'dotProduct' not yet implemented");
    return other;
  }

  // in place-multiplicaton
  void multInPlace(CMatrix &other)
  {
    if(! hasSameDimensions(other))
      return;
    
    for(unsigned int i = 0; i < this->sizey; i++)
      {
	for(unsigned int j = 0; j < this->sizex; j++)
	  {
	    this->array[i][j] *= other[i][j];
	  }
      }
  }

  bool hasSameDimensions(CMatrix &other)
  {  
    unsigned int rsizex = other.getSizeX();
    unsigned int rsizey = other.getSizeY();

    return ( (rsizex == this->sizex) && 
	     (rsizey == this->sizey) );
  }

  bool isSquareMatrix()
  {
    return (sizex == sizey);
  }
  
  void print()
  {
    for(unsigned int i = 0; i < sizey; i++)
      {
	for(unsigned int j = 0; j < sizex; j++)
	  {
	    printf(" %i ", this->array[i][j] );
	  }
	printf("\n");
      }
  }

  /* --------
    ACCESSORS
     --------
  */

  unsigned int getSizeX() { return this->sizex; };
  unsigned int getSizeY() { return this->sizey; };

private:

  T * data;
  T ** array;

  unsigned  int sizex, sizey;
};

#endif
