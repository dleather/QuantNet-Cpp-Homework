/******************************************************
 * File:		main_2_2_1.cpp
 * Author:		David Leather
 * Date:		2025-01-13
 * Purpose:		Test program for the point class:
 *					1. Include the point header file
 *					2. Ask the user for x- and y-coordinates using the std::cin
 *						object
 *					3. Then create a Point object using the default constructor
 *					4. Set the coordinates entered by the user.
 *					5. Print the description of the point return by
						the ToString() function.
					6. Print the point coordinates using the get functions.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
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
	Point pnt;

	// Set the X-coordinate
	pnt.SetX(x);

	// Set the Y-coordinate
	pnt.SetY(y);

	// Print the description returned by ToString;
	desc = pnt.ToString();
	std::cout << desc << std::endl;

	// Print the print coordinates using the getter functions
	std::cout << "Point(" << pnt.GetX() << ", " << pnt.GetY() << ")" << std::endl;
	
	// Return exit code 0
	return 0;
}
