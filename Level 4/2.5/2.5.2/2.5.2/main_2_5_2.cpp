/*******************************************************************************
 * File:		main_2_5_2.cpp
 * Author:		David Leather
 * Date:		2025-01-18
 * Purpose:		Creating Array of Pointers
 *					1. Create an array of Point pointers with 3 elements on the
 *						heap
 *					2. Create for each element in the array a point on the heap.
 *					3. Iterate the array and print each point in the array.
 *					4. Iterate the array again and delete each point in the array
 *					5. Delete the array itself
 *					
 * Change Log:
 * Version 1.0: 2025-01-18 - Initial implementation.
 ******************************************************************************/

// Include the point header file
#include "Point.hpp"
#include <iostream>	

const int ARRAY_SIZE = 3;			// Declare global constant for size of array

int main()
{
	// Create a 3-dimensional array of Point pointers on the heap
	Point** pnt_array;						// Pointer to array of pointers
	pnt_array = new Point * [ARRAY_SIZE];	// Initalize array of pointers

	// Create for each element in the array a point on the heap
	pnt_array[0] = new Point(1.0, 1.0);
	pnt_array[1] = new Point(2.0, 2.0);
	pnt_array[2] = new Point(3.0, 3.0);

	// Iterate the array and print each point in the array
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		std::cout << *pnt_array[i] << std::endl;
	}

	// Iterate the array and delete each objecty
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		delete pnt_array[i];
	}

	// Delete the array itself
	delete[] pnt_array;

	// Return exit code 0
	return 0;
}