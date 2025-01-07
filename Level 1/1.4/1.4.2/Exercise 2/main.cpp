// Author: David Leather. Date: 1/6/2025.
// QuantNet C++ Course 1: Level 1, Section 1.4, Exercise 2
// Write a do-while loop that prints the number of characters, words, and lines.

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
	do
	{
		// Get current character
		c = getchar();

		if (c != EOF) //If not ctrl + Z...
		{
			// If new line, add cntr and continue
			if (c == '\n')
			{
				line_cnt++;
				in_word = 0;
				continue;
			}

			char_cnt++;

			// Handle space
			if (c == ' ')
			{
				// If previously in word, switch
				if (in_word)
				{
					in_word = 1 - in_word;
				}
				continue;
			}

			// If not space, then its a character
			if (in_word == 0)
			{
				in_word = 1 - in_word;
				wrd_cnt++;
			}
		}
		else
		{
			continue_loop = 0;
		}
		

	} while (continue_loop);

	printf("Character Count: %d\n", char_cnt);
	printf("Word Count: %d\n", wrd_cnt);
	printf("Line Count: %d\n", line_cnt);

	return 0;
}