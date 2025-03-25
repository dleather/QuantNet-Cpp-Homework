/*****************************************************************************
 * File:		PointArray.hpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Header file for the PointArray class. Derived from Array<Point>.
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

#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP

#include "Array.hpp"
#include "Point.hpp"

using namespace DavidLeather::CAD;

namespace DavidLeather
{
	namespace Containers 
	{
		class PointArray : public Array<Point>
		{
		public:
			// Constructors
			PointArray();							// Default constructor
			PointArray(unsigned size);				// Size constructor
			PointArray(const PointArray& source);	// Copy constructor

			// Destructor
			virtual ~PointArray();

			// Assignment Operator
			PointArray& operator = (const PointArray& source);

			//Numeric operators
			double Length() const;
		};
	}
}

#endif	// POINTARRAY_HPP