/******************************************************
 * File:		main_2_3_5.cpp
 * Author:		David Leather
 * Date:		2025-01-13
 * Purpose:		Tests the Line.hpp class
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 ******************************************************/

#include "Line.hpp"
#include "Point.hpp"
#include <string>
#include <iostream>


int main()
{
	// Define Point 1: (1.0, 2.0)
	Point pnt1(1.0, 2.0);

	// Define Point 2: (1.0, 3.0)
	Point pnt2(1.0, 3.0);

	// Create line object
	Line line(pnt1, pnt2);

	// Get description
	std::string desc = line.ToString();
	std::cout << desc << std::endl;

	// Get length of line;
	double length = line.Length();
	std::cout << "The length of the line is " << length << "." << std::endl;

	return 0;
}


