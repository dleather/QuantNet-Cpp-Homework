/******************************************************
 * File:		main_1_8_1.cpp
 * Author:		David Leather
 * Date:		2025-01-08
 * Purpose:		Prints contents of struct Article.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-08 - Initial implementation.
 ******************************************************/

#include <stdio.h> 

// Initalize struct, Article
struct Article
{
	int number;
	int quantity;
	char description[20];
};

// Initialize Print() function
int Print(struct Article* article);

// Main function.
// Prints the contents of Article
int main()
{
	// Initialize article
	struct Article my_article =
	{
		1,				// Article number
		2,				// Article quantity
		"How to fly"	// Article description
	};

	// Print contents of my_article
	Print(&my_article);

	// Return exit code 0
	return 0;
}

// Define Print function
// Prints the contents of Article struct using pointers
int Print(struct Article* article)
{
	// Print contents of struct
	printf("Article number: %d.\n", article->number); 
	printf("Article quantity: %d.\n", article->quantity);
	printf("Article description: %s.\n", article->description);

	// Exit with code 0
	return 0;
}