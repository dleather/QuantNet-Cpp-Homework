/******************************************************
 * File:		Macro.c
 * Author:		David Leather
 * Date:		2025-01-06
 * Purpose:		Macro.c defines a and b and calls PRINT1 and PRINT2
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-06 - Initial implementation.
 ******************************************************/

#include "Defs.h"

// Prints a, and then prints a and b.
int main() {
	// Input integers a and b
	double a = 1.0;
	double b = 2.0;

	// Print a
	PRINT1(a);

	// Print a and b
	PRINT2(a, b);


	// Return exit code 0
	return 0;
}