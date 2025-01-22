/***************************************************************************
 * File:		main_3_5_4.cpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Test draw functionality and Shape ABC functionality.
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
	// Can I create an instance of a Shape class? No!
	// Shape shp;
	// cout << shp.ToString() << endl;

	// Test Point
	Shape* shp1 = new Point;	// Create new point
	shp1->Draw();				// Draw the point
	delete shp1;				// Clear from memory

	// Test Line
	Line* shp2 = new Line;		// Create new line
	shp2->Draw();				// Draw the line
	delete shp2;				// Clear from memory

	// Test Circle
	Circle* shp3 = new Circle;	// Create new line
	shp3->Draw();				// Draw the line
	delete shp3;				// Clear from memory

	return 0;
}