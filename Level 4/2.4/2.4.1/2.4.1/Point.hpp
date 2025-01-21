/*****************************************************************************
 * File:		Point.hpp
 * Author:		David Leather
 * Date:		2025-01-17
 * Purpose:		Header file for the Point class, which is for Cartesian coords.
 * Version:		1.6
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 * Version 1.1: 2025-01-13 - Added DistanceOrigin() and Distance(Point p) fns.
 * Version 1.2: 2025-01-13 - Changed Distance() function to Pass by Reference
 * Version 1.3: 2025-01-13 - Replace SetX and GetX with just X.
 *								Replace DistanceOrigin with Distance().
 * Version 1.4: 2025-01-13 - Declared const functions.
 * Version 1.5: 2025-01-13 - Changes getter and setter functions to inline.
 * Version 1.6: 2025-01-17 - Added -, +, *, ==, =, and *= operators.
 *****************************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

#include <string> // C++ return type of string is std::string

class Point
{
public:
	Point();									// Constructor
	Point(const Point& pnt);					// Copy constructor
	Point(double x, double y);					// Constructor with inputs
	~Point();									// Destructor
	Point operator - () const;					// Negative the coordinates
	Point operator * (double factor) const;		// Scale the coordinates
	Point operator + (const Point& p) const;	// Add the coordinates
	bool operator == (const Point& p) const;	// Equally compare operator
	Point& operator = (const Point& source);	// Assignment operator
	Point& operator *= (double factor);			// Scale the coordinates & assign
	double X() const;							// Returns X-coordinate
	double Y() const;							// Returns Y-coordinate
	void X(double x) { m_x = x; }				// Sets X-coordinate
	void Y(double y) { m_y = y; }				// Sets Y-coordinate
	std::string ToString() const;				// Prints (X, Y)-coordinate
	double Distance() const;					// Calculates the distance to the origin (0, 0)
	double Distance(const Point& p) const;		// Calculates the distance between two points.

private:
	double m_x;									// Value of X-coordinate
	double m_y;									// Value of Y-coordinate
};

// Inline Getter of X
inline double Point::X() const { return m_x; }

// Inline Getter of Y
inline double Point::Y() const { return m_y; }


#endif	// POINT_HPP