/*****************************************************************************
 * File:		main_2_6_1.cpp
 * Author:		David Leather
 * Date:		2025-01-19
 * Purpose:		Tests the DavidLeather namespace/
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-19 - Initial implementation.
 *****************************************************************************/

// Header files
#include "DavidLeather.hpp"
#include <iostream>

using namespace std;

int main()
{
	// The full namespace for point.
	DavidLeather::CAD::Point pnt(1.0, 2.0);
	cout << pnt << endl;

	// Declaration for using a single class (Line)
	using DavidLeather::CAD::Line;
	cout << Line(pnt, DavidLeather::CAD::Point(1.0, 5.0)) << endl;

	// Decrlation for a complete namespace Constainers
	using namespace DavidLeather::Containers;
	Array a1;
	cout << "The first element of the array is " << a1[0] << endl;

	namespace DLCAD = DavidLeather::CAD;
	DLCAD::Circle circ;
	cout << circ << endl;

	return 0;
}