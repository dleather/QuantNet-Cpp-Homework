/*****************************************************************************
 * File:		main_2_5_3.cpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Tests the array class
 *
 * Version:		1.1
 *
 * Change Log:
 * Version 1.0: 2025-01-19 - Initial implementation.
 * Version 1.1: 2025-01-21 - Changed GetElement() to const and validated index
 *								greater than or equal to 0.
 *****************************************************************************/

// Header files
#include "Point.hpp"
#include "Array.hpp"
#include <iostream>

int main()
{
	// Test default constructor, Size(), GetElement(), SetElement(), and [].
	Array arr1;
	std::cout << "Size of default constructor is " << arr1.Size();
	std::cout << "." << std::endl;
	std::cout << "First element of default constructor is ";
	std::cout << arr1.GetElement(0) << std::endl;
	std::cout << "Changing first element to (1.0, 2.0)..." << std::endl;
	arr1.SetElement(0, Point(1.0, 2.0));
	std::cout << "The new first element is " << arr1[0] << std::endl;

	//Test constructor with size argument
	Array arr2(20);
	std::cout << "The size of the arr2 is " << arr2.Size() << std::endl;

	// Test the copy constructor
	Array arr3 = arr2;
	std::cout << "The size of the arr3 is " << arr3.Size() << std::endl;

	// Test [] const operator
	const Array arr4(5);
	const Point& p = arr4[0]; // Only reads the element
	std::cout << "No error thrown for [] const operator." << std::endl;

	return 0;
}