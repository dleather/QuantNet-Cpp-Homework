/******************************************************
 * File:		main_1_7_3.cpp
 * Author:		David Leather
 * Date:		2025-01-07
 * Purpose:		Predict the output.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-07 - Initial implementation.
 ******************************************************/

 /* Predict what will be printed on the screen */

#include <stdio.h>

#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line

// Create and initialize array
int a[] = { 0, 1, 2, 3, 4 };

int main()
{
	int i;
	int* p;

	for (i = 0; i <= 4; i++) PRD(a[i]); // 1
	NL;
	// Output: 01234\n

	for (p = &a[0]; p <= &a[4]; p++) PRD(*p); // 2
	NL;
	NL;
	// Output: 01234\n\n

	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]); // 3
	NL;
	// Output: 01234\n

	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); // 4
	NL;
	NL;
	// Output: 024\n\n

	for (p = a + 4; p >= a; p--) PRD(*p); // 5
	NL;
	// Output: 43210\n

	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]); // 6
	NL;
	// Output: 43210\n

	for (p = a + 4; p >= a; p--) PRD(a[p - a]); // 7
	NL;
	// Output: 43210\n

	return 0;
}

