/******************************************************
 * File:		Point.hpp
 * Author:		David Leather
 * Date:		2025-01-13
 * Purpose:		Header file for the Point class, which is for Cartesian coords.
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 ******************************************************/

#ifndef POINT_HPP
#define POINT_HPP

#include <string> // C++ return type of string is std::string

class Point
{
public:
	Point();				// Constructor
	~Point();				// Destructor
	double GetX();			// Returns X-coordinate
	double GetY();			// Returns Y-coordinate
	void SetX(double x);	// Sets X-coordinate
	void SetY(double y);	// Sets Y-coordinate
	std::string ToString();	// Prints (X, Y)-coordinate

private:
	double m_x;				// Value of X-coordinate
	double m_y;				// Value of Y-coordinate
};

#endif	// POINT_HPP