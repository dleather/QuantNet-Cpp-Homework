/******************************************************
 * File:		Point.cpp
 * Author:		David Leather
 * Date:		2025-01-13
 * Purpose:		Source file for the Point class, which is for Cartesian coords.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 ******************************************************/

#include "Point.hpp"	// Self-defined Point class header file
#include <sstream>		// Used for std::stringstream object
#include <string>		// For C++ string type output

// Constructor
Point::Point() {
	m_x = 0.0;
	m_y = 0.0;
}

// Destructor
Point::~Point() {}

// GetX - Returns the X-coordinate
double Point::GetX()
{
	return m_x;
}

// GetY - Returns the X-coordinate
double Point::GetY()
{
	return m_y;
}

// SetX - Sets the X-coordinate
void Point::SetX(double x)
{
	m_x = x;
}

// SetY - Sets the Y-coordinate
void Point::SetY(double y)
{
	m_y = y;
}

// ToString - Prints "Point(m_x, m_y)"
std::string Point::ToString()
{
	// Initalize stream
	std::stringstream output_ss;

	// Write to stream
	output_ss << "Point(" << m_x << ", " << m_y << ")";

	// Convert to string
	std::string output = output_ss.str();

	// Return string
	return output;

}