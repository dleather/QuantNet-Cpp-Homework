// Author: David Leather. Date: 1/6/2025.
// QuantNet C++ Course 1: Level 1, Section 1.5, Exercise 4
// Define and calls printnumber(), which prints a number recursively using putchar()
#include <stdio.h>

int printnumber(int n)
{
	// Handle case of negative numbers
	if (n < 0) // If negative...
	{
		putchar('-'); // Print negative sign
		n = -n; // Switch sign of n
	}

	// Base case: n/10 != 0
	if (n / 10 != 0)
	{
		printnumber(n / 10); // add to stack
	}
	
	putchar('0' + (n % 10)); // Print last digit

	return 0;

}

int main()
{
	// Set number
	int n = -6001;

	printnumber(n); // Call recursive function

	return 0;

}