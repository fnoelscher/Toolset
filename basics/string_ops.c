/*    
    Basic character operations

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

#include "cdecls.c"

bool isUpper(char *c)
{
  return *c < 91;
}

bool isLower(char *c)
{
  return *c > 91;
}

bool isNumeric(char *c)
{
  return ( (*c > 47) && (*c < 58) );
}

bool isCharacter(char *c)
{
  return ( ((*c > 64) && (*c < 91)) ||
	   ((*c > 96) && (*c < 123)) ); // tbc
}

bool isAlpha(char *c)
{
  return ( isNumeric(c) || isCharacter(c) );
}

void toUpper(char *c)
{
  *c &= ~0x20;
}

void toLower(char *c)
{
  *c |= 0x20;
}

void swapCase(char *c)
{
  *c ^= 0x20;
}
