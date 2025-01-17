/******************************************************
 * File:		Line.hpp
 * Author:		David Leather
 * Date:		2025-01-13
 * Purpose:		Header file for the Line class. This class should:
 *					P1() :: Point 1 :: Point Class
 *					P2() :: Point 2 :: Point Class
 *					Length() :: Length of line = P1.distance(P2)
 *					ToString() :: std::string :: Describes line
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 ******************************************************/

#include <string>
#include "Point.hpp"
#include "Line.hpp"
#include <sstream>

// Default constructor
Line::Line()
{
	m_pnt1 = Point();
	m_pnt2 = Point();
}

// Constructor with stard and end point
Line::Line(const Point& pnt1, const Point& pnt2)
{
	m_pnt1 = pnt1;
	m_pnt2 = pnt2;
}

// Copy constructor
Line::Line(const Line& line)
{
	m_pnt1 = line.m_pnt1;
	m_pnt2 = line.m_pnt2;
}

// Destructor
Line::~Line() {};

// Getter for start point
Point Line::P1() const
{
	return m_pnt1;
}

// Getter for end point
Point Line::P2() const
{
	return m_pnt2;
}

// Setter for start point
void Line::P1(const Point& pnt)
{
	m_pnt1 = pnt;
}

// Setter for end point
void Line::P2(const Point& pnt)
{
	m_pnt2 = pnt;
}

// Returns "Line formed by Points () and ()."
std::string Line::ToString() const
{
	// Initalize stringstream
	std::stringstream output_stream;

	// Write to stream
	output_stream << "This is the line from (" << m_pnt1.X() << ", ";
	output_stream << m_pnt1.Y() << ") and (" << m_pnt2.X() << ", ";
	output_stream << m_pnt2.Y() << ").";

	// Convert to string
	std::string output_string = output_stream.str();

	// Return string
	return output_string;

}

// Returns the length of the line
double Line::Length() const
{
	return m_pnt1.Distance(m_pnt2);
}