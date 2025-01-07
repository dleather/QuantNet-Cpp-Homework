// Author: David Leather. Date: 01/06/2025
// QuantNet C++ Course 1. Level 2. Section 1.6. Exercise 2. 
// Purpose: Calls MAX3 macro

#include <stdio.h>
#include "Defs.h"

int main() {
	int a = 1;
	int b = 3;
	int c = 2;
	printf("The maximum of %d, %d, and %d is %d.\n", a, b, c, MAX3(a, b, c));
	return 0;
}