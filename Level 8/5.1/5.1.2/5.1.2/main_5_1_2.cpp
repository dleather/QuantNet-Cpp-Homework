/***************************************************************************
 * File:		main_5_1_2.cpp
 * Author:		David Leather
 * Date:		2025-03-27
 * Purpose:		Explore the Tuple class.
 *					1. Create typedef for a Person tuple that contains:
 *						a. Name (string)
 *						b. Age (years, int)
 *						c. Height (inches, double)
 *					2. Create a function that prints the person tuple,
 *						a. Use the get<T>() member function to retrieve data.
 *					3. Create a few person tuple instances and prints them.
 *					4. Also increment age of one of the persons
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-27 - Initial implementation.
 *****************************************************************************/

#include <iostream>
#include <boost/tuple/tuple.hpp>

using namespace std;

// Create person typedef
typedef boost::tuple<string, int, double> Person;	// (Name, Age, Height)

// Create function that prints the Person tuple
void PrintPerson(const Person& p)
{
	cout << "Name: " << boost::get<0>(p) << "." << endl;
	cout << "Age: " << boost::get<1>(p) << " years old." << endl;
	cout << "Height: " << boost::get<2>(p) << " inches tall." << endl;
	cout << endl;
}

int main()
{
	// Define a few people (my cats)
	Person catalino = boost::make_tuple("Catalino", 0, 24.0);
	Person calliope = boost::make_tuple("Calliope", 6, 32.0);
	Person julius = boost::make_tuple("Julius", 7, 36.0);

	// Print the people tuples
	PrintPerson(catalino);
	PrintPerson(calliope);
	PrintPerson(julius);

	// Increment age of one person
	cout << "It's Catalino's birthday!" << endl << endl;
	boost::get<1>(catalino)++;	// Increment Catalino's age by 1
	PrintPerson(catalino);		// Show the new result

	return 0;
}
