// Author: David Leather. Date: 1/6/2025.
// QuantNet C++ Course 1: Level 1, Section 1.4, Exercise 1
// Write a while loop w/ switch that prints the number of characters, words, and lines.

#include <stdio.h>

int main()
{
	// Declare variables
	int wrd_cnt = 0;
	int char_cnt = 0;
	int line_cnt = 0; // Set to 0 to not count ctrl + z to end.
	int in_word = 0;
	char c;
	int continue_loop = 1;

	printf("Type away...\nPress Ctrl + Z on a new line to end.\n");
	while (continue_loop)
	{
		// Get current character
		c = getchar();

		switch (c)
		{
			case EOF:
				continue_loop = 0; break;
			case '\n':
				line_cnt++;
				in_word = 0; break;
			case ' ':
				char_cnt++;
				if (in_word)
				{
					in_word = 1 - in_word;
				} break;
			default:
				char_cnt++;
				if (in_word == 0)
				{
					in_word = 1 - in_word;
					wrd_cnt++;
				} break;
		}
	}
	printf("Character Count: %d\n", char_cnt);
	printf("Word Count: %d\n", wrd_cnt);
	printf("Line Count: %d\n", line_cnt);

	return 0;
}