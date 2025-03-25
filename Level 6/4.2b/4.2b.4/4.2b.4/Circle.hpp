/*******************************************************************************
 * File:		Circle.hpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Header file for the Circle class:
 *					- m_radius :: radius of the point
 *					- Default constructor
 *					- Constructor with point input
 *					- Copy constructor
 *					- Destructor
 *					- Overload getter and setter of CentrePoint() and Radius()
 *					- Function that computes the diameter, Diameter()
 *					- Function that computes the area, Area()
 *					- Function that describes the circle, ToString()
 * 
 * Version:		1.4
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 * Version 1.1: 2025-01-17 - Added assignment operator.
 * Version 1.2: 2025-01-17 - Added << operator.
 * Version 1.3: 2025-01-19 - Added to namespace DavidLeather::CAD
 * Version 1.4: 2025-01-21 - Added Draw() function. Overridden from Shape Class.
 ******************************************************************************/

#ifndef Circle_HPP
#define Circle_HPP

#define _USE_MATH_DEFINES	// For M_PI constant
#include <string>
#include "Point.hpp"

namespace DavidLeather
{
	namespace CAD
	{
		class Circle: public Shape
		{
		private:
			double m_radius;
			Point m_centre_point;

		public:
			// Constructors and Destructors
			Circle();									// Default Constructor
			Circle(const Point& pnt, double r);			// Constructor with input
			Circle(const Circle& circ);					// Copy constructor
			~Circle();									// Destructor

			// Operators
			Circle& operator = (const Circle& source);	// Assignment operator

			// Getters and Setters
			Point CentrePoint() const;					// Getter of CentrePoint
			void CentrePoint(const Point& pnt);			// Setter of CentrePoint
			double Radius() const;						// Getter of radius
			void Radius(double r);						// Setter of radius

			// Circle-specific functions
			double Diameter() const;		// Returns the diameter: 2 * r
			double Area() const;			// Returns the area: pi * r * r
			double Circumference() const;	// Returns the circumference: 2 * pi * r;
			void Draw() const override;		// Draws the circle.

			// Override the ToString() function from Shape
			std::string ToString() const;	// Describes the circle.

		};

		// Declare the << Operator
		std::ostream& operator << (std::ostream& os, const Circle& c);

	}
}

#endif