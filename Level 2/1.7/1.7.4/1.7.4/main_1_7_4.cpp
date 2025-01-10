/******************************************************
 * File:		main_1_7_4.cpp
 * Author:		David Leather
 * Date:		2025-01-07
 * Purpose:		Given int 1-7, print day Sun - Sat.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-07 - Initial implementation.
 ******************************************************/

#include <stdio.h> // Standard C header

// Declare function DayName()
char* DayName(int i);

// Main Function
int main()
{
	int i;	// Initialize day number

	// Ask for input day number.
	printf("Enter the integer of the day. 1 = Sunday. 7 = Saturday.\n");
	scanf_s("%d", &i);	// Stores input in pointer to i

	// Print day
	printf("Day %d is a %s.\n", i, DayName(i));
	
	// Return 0
	return 0;
}

// Define function DayName()
char* DayName(int i)
{
	// Initialize array of strings related to day
	static const char day_array[7][10] =
	{
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};

	return (char*)day_array[i - 1];
}