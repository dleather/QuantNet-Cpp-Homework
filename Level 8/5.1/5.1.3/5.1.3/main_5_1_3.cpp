/***************************************************************************
 * File:		main_5_1_3.cpp
 * Author:		David Leather
 * Date:		2025-03-27
 * Purpose:		Explore the boost::variant class.
 *					1. Create a typedef for a ShapeType variant that can contain:
 *						- Point, Line or Circle.
 *					2. Create a function that returns the variant in (2).
 *						2a. Ask the user for the shape they want to create
 *							as in (1).
 *						2b. Create the requested shape, assign it to the variant,
 *							and return it.
 *					3. In the main program, call function and print result by
 *						sending it to `cout`.
 *					4. Next, try to assign the variant to a `Line` variable by
 *						using the global `boost::get<T>()` function.
 *						4a. This should throw an exception when variant is not a
 *							line.
 *					5. Test application.
 *					6. Create a variant visitor that moves the shapes
 *						- Derived from `boost::static_visitor<void>
 *						- Private members for x- and y-offset.
 *						- For each shape create an `operator ()` that changes
 *							the coordinates of the shape.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-27 - Initial implementation.
 *****************************************************************************/
#include "DavidLeather.hpp"
#include <iostream>
#include <boost/variant/variant.hpp>
#include <boost/variant/get.hpp>
#include <stdexcept>

namespace DL = DavidLeather;	// Shorten namespace

// 1. Create a typedef for a ShapeType variant that can contain Point, Line, or Circle
typedef boost::variant<DL::CAD::Point, DL::CAD::Line, DL::CAD::Circle> ShapeVariant;

// 2. Create function that asks user for shape and returns ShapeVariant.
ShapeVariant CreateShape()
{
	// Initalize variables
	std::string shp_str;	// Input from user.
	ShapeVariant shp;

	// Ask user to input shape name
	std::cout << "What shape do you want to create? (Circle, Line, or Point)";
	std::cout << std::endl;

	// Get input from user
	std::cin >> shp_str;
	std::cout << "The user chose " << shp_str << "." << std::endl << std::endl;

	// If statement converting input string to output Shape
	if (shp_str == "Circle" || shp_str == "circle")
	{
		shp = DL::CAD::Circle();
	}
	else if (shp_str == "Line" || shp_str == "line")
	{
		shp = DL::CAD::Line();
	}
	else if (shp_str == "Point" || shp_str == "point")
	{
		shp = DL::CAD::Point();
	}
	else
	{
		std::string err_str = "Input is not valid. Must be \"Circle\", ";
		err_str += "\"Line\", or \"Point\"";
		throw std::invalid_argument(err_str);
	}

	return shp;

}

// 6. Create a variant visitor that move shapes
struct MoveShape : public boost::static_visitor<void>
{
private:
	double m_dx;	// X-offset
	double m_dy;	// Y-offset

public:

	// Default constructor
	MoveShape() : m_dx(0.0), m_dy(0.0) {}
	
	// Contructor with dx and dy as inputs
	MoveShape(double x, double y) : m_dx(x), m_dy(y) {}

	// Operator for Circle
	void operator () (DL::CAD::Circle& c) const
	{
		DL::CAD::Point cp = c.CentrePoint();	// Extract current center
		double new_x = cp.X() + m_dx;			// Compute new x-val of center
		double new_y = cp.Y() + m_dy;			// Compute new y-val of center
		c.CentrePoint(DL::CAD::Point(new_x, new_y));	// Update center;
	}

	// Operator for Line
	void operator () (DL::CAD::Line& l) const
	{
		DL::CAD::Point p1 = l.P1();		// Extract first point
		DL::CAD::Point p2 = l.P2();		// Extract second point
		p1.X(p1.X() + m_dx);			// Update X coordinate of first point
		p2.X(p2.X() + m_dx);			// Update X coordinate of second point
		p1.Y(p1.Y() + m_dy);			// Update Y coordinate of first point
		p2.Y(p2.Y() + m_dy);			// Update Y coordinate of second point
		l.P1(p1);						// Update first point in line
		l.P2(p2);						// Update second point in line
	}

	// Operator for Point
	void operator () (DL::CAD::Point& p) const
	{
		p.X(p.X() + m_dx);
		p.Y(p.Y() + m_dy);
	}
};

int main()
{
	// Call function: input Circle, Line, or Point.
	try
	{
		std::cout << "Printing shape..." << std::endl;
		ShapeVariant shp = CreateShape();
		std::cout << shp << std::endl << std::endl;

		// Next try to assign variant to a Line variable
		try 
		{
			DL::CAD::Line line = boost::get<DL::CAD::Line>(shp);
			std::cout << "Assignment to Line variable successful." << std::endl;
			std::cout << "The input variable must have been a Line." << std::endl;
			std::cout << std::endl;
		}
		catch (boost::bad_get& e)
		{
			std::cout << "Assignment to Line variable failed." << std::endl;
			std::cout << "`boost::bad_get` exception caught." << std::endl;
			std::cout << "The input variable must have been a Circle or Point.";
			std::cout << std::endl << std::endl;
		}

		// Lastly increment x- and y-coords by 1.0
		std::cout << "Shifting each X- and Y-coordinate by 1." << std::endl;
		MoveShape move_shape = MoveShape(1.0, 1.0);	// Instantiate visitor
		boost::apply_visitor(move_shape, shp);
		std::cout << "Printing shifted shape..." << std::endl << std::endl;
		std::cout << shp << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	return 0;
}
