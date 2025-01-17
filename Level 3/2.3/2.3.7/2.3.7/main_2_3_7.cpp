/******************************************************
 * File:		main_2_3_7.cpp
 * Author:		David Leather
 * Date:		2025-01-13
 * Purpose:		Test program for the point class:
 *					1. Include the point header file
 *					2. Ask the user for x- and y-coordinates using the std::cin
 *						object
 *					3. Then create a Point object using the default constructor
 *					4. Set the coordinates entered by the user.
 *					5. Print the description of the point return by
 *						the ToString() function.
 *					6. Print the point coordinates using the get functions.
 *					7. Print distance to origin
 *					8. Print distance to some randon non-origin point.
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 * Version 1.1: 2025-01-13 - Added Copy constructor and Point(double x, double y)
 * Version 1.2: 2025-01-13 - Changed Distance() function to Pass by Reference
 * Version 1.3: 2025-01-13 - Replace SetX and GetX with just X.
 *								Replace DistanceOrigin with Distance().
 ******************************************************/

// Include the point header file
#include "Point.hpp"
#include <iostream>	// Also include iostream for (2)

int main()
{
	// Initalize x and y local
	double x; double y; std::string desc;

	// Ask for user input of (X, Y)-coordinates
	std::cout << "Enter the X-coordinate: " << std::endl;
	std::cin >> x;
	std::cout << "Enter the Y-coordinate: " << std::endl;
	std::cin >> y;

	// Create Point object
	// Point pnt = Point(x, y);
	Point pnt;

	// Set the X-coordinate
	 pnt.X(x);

	// Set the Y-coordinate
	pnt.Y(y);

	// Print the description returned by ToString;
	desc = pnt.ToString();
	std::cout << desc << std::endl;

	// Print the print coordinates using the getter functions
	std::cout << "Point(" << pnt.X() << ", " << pnt.Y() << ")" << std::endl;
	
	// Print the distance to origin.
	std::cout << "Distance to origin: " << pnt.Distance() << "." << std::endl;

	// Print the distance to a random point.
	Point new_pnt = Point(3.0, 0.14);			// Initialize new Point object
	// new_pnt.SetX(3.0); new_pnt.SetY(0.14);	// Set to (3.0, 0.14)
	std::cout << "Distance to (3.0, 0.14): " << pnt.Distance(new_pnt) << ".";
	std::cout << std::endl;

	// Create a const point. Did I get a compile error? Yes!
	const Point cp(1.5, 3.9);
	// cp.X(0.3);
	std::cout << cp.X() << std::endl;

	// Return exit code 0
	return 0;
}