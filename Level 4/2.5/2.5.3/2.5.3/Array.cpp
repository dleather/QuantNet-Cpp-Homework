/*****************************************************************************
 * File:		Array.cpp
 * Author:		David Leather
 * Date:		2025-01-19
 * Purpose:		Source file for the Array class for Point class.
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

#include "Array.hpp"

// Default constructor - creates 10 elements
Array::Array()
{
	m_data = new Point[10];	// Create array 10 Point objects
	m_size = 10;			// Size of array
}

// Constructor with size argument
Array::Array(unsigned size)
{
	// If size is equal to 0 set it to default value of 10.
	if (size == 0)
	{
		size = 10;
	}

	m_data = new Point[size];	// Create an array of size Point objects
	m_size = size;				// Size of array
}

// Copy constructor
Array::Array(const Array& arr)
{
	m_size = arr.m_size;	// Set size

	// Create new array and set each element seperatelt
	m_data = new Point[m_size];
	for (int i = 0; i < m_size; ++i)
	{
		m_data[i] = arr.m_data[i];
	}
}

// Destructor
Array::~Array()
{
	delete[] m_data;	// Delete data from memory
}

// Assignment operator
Array& Array::operator = (const Array& source)
{
	// Check for self-assignment
	if (this == &source)
	{
		return *this;
	}

	// Free old memory
	delete[] m_data;

	// Set size
	m_size = source.m_size;

	// Create new array and set each element seperatelt
	m_data = new Point[m_size];
	for (int i = 0; i < m_size; ++i)
	{
		m_data[i] = source.m_data[i];
	}

	return *this;
}

// Square bracket operator
Point& Array::operator [] (unsigned index)
{
	// If index is out of range return first element.
	if ((index >= m_size) || (index < 0))
	{
		return m_data[0];
	}

	// Else return the proper element
	return m_data[index];
}

// Square bracket operator w/ const
Point& Array::operator [] (unsigned index) const
{
	// If index is out of range return first element.
	if ((index >= m_size) || (index < 0))
	{
		return m_data[0];
	}

	// Else return the proper element
	return m_data[index];
}

// Return size of array
unsigned Array::Size() const
{
	return m_size;
}

// Set an element
void Array::SetElement(unsigned i, const Point& pnt)
{
	// If element is out of bounds escape
	if ((i >= m_size) || (i < 0))
	{
		return;
	}

	// Else, set the element
	m_data[i] = pnt;
}

// Get element
Point& Array::GetElement(unsigned i) const
{
	// If OOB, return first element
	if ((i >= m_size) || (i < 0))
	{
		return m_data[0];
	}

	// Else, return ith element
	return m_data[i];
}