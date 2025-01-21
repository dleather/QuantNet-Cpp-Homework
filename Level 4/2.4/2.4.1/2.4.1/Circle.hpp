/******************************************************
 * File:		Circle.hpp
 * Author:		David Leather
 * Date:		2025-01-17
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
 * Version:		1.1
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 * Version 1.1: 2025-01-17 - Added assignment operator.
 ******************************************************/

#ifndef Circle_HPP
#define Circle_HPP

#define _USE_MATH_DEFINES	// For M_PI constant
#include <string>
#include "Point.hpp"

class Circle
{
private:
	double m_radius;
	Point m_centre_point;

public:
	Circle();									// Default Constructor a unit circle at
												//	origin
	Circle(const Point& pnt, double r);			// Constructor with input
	Circle(const Circle& circ);					// Copy constructor
	~Circle();									// Destructor
	Circle& operator = (const Circle& source);	// Assignment operator
	Point CentrePoint() const;					// Getter of CentrePoint
	void CentrePoint(const Point& pnt);			// Setter of CentrePoint
	double Radius() const;						// Getter of radius
	void Radius(double r);						// Setter of radius
	double Diameter() const;					// Returns the diameter: 2 * r
	double Area() const;						// Returns the area: pi * r * r
	double Circumference() const;				// Returns the circumference: 2 * pi * r;
	std::string ToString() const;				// Describes the circle.

};

#endif