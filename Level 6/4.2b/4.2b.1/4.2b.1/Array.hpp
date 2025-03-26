/*****************************************************************************
 * File:		Array.hpp
 * Author:		David Leather
 * Date:		2025-03-26
 * Purpose:		Header file for the Array template class.
 *					-m_data - array of data
 *					-m_size - size of array
 *					+Size() - returns size of array
 *					+SetElement()		- Sets element i
 *					+GetElement()		- Gets element i
 *					+operator []()	- Indexes array
 *
 * Version:		1.6
 *
 * Change Log:
 * Version 1.0: 2025-01-19 - Initial implementation.
 * Version 1.1: 2025-01-19 - Added to namespace DavidLeather::Container
 * Version 1.2: 2025-01-21 - Changed GetElement() to const and validate index
 *								is >= 0.
 * Version 1.3: 2025-01-22 - Added ArrayException ABC and OutOfBoundsException Class.
 * Version 1.4: 2025-03-24 - Turned Array class into template class.
 * Version 1.5: 2025-03-24 - Add static data member and function for DefaultSize.
 * Version 1.6: 2025-03-26 - Initalized static m_default_size after class defn.
 *****************************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <sstream>

namespace DavidLeather
{
	namespace Containers
	{
		class ArrayException
		{
		public:
			virtual std::string GetMessage() const = 0;	// PVMF for returning msg.
			virtual ~ArrayException() {};				// Virtual destructor.
		};

		class OutOfBoundsException : public ArrayException
		{
		private:
			int m_index;	// Index that returned OOBException.

		public:
			// Constructors and Destructors
			OutOfBoundsException(int index) : m_index(index) {};	// Store index
			virtual ~OutOfBoundsException() override {};			// Destructor

			// Override GetMessage() PVMF
			virtual std::string GetMessage() const override
			{
				std::stringstream sstream;							// Initalize stringstream
				sstream << "Invalid index at " << m_index << ".";	// Create output string
				return sstream.str();
			}

		};
		template <typename T>
		class Array
		{
		private:
			unsigned int m_size;				// Size of array
			T* m_data;							// Dynamic C array of point objects
			static unsigned int m_default_size;	// Default size of the array

		public:

			// Constructors and destructors
			Array();							// Default constructor
			Array(unsigned size);				// Constructor with size argument
			Array(const Array<T>& arr);			// Copy constructor
			~Array();							// Destructor

			// Operator overload
			Array<T>& operator = (const Array<T>& source);	// Assignment operator
			T& operator [] (unsigned index);				// Square bracket operator
			const T& operator [] (unsigned index) const;	// Square bracket operator w/ const


			// Private member functions
			unsigned Size() const;							// Returns size
			void SetElement(unsigned i, const T& element);	// Sets an element
			const T& GetElement(unsigned i) const;				// Gets element

			// Static functions
			static unsigned int DefaultSize();			// Get default size
			static void DefaultSize(unsigned int size);	// Set default size
		};

		template <typename T>
		unsigned int Array<T>::m_default_size = 10;
	}
}

// Include the implementation file
#ifndef ARRAY_CPP
#include "Array.cpp"
#endif	// ARRAY_CPP

#endif	// ARRAY_HPP