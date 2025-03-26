/*******************************************************************************
* File:		main_4_3_1.cpp
* Author:	David Leather
* Date:		2025-03-25
* Purpose:	Explore the containers in STL and their methods.
*				- Create list of doubles
*					- Add data
*					- Use font() and back()
*				- Create a vector of doubles
*					- Add data
*					- Use index operator to access some elements
*					- Make the vector grow
*				- Create a map that maps strings to doubles
*					- Fill the map and access elements using the [] operator
*
*Version : 1.0
*
*Change Log:
*Version 1.0: 2025-03-25 - Initial implementation.
*******************************************************************************/

#include <vector>
#include <list>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	// Part 1: Lists
	list<double> dbl_list;	// Create a list of doubles
	// Add some data
	dbl_list.push_back(1.0);
	dbl_list.push_back(2.0);
	dbl_list.push_back(3.0);
	// Show first and last element.
	cout << "---- Part I: Lists ----" << endl;
	cout << "The first element of the list is: " << dbl_list.front() << endl;
	cout << "The last element of the list is: " << dbl_list.back() << endl;
	cout << endl;

	// Part 2: Vectors
	vector<double> dbl_vec;	// Create a vector of doubles
	dbl_vec.reserve(20);	// Set capacity to 20
	// Add some data
	dbl_vec.push_back(1.0);
	dbl_vec.push_back(2.0);
	dbl_vec.push_back(3.0);
	cout << "---- Part II: Vectors ----" << endl;
	cout << "The second (middle) element of the vector is: " << dbl_vec[1] << endl;
	// Make the vector grow
	cout << "The current size is: " << dbl_vec.size() << endl;
	cout << "Adding an element..." << endl;
	dbl_vec.push_back(4.0);
	cout << "The new size is now: " << dbl_vec.size() << endl;
	cout << endl;

	// Part 3: Map
	map<string, double> dens_map;	// Initialize map from str to dbl
	// Fill the map
	dens_map["USA"] = 93.29;
	dens_map["France"] = 122.01;
	dens_map["NYC"] = 27547.56;
	// Access elements
	cout << "---- Part III: Map: String -> Double ----" << endl;
	string pre_str = "The population density per square mile of ";
	cout << pre_str << "the USA is: " << dens_map["USA"] << endl;
	cout << pre_str << "France is: " << dens_map["France"] << endl;
	cout << pre_str << "NYC is: " << dens_map["NYC"] << endl;

	return 0;
}