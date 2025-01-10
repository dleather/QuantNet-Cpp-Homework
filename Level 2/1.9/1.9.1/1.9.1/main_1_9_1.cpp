/*******************************************************************************
 * File:		main_1_9_1.cpp
 * Author:		David Leather
 * Date:		2025-01-09
 * Purpose:		Reads characters from keyboard and shows them on the screen.
 *				Inputted characters should only be displayed when the user hits
 *					'enter', line by line.
 *				When ^A is entered, the program must end properly..
 *				Then the following message will appear: “CTRL + A is a correct
 *					ending.”
 *				Tip: getchar() reads and putchar() writes the type int. The
 *					value of ^A is 1.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0:	2025-01-09 - Initial implementation.
 ******************************************************************************/

#include <stdio.h>

int main()
{
	// Initalize variables
	int current_char;						// Store character as int
	char buffer[1024];						// Buffer to store current line string
	int index = 0;							// Index to store current position of buffer

	// Prompt user for input
	printf("Type away. Enter CTRL + A when finished.\n");

	// Begin main loop
	while (1)								// Infinite loop
	{
		current_char = getchar();			// Get current character as integer

		// Check for exit condition
		if (current_char == 1)				// If CTRL + A was entered...
		{
			// Print exit message
			printf("\nCtrl + A is a correct ending.");

			// Exit while loop
			break;
		}

		// If enter, then print the line
		if (current_char == '\n')
		{
			buffer[index] = '\0';			// Terminate string
			printf("%s\n", buffer);			// Print buffer
			index = 0;						// Reset buffer index
		}
		else if (index < 1023)				// Add to the buffer
		{
			index++;						// Iterate forward index
			buffer[index] = current_char;	// Store new character in buffer
		}
		else	// Throw error
		{
			printf("Line exceeds max characters of 1024.");
			break;
		}

	}

	// Return exit code 0
	return 0;

}