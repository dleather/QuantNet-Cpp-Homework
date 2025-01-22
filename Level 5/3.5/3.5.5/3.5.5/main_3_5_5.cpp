/***************************************************************************
 * File:		main_3_5_5.cpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Test Print() template of the Shape Base Class.
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

int main() {

	// Initialize a point and a line
	Point pnt(1.0, 2.0);
	Line line(Point(0.0, 0.0), Point(1.0, 3.0));

	// Call Print() function on both
	pnt.Print();	// Output: ID: 41. Point(1, 2).
	line.Print();	// Output: ID: 26500. The line from (0, 0) and (1, 3).

	return 0;

}