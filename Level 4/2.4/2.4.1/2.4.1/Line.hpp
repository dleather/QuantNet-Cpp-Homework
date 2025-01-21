/******************************************************
 * File:		Line.hpp
 * Author:		David Leather
 * Date:		2025-01-17
 * Purpose:		Header file for the Line class. This class should:
 *					P1() :: Point 1 :: Point Class
 *					P2() :: Point 2 :: Point Class
 *					Length() :: Length of line = P1.distance(P2)
 *					ToString() :: std::string :: Describes line
 *					
 * Version:		1.1
 *
 * Change Log:
 * Version 1.0: 2025-01-13 - Initial implementation.
 * Version 1.1: 2025-01-17 - Changes getters to return by const reference and
 *								added assignment operator.
 ******************************************************/

#ifndef Line_HPP
#define Line_HPP

#include <string>
#include "Point.hpp"

class Line
{
private:
	Point m_pnt1;
	Point m_pnt2;

public:
	Line();										// Default constructor
	Line(const Point& pnt1, const Point& pnt2);	// Constructor w/ start- and end-point
	Line(const Line& line);						// Copy constructor
	~Line();									// Destructor
	Line& operator = (const Line& source);		// Assignmet operator
	const Point& P1() const;					// Get point 1
	const Point& P2() const;					// Get point 2
	void P1(const Point& pnt);					// Set point 1
	void P2(const Point& pnt);					// Set point 2
	std::string ToString() const;				// Returns "Line formed by Points () and ()."
	double Length() const;						// Computes the length of the line

};

#endif