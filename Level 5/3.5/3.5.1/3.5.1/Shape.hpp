/*****************************************************************************
 * File:		Shape.hpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Header file for the Shape Base class.
 * Version:		1.1
 *
 * Change Log:
 * Version 1.0: 2025-01-21 - Initial implementation.
 * Version 1.1: 2025-01-21 - Made ToString() function virtual.
 *****************************************************************************/

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

namespace DavidLeather
{
	namespace CAD
	{
		class Shape
		{
		private:
			int m_id;

		public:
			Shape();									// Default constructor
			Shape(const Shape& source);					// Copy constructor
			Shape& operator = (const Shape& source);	// Assignment operator
			int ID() const;								// Returns m_id
			virtual std::string ToString() const;		// Returns string describing shape

		};
	}
}

#endif