/*******************************************************************************
 * File:		main_1_9_2.cpp
 * Author:		David Leather
 * Date:		2025-01-09
 * Purpose:		Reads characters from keyboard and prints to file.
 *				Inputted characters should only be written when the user hits
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
	const unsigned int buffer_size = 1024u;	// Size of buffer
	int current_char;						// Store character as int
	char buffer[buffer_size];				// Buffer to store current line string
	int index = 0;							// Index to store current position of buffer
	char fp_str[buffer_size];				// File path string
	FILE* fp;								// File pointer

	// Prompt user for file
	printf("Enter the desired filename.\n");
	scanf_s("%s", fp_str, buffer_size);

	// Open file for writing
	fopen_s(&fp, fp_str, "w");

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
			fprintf(fp, "Ctrl + A is a correct ending.");

			// Exit while loop
			break;
		}

		// If enter, then print the line
		if (current_char == '\n')
		{
			buffer[index] = '\0';			// Terminate string
			fprintf(fp, "%s\n", buffer);	// Print buffer
			index = 0;						// Reset buffer index
		}
		else if (index < 1023)				// Add to the buffer
		{
			buffer[index] = current_char;	// Store new character in buffer
			index++;						// Iterate forward index
		}
		else // Throw error
		{
			fprintf(fp, "Line exceeds max characters of 1024.");
			break;
		}

	}

	// Close file
	fclose(fp);

	// Return exit code 0
	return 0;

}