/*****************************************************************************
 * File:		Shape.hpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Header file for the Shape Base class.
 * Version:		1.2
 *
 * Change Log:
 * Version 1.0: 2025-01-21 - Initial implementation.
 * Version 1.1: 2025-01-21 - Made ToString() function virtual.
 * Version 1.2: 2025-01-21 - Added custom destructor and made it virtual.
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
			virtual ~Shape();							// Destructor
			int ID() const;								// Returns m_id
			virtual std::string ToString() const;		// Returns string describing shape

		};
	}
}

#endif