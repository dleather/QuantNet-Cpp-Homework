/***************************************************************************
 * File:		main_3_5_3.cpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Test the virtual destructor.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-21 - Initial implementation.
 *****************************************************************************/

// Header files
#include "DavidLeather.hpp"
#include <iostream>

using namespace std;
using namespace DavidLeather::CAD;

int main()
{
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;

	for (int i = 0; i != 3; i++) delete shapes[i];

	return 0;
}