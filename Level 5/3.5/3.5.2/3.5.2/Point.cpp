/*******************************************************************************
 * File:		Point.cpp
 * Author:		David Leather
 * Date:		2025-01-21
 * Purpose:		Source file for the Point class, which is for Cartesian coords.
 * Version:		1.12
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 * Version 1.1: 2025-01-13 - Added DistanceOrigin() and Distance(Point p) fns.
 * Version 1.2: 2025-01-13 - Print message in constructor and destructor.
 * Version 1.3: 2025-01-13 - Changed Distance() function to Pass by Reference
 * Version 1.4: 2025-01-13 - Replace SetX and GetX with just X.
 *								Replace DistanceOrigin with Distance().
 * Version 1.5: 2025-01-13 - Declared const functions.
 * Version 1.6: 2025-01-13 - Removed getter and setters due to inlining.
 * Version 1.7: 2025-01-17 - Added -, +, *, ==, =, and *= operators.
 * Version 1.8: 2025-01-17 - Added << operator.
 * Version 1.9: 2025-01-17 - Added constructor with equal x- and y-coords.
 * Version 1.10: 2025-01-17 - Made the << operator a friend functions.
 * Version 1.11: 2025-01-19 - Added to DavidLeather::CAD namespace
 * Version 1.12: 2025-01-21 - Changes constructors to : syntax
 * Version 1.13: 2025-01-21 - Made Point class derived from Shape class
 ******************************************************************************/

#include "Point.hpp"	// Self-defined Point class header file
#include <sstream>		// Used for std::stringstream object
#include <string>		// For C++ string type output
#include <cmath>		// For std::sqrt() function
#include <iostream>		// For printing messages in constructor and destructor
#include "Shape.hpp"

namespace DavidLeather
{
	namespace CAD
	{
		// Constructor
		Point::Point() : Shape(), m_x(0.0), m_y(0.0) {}

		// Copy constructor
		Point::Point(const Point& pnt) : Shape(pnt), m_x(pnt.m_x), m_y(pnt.m_y) {}

		// Constructor with inputs
		Point::Point(double x, double y) : Shape(), m_x(x), m_y(y) {}

		// Construct where x-coord = y-coords
		Point::Point(double x) : Shape(), m_x(x), m_y(x) {}

		// Destructor
		Point::~Point() {}

		// Negative the coordinates
		Point Point::operator - () const
		{
			return Point(-m_x, -m_y);
		}

		// Scale the coordinates
		Point Point::operator * (double factor) const
		{
			return Point(factor * m_x, factor * m_y);
		}

		// Add the coordinates
		Point Point::operator + (const Point& p) const
		{
			return Point(m_x + p.m_x, m_y + p.m_y);
		}

		// Equally compare operator
		bool Point::operator == (const Point& p) const
		{
			return (m_x == p.m_x) && (m_y == p.m_y);
		}

		// Assignment operator
		Point& Point::operator = (const Point& source)
		{
			// Prevents self-assignmet
			if (this == &source)
			{
				return *this;
			}

			// Initalize base class
			Shape::operator = (source);

			// Set data
			m_x = source.m_x;
			m_y = source.m_y;

			return *this;
		}

		// Scale and assign operator
		Point& Point::operator *= (double factor)
		{
			// Scale
			m_x *= factor;
			m_y *= factor;

			return *this;
		}

		// ToString - Prints "Point(m_x, m_y)"
		std::string Point::ToString() const
		{
			// Initalize stream
			std::stringstream output_ss;

			// Write to stream
			output_ss << Shape::ToString();
			output_ss << "Point(" << m_x << ", " << m_y << ")";

			// Convert to string
			std::string output = output_ss.str();

			// Return string
			return output;

		}

		// DistanceOrigin() - Computes the distance to the origin (0, 0)
		double Point::Distance() const
		{
			// Return L2-norm: ((x - 0)^2 + (y-0)^2)^(1/2)
			return std::sqrt(m_x * m_x + m_y * m_y);
		}

		// Distance() - Computes the distance from the inputted point
		double Point::Distance(const Point& p) const
		{
			// Get input x and y coordinates
			double x_in = p.m_x;
			double y_in = p.m_y;

			// Computes distances
			double x_dist = x_in - m_x;
			double y_dist = y_in - m_y;

			// Return L2-norm
			return std::sqrt(x_dist * x_dist + y_dist * y_dist);
		}

		// << Operator - Prints to ostream
		std::ostream& operator << (std::ostream& os, const Point& p)
		{
			// Add to ostream
			os << "Point(" << p.m_x << ", " << p.m_y << ").";

			return os;
		}
	}
}