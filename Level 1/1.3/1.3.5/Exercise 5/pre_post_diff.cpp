// Author: David Leather. Date: 1/3/2025.
// QuantNet C++ Course 1: Level 1, Section 1.3, Exercise 5
// Exemplifies difference between prefix and postfix -- operator

#include <stdio.h> // Load "stdio" header file

int main()
{
	// Declare variable
	int i = 5;

	// Print starting value
	printf("The starting value of i is: %d.\n", i);

	// Show prefix -- will print the new value of i.
	printf("--i subtracts by 1 first and then evaluates to i - 1: %d.\n", --i);

	// Reset i
	i = 5;
	printf("i has been reset to it's original value: %d\n", i);

	// Show that post -- will print the old value of i
	printf("However, i-- evaluates first and then sets i to i - 1: %d.\n", i--);
	printf("The new value of i is now: %d.\n", i);

	return 0;
}