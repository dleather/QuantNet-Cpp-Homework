/******************************************************
 * File:		Point.cpp
 * Author:		David Leather
 * Date:		2025-01-13
 * Purpose:		Source file for the Point class, which is for Cartesian coords.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 * Version 1.1: 2025-01-13 - Added DistanceOrigin() and Distance(Point p) fns.
 * Version 1.2: 2025-01-13 - Print message in constructor and destructor.
 * Version 1.3: 2025-01-13 - Changed Distance() function to Pass by Reference

 ******************************************************/

#include "Point.hpp"	// Self-defined Point class header file
#include <sstream>		// Used for std::stringstream object
#include <string>		// For C++ string type output
#include <cmath>		// For std::sqrt() function
#include <iostream>		// For printing messages in constructor and destructor

// Constructor
Point::Point() {
	m_x = 0.0;
	m_y = 0.0;
	std::cout << "Constructing..." << std::endl;
}

// Copy constructor
Point::Point(const Point& pnt)
{
	// Initalize point
	m_x = pnt.m_x;
	m_y = pnt.m_y;
	std::cout << "Constructing..." << std::endl;
}

// Constructor with inputs
Point::Point(double x, double y)
{
	// Initalize point
	m_x = x;
	m_y = y;
	std::cout << "Constructing..." << std::endl;

}

// Destructor
Point::~Point() { std::cout << "Destructing..." << std::endl; }

// GetX - Returns the X-coordinate
double Point::GetX() const
{
	return m_x;
}

// GetY - Returns the X-coordinate
double Point::GetY() const
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

// DistanceOrigin() - Computes the distance to the origin (0, 0)
double Point::DistanceOrigin()
{
	// Return L2-norm: ((x - 0)^2 + (y-0)^2)^(1/2)
	return std::sqrt(m_x * m_x + m_y * m_y);
}

// Distance() - Computes the distance from the inputted point
double Point::Distance(const Point& p)
{
	// Get input x and y coordinates
	double x_in = p.GetX();
	double y_in = p.GetY();

	// Test: Can I change inputs? No.
	// p.SetX(0.0);

	// Computes distances
	double x_dist = x_in - m_x;
	double y_dist = y_in - m_y;

	// Return L2-norm
	return std::sqrt(x_dist * x_dist + y_dist * y_dist);
}