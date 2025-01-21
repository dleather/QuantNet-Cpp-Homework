/*******************************************************************************
 * File:		main_2_5_1.cpp
 * Author:		David Leather
 * Date:		2025-01-19
 * Purpose:		Test program for the point class:
 *					1. Include the point header file
 *					2. create Point objects on the heap with new using:
 *						2a. the default constructor
 *						2b. constructor with coordinates
 *						2c. the copy constructor.
 *					3. Next call the Distance() function on the pointers and
 *						try to send the Point pointers to cout.
 *					4. Test the main program.
 *					5. Ask the user for the size of the arraya nd read it using cin.
 *					6. Try to create an array on the stack using the entered size.
 *					7. Now create the array on the heap using new.
 *					8. Can you use other constructors than the default
 *						constructor for the objects created in the array?
 * Version: 1.1
 *					
 * Change Log:
 * Version 1.0: 2025-01-18 - Initial implementation.
 * Version 1.1: 2025-01-19 - Dereferenced pointers when sending to cout.
 ******************************************************************************/

// Include the point header file
#include "Point.hpp"
#include <iostream>	

int main()
{
	// Create Point objects on the heap using...
	Point* p1;
	p1 = new Point;				// Default constructor

	Point* p2;
	p2 = new Point(1.0, 2.0);	// Coordinate constructor

	Point* p3;
	p3 = new Point(*p1);		// Copy constructor

	// Call Distance() function on pointers
	double d1 = p1->Distance();
	double d2 = p2->Distance();
	double d3 = p3->Distance();
	std::cout << "The distances are, " << d1 << ", " << d2 << ", and " << d3;
	std::cout << "." << std::endl;

	// Send the pointers to cout
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	std::cout << *p3 << std::endl;

	// Delete
	delete p1; delete p2; delete p3;

	// Ask the user for dimension of array
	unsigned int N;
	std::cout << "Enter the size of the array (positive integer):" << std::endl;
	std::cin >> N;

	// Create an array on the stack using the entered size.
	// Point a1[N];

	// Now create the array on the heap using new.
	Point* a1;							// Default constructor
	a1 = new Point[N];
	std::cout << a1[0] << std::endl;
	delete[] a1;

	// Can I use other constructors? No the default constructor must be used.

	// Return exit code 0
	return 0;
}