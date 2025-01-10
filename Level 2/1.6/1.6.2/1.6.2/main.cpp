/******************************************************
 * File:		main.cpp
 * Author:		David Leather
 * Date:		2025-01-06
 * Purpose:		Computes max(a, b, c) by calling MAX3 macro
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-06 - Initial implementation.
 ******************************************************/

#include <stdio.h>
#include "Defs.h"

int main() {
	// Define a, b, c
	int a = 1;
	int b = 3;
	int c = 2;

	// Calls MAX3 and prints output
	printf("The maximum of %d, %d, and %d is %d.\n", a, b, c, MAX3(a, b, c));

	// Return exit code 0
	return 0;
}