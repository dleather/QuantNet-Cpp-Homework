/*****************************************************************************
 * File:		Array.cpp
 * Author:		David Leather
 * Date:		2025-03-26
 * Purpose:		Source file for the Array class for Point class.
 *					- -m_size - size of array
 *					- +Size() - returns size of array
 *					- +SetElement()		- Sets element i
 *					- +GetElement()		- Gets element i
 *					- +operator []()	- Indexes array
 *
 * Version:		1.6
 *
 * Change Log:
 * Version 1.0: 2025-01-19 - Initial implementation.
 * Version 1.1: 2025-01-19 - Added to DavidLeather::Containers namespace.
 * Version 1.2: 2025-01-21 - Made GetElement() const and validate index >= 0.
 * Version 1.3: 2025-01-22 - Improved bounds checking for SetElement(),
 *								GetElement(), and the index operator, [].
 * Version 1.4: 2025-01-22 - Changed exception handling to throw
 *								OutOfBoundException object instead of -1.
 * Version 1.5: 2025-03-24 - Converted to template implementation.
 * Version 1.6: 2025-03-26 - Changed constructors to use colon syntax.
 *						   - Added definition for DefaultSize getter and setter.
 *						   - Changed constructos to use static m_default_size
 *****************************************************************************/

#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.hpp"

namespace DavidLeather
{
	namespace Containers
	{
		// Default constructor - creates 10 elements
		template <typename T>
		Array<T>::Array()
			: m_size(m_default_size), m_data(new T[m_default_size]) {
		}

		// Constructor with size argument
		template <typename T>
		Array<T>::Array(unsigned size)
			: m_size(size == 0 ? m_default_size : size), m_data(new T[m_size]) {
		}

		// Copy constructor
		template <typename T>
		Array<T>::Array(const Array<T>& arr)
			: m_size(arr.m_size), m_data(new T[arr.m_size])
		{
			// Fill out array
			for (unsigned i = 0; i < m_size; ++i)
			{
				m_data[i] = arr.m_data[i];
			}
		}

		// Destructor
		template <typename T>
		Array<T>::~Array()
		{
			delete[] m_data;	// Delete data from memory
		}

		// Assignment operator
		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source)
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
			m_data = new T[m_size];
			for (unsigned i = 0; i < m_size; ++i)
			{
				m_data[i] = source.m_data[i];
			}

			return *this;
		}

		// Square bracket operator
		template <typename T>
		T& Array<T>::operator [] (unsigned index)
		{
			// If index is out of range return first element.
			if ((index >= m_size) || (index < 0)) throw OutOfBoundsException(index);

			// Else return the proper element
			return m_data[index];
		}

		// Square bracket operator w/ const
		template <typename T>
		const T& Array<T>::operator [] (unsigned index) const
		{
			// If index is out of range return first element.
			if ((index >= m_size) || (index < 0)) throw OutOfBoundsException(index);

			// Else return the proper element
			return m_data[index];
		}

		// Return size of array
		template <typename T>
		unsigned Array<T>::Size() const
		{
			return m_size;
		}

		// Set an element
		template <typename T>
		void Array<T>::SetElement(unsigned i, const T& element)
		{
			// If element is out of bounds, throw exception.
			if ((i >= m_size) || (i < 0)) throw OutOfBoundsException(i);

			// Else, set the element
			m_data[i] = element;
		}

		// Get element
		template <typename T>
		const T& Array<T>::GetElement(unsigned i) const
		{
			// If OOB, return first element
			if ((i >= m_size) || (i < 0)) throw OutOfBoundsException(i);

			// Else, return ith element
			return m_data[i];
		}

		// Getter for default size
		template <typename T>
		unsigned int Array<T>::DefaultSize()
		{
			return m_default_size;
		}

		// Setting for default size
		template <typename T>
		void Array<T>::DefaultSize(unsigned int size)
		{
			m_default_size = size;
		}

	}
}

#endif // Array_cpp
