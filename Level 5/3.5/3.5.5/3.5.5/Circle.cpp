/******************************************************
 * File:		Circle.cpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Source file for the Circle class:
 *					- m_id	::	ID of shape
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
 * Version:		1.5
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 * Version 1.1: 2025-01-17 - Added assignment operator.
 * Version 1.2: 2025-01-19 - Added to DavidLeather::CAD namespace
 * Version 1.3: 2025-01-21 - Changed constructors to : syntax.
 * Version 1.4: 2025-01-21 - Made Circle derived from Shape class.
 * Version 1.5: 2025-01-21 - Added Draw() function. Overridden from Shape class.
 ******************************************************/

#define _USE_MATH_DEFINES	// For M_PI constant
#include <sstream>
#include <string>
#include "Point.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include <iostream>

using namespace std;

namespace DavidLeather
{
	namespace CAD
	{
		// Default constructor
		Circle::Circle() : Shape(), m_centre_point(Point()), m_radius(1.0) {}

		// Constructor with input
		Circle::Circle(const Point& pnt, double r)
			: Shape(), m_centre_point(pnt), m_radius(r) {}

		// Copy Constructor
		Circle::Circle(const Circle& circ)
			: Shape(circ), m_centre_point(circ.m_centre_point), m_radius(circ.m_radius) {}

		// Destructor
		Circle::~Circle() {};

		// Assignment operator
		Circle& Circle::operator = (const Circle& source)
		{
			// Check for self-assignmet
			if (this == &source)
			{
				return *this;
			}

			// Call base class copy constructor
			Shape::operator = (source);

			// Make assignments
			m_radius = source.m_radius;
			m_centre_point = source.m_centre_point;

			return *this;
		}

		// Getter of CentrePoint()
		Point Circle::CentrePoint() const
		{
			return m_centre_point;
		}

		// Getter of Radius()
		double Circle::Radius() const
		{
			return m_radius;
		}

		// Setter of CentrePoint()
		void Circle::CentrePoint(const Point& pnt)
		{
			m_centre_point = pnt;
		}

		// Setter of Radius()
		void Circle::Radius(double r)
		{
			m_radius = r;
		}

		// Return diameter: 2*r
		double Circle::Diameter() const
		{
			return 2.0 * m_radius;
		}

		// Return Area: pi * r * r
		double Circle::Area() const
		{
			return M_PI * m_radius * m_radius;
		}

		// Return Circumference: 2 * pi * r
		double Circle::Circumference() const
		{
			return 2.0 * M_PI * m_radius;
		}

		// Describe the circle
		std::string Circle::ToString() const
		{
			// Initialize buffer
			std::stringstream output_stream;

			// Define output string
			output_stream << Shape::ToString() << ". " << endl; // Include ID from Shape
			output_stream << "The centre point of the circle is (" << CentrePoint().X();
			output_stream << ", " << CentrePoint().Y() << ")." << std::endl;
			output_stream << "The radius is " << Radius() << "." << std::endl;
			output_stream << "The diameter is " << Diameter() << "." << std::endl;
			output_stream << "The area is " << Area() << "." << std::endl;
			output_stream << "The circumference is " << Circumference() << "." << std::endl;

			// Convert to string
			std::string output_string = output_stream.str();

			// Return string
			return output_string;
		}

		// Draw() - Draws the line.
		void Circle::Draw() const
		{
			cout << "This is a drawing of the circle with centre point ";
			cout << m_centre_point << " and radius " << m_radius << ".";
			cout << endl;
		}

		// << Operator - Prints to ostream
		std::ostream& operator << (std::ostream& os, const Circle& c)
		{
			// Add to ostream
			os << c.ToString();

			return os;
		}
	}
}