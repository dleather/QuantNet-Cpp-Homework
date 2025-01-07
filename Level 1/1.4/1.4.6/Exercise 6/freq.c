// Author: David Leather. Date: 1/6/2025.
// QuantNet C++ Course 1: Level 1, Section 1.4, Exercise 6
// Counts 0, 1, 2, 3, 4
#include <stdio.h> // Standard include header file

int main()
{
	// Initialize variables 
	int n_0 = 0; int n_1 = 0; int n_2 = 0; int n_3 = 0; int n_4 = 0; int n_other = 0; // Counters
	int continue_loop = 1; // Continute while loop flag
	char c;

	// Main results
	while (continue_loop)
	{
		c = getchar();

		switch (c)
		{
			case '0':
				n_0++; break;
			case '1':
				n_1++; break;
			case '2':
				n_2++; break;
			case '3':
				n_3++; break;
			case '4':
				n_4++; break;
			case EOF:
				continue_loop = 0; break; // Exit loop
			default:
				n_other++; break;
		}

	}

	// Print results
	printf("Frequency of 0: %d\n", n_0);
	printf("Frequency of 1: %d\n", n_1);
	printf("Frequency of 2: %d\n", n_2);
	printf("Frequency of 3: %d\n", n_3);
	printf("Frequency of 4: %d\n", n_4);
	printf("Frequency of other characyers: %d", n_other);
}



