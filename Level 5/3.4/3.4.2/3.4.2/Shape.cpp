/*****************************************************************************
 * File:		Shape.cpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Source file for the Shape Base class.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-21 - Initial implementation.
 *****************************************************************************/

#include "Shape.hpp"
#include <string>
#include <sstream>
#include "stdlib.h"

using namespace std;

namespace DavidLeather
{
	namespace CAD
	{
		// Default constructor
		Shape::Shape() : m_id(rand()) {}

		// Copy constructor
		Shape::Shape(const Shape& source) : m_id(source.m_id) {}

		// Assignment Operator
		Shape& Shape::operator = (const Shape& source)
		{
			// Prevents self-assignmet
			if (this == &source)
			{
				return *this;
			}

			// Set data
			m_id = source.m_id;

			return *this;
		}

		// ID() function - returns the private ID
		int Shape::ID() const
		{
			return m_id;
		}

		// ToString function - Returns string "ID: 123"
		std::string Shape::ToString() const
		{
			stringstream sstring;				// Initalize stringstream object
			sstring << "ID: " << m_id << ".";	// Put output string into stream
			return sstring.str();				// Return converted string

		}

	}
}
