/*****************************************************************************
 * File:		main_3_5_1.cpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Tests the Shape Base Class and inheritance after declaring
 *					Shape::ToString() as virtual
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
namespace DLCAD = DavidLeather::CAD;

int main()
{
	DLCAD::Shape s;											// Create shape.
	DLCAD::Point p(10, 20);									// Create point.
	DLCAD::Line l(DLCAD::Point(1, 2), DLCAD::Point(3, 4));	// Create line.

	cout << s.ToString() << endl;							// Print shape.
	cout << p.ToString() << endl;							// Print point.
	cout << l.ToString() << endl;							// Print line

	cout << "Shape ID: " << s.ID() << endl;					// ID of the shape.
	cout << "Point ID: " << p.ID() << endl;					// ID of the point. Does this work? Yes.
	cout << "Line ID: " << l.ID() << endl;					// ID of the line. Does this work? Yes.

	DLCAD::Shape* sp;										// Create pointer to a shape variable.
	sp = &p;												// Point in a shape variable. Possible? Yes.
	cout << sp->ToString() << endl;							// What is printed?
																// Old: "ID: 18467."
																// New: "Point(10, 20)."

	// Create and copy Point p to new point.
	DLCAD::Point p2;
	p2 = p;
	cout << p2 << " " << p2.ID() << endl;	// Is the ID copied if you do not call the base class assignment in point?
												//	No.

	return 0;
}