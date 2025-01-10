/******************************************************
 * File:		main_1_7_1.cpp
 * Author:		David Leather
 * Date:		2025-01-07
 * Purpose:		Create a function Swap() that swaps
 *					inputs i and j.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-07 - Initial implementation.
 ******************************************************/

#include <stdio.h>	// Standard header

// Declare Swap() function
void Swap(int* i, int* j);

// Define Swap() function which swaps values for pointers
//	i and j.
void Swap(int* i, int* j)
{
	int tmp = *i;	// Dereferences and copies *i to tmp
	*i = *j;		// Reassigns the value of *j to *i
	*j = tmp;		// Assigns original value of *i to *j
}

// Main function
int main()
{
	// Initlaize values to switch
	int i = 123;
	int j = 456;

	// Call Swap() on pointers
	Swap(&i, &j);

	// Print values
	printf("New i: %d. New j: %d.", i, j);

	// Return 0
	return 0;
}