/*****************************************************************************
 * File:		Array.hpp
 * Author:		David Leather
 * Date:		2025-01-19
 * Purpose:		Header file for the Array class for Point class.
 *					- -m_size - size of array
 *					- +Size() - returns size of array
 *					- +SetElement()		- Sets element i
 *					- +GetElement()		- Gets element i
 *					- +operator []()	- Indexes array 
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-19 - Initial implementation.
 *****************************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"

class Array
{
private:
	Point* m_data;			// Dynamic C array of point obkects
	unsigned int m_size;	// Size of array

public:

	// Constructors and destructors
	Array();									// Default constructor
	Array(unsigned size);						// Constructor with size argument
	Array(const Array& arr);					// Copy constructor
	~Array();									// Destructor

	// Operator overload
	Array& operator = (const Array& source);	// Assignment operator
	Point& operator [] (unsigned index);		// Square bracket operator
	Point& operator [] (unsigned index) const;	// Square bracket operator w/ const


	// Private member functions
	unsigned Size() const;							// Returns size
	void SetElement(unsigned i, const Point& pnt);	// Sets an element
	Point& GetElement(unsigned i) const;			// Gets element

};

#endif	// ARRAY_HPP