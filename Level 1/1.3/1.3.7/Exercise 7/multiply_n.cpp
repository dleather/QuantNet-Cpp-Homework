// Author: David Leather. Date: 1/3/2025.
// QuantNet C++ Course 1: Level 1, Section 1.3, Exercise 8
// Computes x * 2^n 

#include <stdio.h> // Include "stdio" header file

int main()
{
	// Declare variables
	unsigned int n;
	signed int x;

	// Input x - number to multipl
	printf("Input an integer to be multiplied, x.\n");
	scanf_s("%d", &x);

	// Input n - integer to raise to power of n
	printf("Input a non-negative integer exponent, n.\n");
	scanf_s("%d", &n);

	// Print result
	printf("x * 2^n is: %d.\n", x << n);

	return 0;
}