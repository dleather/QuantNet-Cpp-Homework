// Author: David Leather. Date: 1/3/2025.
// QuantNet C++ Course 1: Level 1, Section 1.3, Exercise 2
// Computes area of triangle with one right angle

#include <stdio.h> // Include "stdio.h" header

int main()
{
	// Declare variables
	double area, base, height;

	// Ask for base of triangle
	printf("What is the base of the triangle? (sq. ft)\n");
	scanf_s("%lf", &base);

	// Ask for height of triangle
	printf("What is the height of the triangle? (sq. ft)\n");
	scanf_s("%lf", &height);
		
	// Compute the area of half the base times height
	area = 0.5 * base * height;

	// Print output
	printf("The area of the triangle is %.2f sq. ft.\n", area);

	return 0;
}