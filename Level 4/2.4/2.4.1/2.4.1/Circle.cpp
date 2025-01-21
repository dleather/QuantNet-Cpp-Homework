/******************************************************
 * File:		Circle.cpp
 * Author:		David Leather
 * Date:		2025-01-17
 * Purpose:		Source file for the Circle class:
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
 *
 ******************************************************/

#define _USE_MATH_DEFINES	// For M_PI constant
#include <sstream>
#include <string>
#include "Point.hpp"
#include "Circle.hpp"

// Default constructor
Circle::Circle()
{
	m_centre_point = Point();
	m_radius = 1.0;
}

// Constructor with input
Circle::Circle(const Point& pnt, double r)
{
	m_centre_point = pnt;
	m_radius = r;
}

// Copy Constructor
Circle::Circle(const Circle& circ)
{
	m_centre_point = circ.m_centre_point;
	m_radius = circ.m_radius;
}

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