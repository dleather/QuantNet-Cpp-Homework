/*****************************************************************************
 * File:		PointArray.cpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Sourc file for the PointArray class. Derived from Array<Point>.
 *				- Array Inherited:
 *					-m_data - array of data
 *					-m_size - size of array
 *					+Size() - returns size of array
 *					+SetElement()		- Sets element i
 *					+GetElement()		- Gets element i
 *					+operator []()	- Indexes array
 *				- New:
 *					+Length()
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-24 - Initial implementation.
 *****************************************************************************/


#include "PointArray.hpp"
#include "Array.hpp"
#include "Point.hpp"
#include <stdexcept>

namespace DavidLeather
{
	namespace Containers
	{
		// Default constructor
		PointArray::PointArray() : Array<Point>() {}

		// Size constructor
		PointArray::PointArray(unsigned size) : Array<Point>(size) {}

		// Copy constructor
		PointArray::PointArray(const PointArray& source) : Array<Point>(source) {}

		// Virtual destructor - leave body blank
		PointArray::~PointArray() {}

		// Assignment operator
		PointArray& PointArray::operator = (const PointArray& source)
		{
			// Check for self-assignment
			if (this == &source)
			{
				return *this;
			}

			// Call base class assignment operator
			Array<Point>::operator = (source);

			return *this;
		}

		// Length() function - Computes the total length of all points in array
		double PointArray::Length() const
		{
			// Ensure length is greater than one, else throw DimensionMismatch
			if (this->Size() < 2)
			{
				std::string err_msg = "Dimension mismatch: Size of array must be greater than 1.";
				throw std::invalid_argument(err_msg);
			}

			// Initalize output
			double result = double();

			// Loop over points 1, ... , Size()-1, and add length of successive points
			for (unsigned i = 1; i < this->Size(); i++)
			{
				result += (*this)[i].Distance((*this)[i - 1]);
			}

			return result;
		}
	}
}