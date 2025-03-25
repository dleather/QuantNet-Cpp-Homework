/*****************************************************************************
 * File:		NumericArray.hpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Header file for the NumericArray template class. Derived from Array.
 *				- Array Inherited:
 *					-m_data - array of data
 *					-m_size - size of array
 *					+Size() - returns size of array
 *					+SetElement()		- Sets element i
 *					+GetElement()		- Gets element i
 *					+operator []()	- Indexes array
 *				- New:
 *					+operator +()
 *					+operator *()
 *					+DotProduct()
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-24 - Initial implementation.
 *****************************************************************************/

#ifndef NUMERICARRAY_HPP
#define NUMERICARRAY_HPP

#include "Array.hpp"

namespace DavidLeather
{
	namespace Containers
	{
		template <typename T>
		class NumericArray : public Array<T>
		{
		public:
			// Constructors
			NumericArray();									// Default
			NumericArray(unsigned size);					// Size constructor
			NumericArray(const NumericArray<T>& source);	// Copy constructor

			// Destructor
			virtual ~NumericArray();

			// Assignment operator
			NumericArray<T>& operator = (const NumericArray<T>& source);

			// Numeric operators
			NumericArray<T> operator * (T factor) const;
			NumericArray<T> operator + (const NumericArray<T>& num_arr) const;
			T DotProduct(const NumericArray<T>& num_arr) const;
		};
	}
}

#ifndef NUMERICARRAY_CPP
#include "NumericArray.cpp"
#endif

#endif