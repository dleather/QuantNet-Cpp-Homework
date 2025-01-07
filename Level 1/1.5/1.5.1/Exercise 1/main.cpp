// Author: David Leather. Date: 1/6/2025.
// QuantNet C++ Course 1: Level 1, Section 1.5, Exercise 1
// Return difference between two floats

#include <stdio.h> // Standard include header file

// A - B
double minus(double A, double B)
{
	return A - B;
}

int main()
{
	double A; double B; double C;

	// Ask for input.
	printf("This function computes A - B.\n");
	printf("Input A.\n");
	scanf_s("%lf", &A);
	printf("Input B.\n");
	scanf_s("%lf", &B);

	// Call minus(A, B)
	C = minus(A, B);
	printf("The difference between %.2f and %.2f is %.2f.\n", A, B, C);

	return 0;
}