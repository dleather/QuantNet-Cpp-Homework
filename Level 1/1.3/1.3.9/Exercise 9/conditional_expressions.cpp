// Author: David Leather. Date: 01/03/2025
// QuantNet C++ Course 1, Level 1, Section 1.3, Exercise 9

/* Conditional expressions */
#include <stdio.h>

int main()
{
	int x = 1;
	int y = 1;
	int z = 1;

	x += y += x;
	printf("%d\n\n", (x < y) ? y : x);      // Number 1: "3" (followed by extra line brk)
	printf("%d\n", (x < y) ? x++ : y++);    // Number 2: "2"
	printf("%d\n", x);                // Number 3: "3"
	printf("%d\n", y);                // Number 4: "3"

	return 0;
}

