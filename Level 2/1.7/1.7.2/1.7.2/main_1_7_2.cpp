/******************************************************
 * File:		main_1_7_2.cpp
 * Author:		David Leather
 * Date:		2025-01-07
 * Purpose:		Calculates the length of a string.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-07 - Initial implementation.
 ******************************************************/

 /* Calculate the length of a string */

#include <stdio.h>

#define MAXLINE 30

// String length declaration
int Length(char str[]);

int main()
{
	char string[MAXLINE + 1];	// Line of maximum 30 chars + \0
	int c;						// The input character
	int i = 0;					// The counter

	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

	// Get the characters
	while ((c = getchar()) != EOF && i < MAXLINE)
	{
		// Append entered character to string
		string[i++] = (char)c;
	}
	string[i] = '\0';	// String must be closed with \0

	printf("String length is %d\n", Length(string));

	return 0;
}

/* Implement the Length() function here */
// Counts the length of the string
// If reaches maximum length returns maximum length
int Length(char* str)
{
	int len = 0; // Initlaize length to 0
	while (str[len] != '\0')	// While current character not EOF
	{
		len++;					// Increment the length counter

		// If len > MAXLINE break
		if (len > MAXLINE) break;
	}

	return len - 1;				// Subtract 1 to account for `\n` needed to call
								//	ctrl + Z in Windows Terminal
}