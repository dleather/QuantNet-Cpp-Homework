/*******************************************************************************
* File:		main_4_3_2.cpp
* Author:	David Leather
* Date:		2025-03-25
* Purpose:	Explore the iterators in STL and their methods.
*				1. Create a function that calculates the sum of a container with
*					doubles.
*					- Create a template function called Sum() that accepts the
*						template argument T as input and returns a double.
*						The template argument will be a container.
*					- In the implementation get an iterator (T::const_iterator)
*						for the end.
*					- Then create a loop that iterates the container T and adds
*						all values.
*					- Finally return the sum.
* 				- In the main program, call the Sum() function for the different
*					container from the previous exercise.
* 				2. Create a Sum() function that calculates the sum of all values
*					between two passed-in iterators. 
*					- The function should use the template argument for the iterator
*						type and accept two iterators, the 'start' - and 'end'
*						iterator.
*					- The summation should include the value pointed to by the start
*						iterator and exclude the value pointed to by the end iterator.
*
*Version : 1.0
*
*Change Log:
*Version 1.0: 2025-03-25 - Initial implementation.
*******************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <map>

#include "sum.hpp"

using namespace std;

int main()
{
	// Part 1: Create structures from last session

	// Lists
	list<double> l;	// Create a list of doubles
	l.push_back(1.0);
	l.push_back(2.0);
	l.push_back(3.0);
	l.push_back(4.0);

	// Vectors
	vector<double> v;	// Create a vector of doubles
	v.reserve(20);	// Set capacity to 20
	v.push_back(1.0);
	v.push_back(2.0);
	v.push_back(3.0);
	v.push_back(4.0);

	// Map
	map<string, double> dens_map;	// Initialize map from str to dbl
	// Fill the map
	dens_map["USA"] = 93.29;
	dens_map["France"] = 122.01;
	dens_map["NYC"] = 27547.56;

	// Part 2: Call the first Sum() functions for the different containers
	cout << "The sum of the entire list is: " << Sum(l) << endl;
	cout << "The sum of the entire vector is: " << Sum(v) << endl;
	cout << "The sum of the entire map is: " << Sum(dens_map) << endl;

	// Part 3: Call the second Sum() function for the different containers
	cout << "The sum of list of all but last element: " << Sum(l.begin(), --l.end());
	cout << endl;
	cout << "The sum of vector of all but last element: " << Sum(v.begin(), --v.end());
	cout << endl;
	cout << "The sum of map of all but last element: ";
	cout << Sum(dens_map.begin(), --dens_map.end()) << endl;

	return 0;
}