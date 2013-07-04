/*    
    TESTS FOR: Basic character operations

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

#include "../basics/string_ops.c"

int main(int argc, char **argv)
{
  // test isUpper
  assert( isUpper("A") );
  assert( isUpper("Z") );
  assert(! isUpper("a") );
  assert( isUpper("1") );

  // test isLower
  assert( isLower("a") );
  assert( isLower("z") );
  assert(! isLower("A") );
  assert(! isLower("Z") );

  // test isNumeric
  assert( isNumeric("1") );
  assert(! isNumeric("a") );

  // test isCharacter
  assert( isCharacter("a") );
  assert( isCharacter("z") );
  assert( isCharacter("A") );
  assert( isCharacter("Z") );
  assert(! isCharacter("1") );
  assert(! isCharacter("!") );

  // test isAlpha
  assert( isAlpha("a") );
  assert( isAlpha("A") );
  assert( isAlpha("z") );
  assert( isAlpha("Z") );
  assert( isAlpha("0") );
  assert( isAlpha("9") );

  // test toUpper
  char aSmall = 'a';

  toUpper(&aSmall);
  assert( aSmall == 'A' );

  // test toLower
  toLower(&aSmall);
  assert( aSmall == 'a' );

  // test swapCase
  swapCase(&aSmall);
  assert( aSmall == 'A' );
  swapCase(&aSmall);
  assert( aSmall == 'a' );

  return 0;
}
