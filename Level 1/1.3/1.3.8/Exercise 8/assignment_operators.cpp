// Author: David Leather. Date: 01/03/2025
// QuantNet C++ Course 1, Level 1, Section 1.3, Exercise 8

/* Assignment operators */

#include <stdio.h>

int main()
{
	int x = 2;
	int y;
	int z;

	x *= 3 + 2;
	printf("x=%d\n", x); // "x=10"

	x *= y = z = 4;
	printf("x=%d\n", x); // "x=40" but doesn't compile as is
	                     // due to y and z not being initilaized

	x = y == z;
	printf("x=%d\n", x); // "x=1"

	return 0;

}

