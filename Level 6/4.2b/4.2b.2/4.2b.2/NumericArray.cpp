/*****************************************************************************
 * File:		NumericArray.cpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Source file for the NumericArray template class. Derived from Array.
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

#ifndef NUMERICARRAY_CPP
#define NUMERICARRAY_CPP
#include "NumericArray.hpp"
#include <stdexcept>		// Include for std::invalid_argument


namespace DavidLeather
{
	namespace Containers
	{
		// Default Constructor
		template <typename T>
		NumericArray<T>::NumericArray() : Array<T>() {}	// Calls default constructor

		// Size constructor
		template <typename T>
		NumericArray<T>::NumericArray(unsigned size) : Array<T>(size) {}

		// Copy constructor
		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& num_arr) : Array<T>(num_arr) {}

		// Destructor
		template <typename T>
		NumericArray<T>::~NumericArray() {}	// Destructor of base class gets called last

		// Assignment operator
		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
		{
			// Check for self-assignment
			if (this == &source)
			{
				return *this;
			}

			// Call base class assignment operator
			Array<T>::operator = (source);

			return *this;
		}

		// * operator - scale by a factor
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (T factor) const
		{
			// Initalize new array
			NumericArray<T> new_arr(this->Size());

			// Scale each element of old array by factor and store in new array
			for (unsigned i = 0; i < this->Size(); i++)
			{
				new_arr[i] = (*this)[i] * factor;
			}

			return new_arr;
		}

		// + operator - adds an array of same size to the input array.
		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& num_arr) const
		{
			// Check for same dimensions
			if (this->Size() != num_arr.Size())
			{
				std::string err_msg = "Dimension mismatch: Arrays must be of the same size";
				throw std::invalid_argument(err_msg);
			}

			// Initalize new array
			NumericArray<T> new_arr(this->Size());
			for (unsigned i = 0; i < this->Size(); i++)
			{
				new_arr[i] = (*this)[i] + num_arr[i];
			}

			return new_arr;
		}

		template <typename T>
		T NumericArray<T>::DotProduct(const NumericArray<T>& num_arr) const
		{
			// Check for same dimensions
			if (this->Size() != num_arr.Size())
			{
				std::string err_msg = "Dimension mismatch: Arrays must be of the same size";
				throw std::invalid_argument(err_msg);
			}

			// Intialize result
			T result = T();

			// Compute sum_i a[i]*b[i]
			for (unsigned i = 0; i < this->Size(); i++)
			{
				result += (*this)[i] * num_arr[i];
			}

			return result;
		}
	}
}

#endif