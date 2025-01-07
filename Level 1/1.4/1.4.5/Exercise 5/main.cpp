// Author: David Leather. Date: 1/6/2025.
// QuantNet C++ Course 1: Level 1, Section 1.4, Exercise 5
// Writes a conversion table between Celsius and Farenheight using for loop

#include <stdio.h> // Standard include header file

int main()
{
	// Declare parameters
	double start_c = 0.0; // Starting temperature (C)
	double end_c = 19.0; // Ending temperature (C)
	double step_c = 1.0; // Step-size (C)

	// Declare other variables
	double f; double c; // Celsius and farenheight respectively

	// Print header
	printf("%10s %10s\n", "Celsius (C)", "Fahrenheit (F)");
	printf("---------------------------\n");

	// Main loop
	for (c = start_c; c <= end_c; c += step_c)
	{
		// Compute f
		f = c * 9.0 / 5.0 + 32.0;
		printf("%10.1f %10.1f\n", c, f);
	}

	return 0;
}