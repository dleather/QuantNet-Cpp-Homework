// Author: David Leather. Date: 1/6/2025.
// QuantNet C++ Course 1: Level 1, Section 1.4, Exercise 7
// Counts 0, 1, 2, 3, 4 in words
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
	switch (n_0) // 0
	{
		case 0:
			printf("Number zero appears zero times.\n"); break;
		case 1:
			printf("Number zero appears one time.\n"); break;
		case 2:
			printf("Number zero appears two times.\n"); break;
		default:
			printf("Number zero appears more than two times.\n"); break;
	}

	switch (n_1) // 1
	{
	case 0:
		printf("Number one appears zero times.\n"); break;
	case 1:
		printf("Number one appears one time.\n"); break;
	case 2:
		printf("Number one appears two times.\n"); break;
	default:
		printf("Number one appears more than two times.\n"); break;
	}
	
	switch (n_2) // 2
	{
	case 0:
		printf("Number two appears zero times.\n"); break;
	case 1:
		printf("Number two appears one time.\n"); break;
	case 2:
		printf("Number two appears two times.\n"); break;
	default:
		printf("Number two appears more than two times.\n"); break;
	}

	switch (n_3) // 3
	{
	case 0:
		printf("Number three appears zero times.\n"); break;
	case 1:
		printf("Number three appears one time.\n"); break;
	case 2:
		printf("Number three appears two times.\n"); break;
	default:
		printf("Number three appears more than two times.\n"); break;
	}

	switch (n_4) // 4
	{
	case 0:
		printf("Number four appears zero times."); break;
	case 1:
		printf("Number four appears one time."); break;
	case 2:
		printf("Number four appears two times."); break;
	default:
		printf("Number four appears more than two times."); break;
	}

	return 0;
}



