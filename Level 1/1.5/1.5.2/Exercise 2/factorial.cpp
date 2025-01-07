// Author: David Leather. Date: 1/6/2025.
// QuantNet C++ Course 1: Level 1, Section 1.5, Exercise 2
// Computes recursive factorial

#include <stdio.h> // Standard include header file

double factorial(double n)
{
	// Base case: end recursion
	if (n == 0.0)
	{
		return 1.0;
	}
		
	return n * factorial(n - 1); // Recursion
}

int main()
{
	double n; double factorial_n;
	printf("Input a non-negative integer.");
	scanf_s("%lf", &n);

	factorial_n = factorial(n);

	printf("%.0f! is equal to %.0f.\n", n, factorial_n);

	return 0;
}

