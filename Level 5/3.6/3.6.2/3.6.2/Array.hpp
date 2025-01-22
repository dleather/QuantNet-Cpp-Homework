/*****************************************************************************
 * File:		Array.hpp
 * Author:		David Leather
 * Date:		2025-01-22
 * Purpose:		Header file for the Array class for Point class.
 *					- -m_size - size of array
 *					- +Size() - returns size of array
 *					- +SetElement()		- Sets element i
 *					- +GetElement()		- Gets element i
 *					- +operator []()	- Indexes array 
 *
 * Version:		1.3
 *
 * Change Log:
 * Version 1.0: 2025-01-19 - Initial implementation.
 * Version 1.1: 2025-01-19 - Added to namespace DavidLeather::Container
 * Version 1.2: 2025-01-21 - Changed GetElement() to const and validate index
 *								is >= 0.
 * Version 1.3: 2025-01-22 - Added ArrayException ABC and OutOfBoundsException Class.
 *****************************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"
#include <string>
#include <sstream>

namespace DavidLeather
{
	namespace Containers
	{
		class ArrayException
		{
		public:
			virtual std::string GetMessage() const = 0;				// PVMF for returning msg.
			virtual ~ArrayException() {};							// Virtual destructor.
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
		
		class Array
		{
		private:
			CAD::Point* m_data;		// Dynamic C array of point obkects
			unsigned int m_size;	// Size of array

		public:

			// Constructors and destructors
			Array();							// Default constructor
			Array(unsigned size);				// Constructor with size argument
			Array(const Array& arr);			// Copy constructor
			~Array();							// Destructor

			// Operator overload
			Array& operator = (const Array& source);		// Assignment operator
			CAD::Point& operator [] (unsigned index);		// Square bracket operator
			CAD::Point& operator [] (unsigned index) const;	// Square bracket operator w/ const


			// Private member functions
			unsigned Size() const;								// Returns size
			void SetElement(unsigned i, const CAD::Point& pnt);	// Sets an element
			CAD::Point& GetElement(unsigned i) const;			// Gets element

		};
	}
}

#endif	// ARRAY_HPP