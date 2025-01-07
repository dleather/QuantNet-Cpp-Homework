// Author: David Leather. Date: 1/3/2025.
// QuantNet C++ Course 1: Level 1, Section 1.3, Exercise 6
// Shifts input 2 digits to right, and declares type of shift used.

#include <stdio.h> // Set header for "stdio"

int main()
{
	// Declare variable
	int i, original_sign, new_sign, logical_used;

	// Ask user to enter an integer
	printf("Enter an integer.\n");
	scanf_s("%d", &i);
	printf("Inputted integer is: %d.\n", i);

	// Get original sign (1 for positive, 0 for neg)
	original_sign = (i >= 0) ? 1 : 0;

	// Shift 2 digits to right
	i >>= 2;
	printf("The 2-shifted integer is %d.\n", i);

	// Get new sign (1 for positive, 0 for neg)
	new_sign = (i >= 0) ? 1 : 0;

	// Output whether logical or arithmetic shift was used
	if (original_sign)
	{
		printf("Shift type used: Logical (positive integer inputted).\n");
	}
	else
	{
		if (original_sign == new_sign)
		{
			printf("Shift type used: Airthmetic (negative int inputted, no sign switch)\n");
		}
		else
		{
			printf("Shift type used: Airthmetic (negative integer inputted, sign switch)\n");
		}
	}

	return 0;
}