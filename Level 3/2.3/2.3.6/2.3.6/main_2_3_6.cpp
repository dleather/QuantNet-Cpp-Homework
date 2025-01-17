/******************************************************
 * File:		main_2_3_6.cpp
 * Author:		David Leather
 * Date:		2025-01-13
 * Purpose:		Tests Circle.hpp class
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 ******************************************************/

#include "Circle.hpp"
#include <iostream>
#include <string>

int main()
{
	// Construct a default circle
	Circle circ = Circle();

	// Print description of the default circle.
	std::cout << "Default circle description: " << std::endl;
	std::string default_desc = circ.ToString();
	std::cout << default_desc << std::endl;

	// Get a non-default circle
	Circle nd_circ = Circle(Point(-1.0, 2.0), 6.0);

	// Print description of the non-default circle.
	std::cout << "Non-default circle description: " << std::endl;
	std::string nd_default_desc = nd_circ.ToString();
	std::cout << nd_default_desc << std::endl;


	// Return exit code 0
	return 0;
}