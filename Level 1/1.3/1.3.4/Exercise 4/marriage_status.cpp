// Author: David Leather. Date: 1/3/2025.
// QuantNet C++ Course 1: Level 1, Section 1.3, Exercise 4
// Uses tertiary operator and a single print statement to reveal marriage status

#include <stdio.h>

int main()
{
	// Declare variables
	int married;

	// Have the user enter 0 if are not married.
	printf("Enter 1 if you're married, or 0 if you are not.");
	scanf_s("%d", &married);

	// Set output string
	printf(married ? "The user is married.\n" : "The user is NOT married.\n");

	return 0;
}