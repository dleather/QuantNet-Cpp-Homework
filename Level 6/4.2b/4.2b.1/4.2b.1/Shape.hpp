/*****************************************************************************
 * File:		Shape.hpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Header file for the Shape Base class.
 * Version:		1.4
 *
 * Change Log:
 * Version 1.0: 2025-01-21 - Initial implementation.
 * Version 1.1: 2025-01-21 - Made ToString() function virtual.
 * Version 1.2: 2025-01-21 - Added custom destructor and made it virtual.
 * Version 1.3: 2025-01-21 - Added Draw() PVMF.
 * Version 1.4: 2025-01-21 - Added the Shape() template function.
 *****************************************************************************/

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <iostream>

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
			virtual void Draw() const = 0;				// PVMF for Drawing Shape

			// Template Print() function.
			void Print() const { std::cout << ToString() << std::endl; }

		};
	}
}

#endif