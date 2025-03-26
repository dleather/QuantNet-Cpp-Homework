/*******************************************************************************
* File:		sum.hpp
* Author:	David Leather
* Date:		2025-03-25
* Purpose:	Creates two sum function templates.
*				1. Create a function that calculates the sum of a container
*					outputted as double. Template parameter is the container type.
* 				2. Create a Sum() function that calculates the sum of all values
*					between two passed-in iterators. Template parameter is the
* 					iterator type.	
*
*Version : 1.0
*
*Change Log:
*Version 1.0: 2025-03-25 - Initial implementation.
*******************************************************************************/

#ifndef SUM_HPP
#define SUM_HPP

#include <iterator>

// Create helper function to extract values of iterators of both numeric and pair types

// Extracts calue of numeric types
template <typename T>
inline T ExtractValue(const T& value)
{
	return value;
}

// Extracts value of pair types
template <typename T_Key, typename T_Val>
inline T_Val ExtractValue(const std::pair<T_Key, T_Val>& value)
{
	return value.second;
}

// Part 1: sum function for entire container
template <typename T>
double Sum(const T& container)
{
	double result = 0.0;			// Initialize resulting sum to 0.0

	// Loop over all elements from begin to end of container
	typename T::const_iterator end_i = container.end();
	for (typename T::const_iterator i = container.begin(); i != end_i; ++i)
	{
		result += ExtractValue(*i);	// Add the value of the current element to the sum
	}

	return result;
}

// Part 2: sum function for range of elements
template <typename IterType>
inline double Sum(IterType start_it, IterType end_it)
{
	double result = 0.0;			// Initialize resulting sum to 0.0

	// Loop over all elements from start to end iterator
	for (IterType i = start_it; i != end_it; ++i)
	{
		result += ExtractValue(*i);	// Add the value of the current element to the sum
	}

	return result;
}

#endif // SUM_HPP