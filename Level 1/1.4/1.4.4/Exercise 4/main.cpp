// Author: David Leather. Date: 1/6/2025.
// QuantNet C++ Course 1: Level 1, Section 1.4, Exercise 4
// Writes a conversion table between Celsius and Farenheight using while loop

#include <stdio.h> // Standard include header file

int main()
{
	// Declare parameters
	double start_f = 0.0; // Starting temperature (F)
	double end_f = 300.0; // Ending temperature (F)
	double step_f = 20.0; // Step-size (F)

	// Declare other variables
	double f; double c; // Farenheight and celsius respectively

	// Print header
	printf("%10s %10s\n", "Fahrenheit (F)", "Celsius (C)");
	printf("---------------------------\n");

	// Initalize f
	f = start_f; 

	// Main loop
	while (f <= end_f)
	{
		c = (5.0 / 9.0) * (f - 32.0); // Compute celsius
		printf("%10.1f %10.1f\n", f, c); // Print line

		// Iterate forward
		f += step_f;
	}

	return 0;
}