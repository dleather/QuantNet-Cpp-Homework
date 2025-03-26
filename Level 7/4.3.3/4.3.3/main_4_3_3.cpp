/*******************************************************************************
* File:		main_4_3_3.cpp
* Author:	David Leather
* Date:		2025-03-26
* Purpose:	Explore the STL algorithms.
*				1. Use the `count_if()` function to count number of elements less
*					than a certain number
*					- Need to define a global predicate to pass to `count_if()`
*				2. Replace the global predicate above with a function object.
*					- Have the inputed value be a private member of the function
*						class.
*
*Version : 1.0
*
*Change Log:
*Version 1.0: 2025-03-26 - Initial implementation.
*******************************************************************************/

// Script parameter - global upper boundary
double boundary = 5.0;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Predefine global predicate for count_if()
inline bool LessThan(double input)
{
	return (input < boundary);
}

// Predefine predicate functor for count_if()
class LessThanFunctor {
private:
	double upper_boundary;

public:
	// Constructor
	explicit LessThanFunctor(double upper_bound) : upper_boundary(upper_bound) {}

	// Overload
	bool operator () (double input) const
	{
		return (input < upper_boundary);
	}
};

int main()
{
	// Part 1: Create vector
	vector<double> v;	// Initalize vector
	v.reserve(10);		// Reserve capacity for 10 elements
	
	// Fill vector with elements 1, ..., 10
	for (unsigned i = 0; i < 10; ++i)
	{
		v.push_back(i + 1.0);
	}
	
	// Should return 4.0 - Check
	cout << "Part 1: Using global function." << endl;
	cout << "------------------------------" << endl;
	cout << "There are " << count_if(v.begin(), v.end(), LessThan);
	cout << " numbers less than " << boundary << " in the vector." << endl;
	cout << "------------------------------" << endl;
	cout << endl;

	// Part 2: Use the functor instead
	LessThanFunctor lt(boundary);	// Call default constructor
	cout << "Part 2: Using function class." << endl;
	cout << "------------------------------" << endl;
	cout << "There are " << count_if(v.begin(), v.end(), lt);
	cout << " numbers less than " << boundary << " in the vector." << endl;
	cout << "------------------------------" << endl;
	cout << endl;

	cout << "Both values should be " << boundary - 1.0 << "." << endl;

	return 0;
}