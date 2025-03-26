/***************************************************************************
 * File:		main_5_1_1.cpp
 * Author:		David Leather
 * Date:		2025-03-26
 * Purpose:		Create a program that:
 *					1. Create array of shared pointer to various for shapes.
 *						1a. Point
 *						1b. Line
 *						1c. Circle
 *					2. Print the different shapes.
 *					3. Check if the shapes are automatically deleted.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-24 - Initial implementation.
 *****************************************************************************/
#include "DavidLeather.hpp"
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;
using namespace DavidLeather::Containers;
using namespace DavidLeather::CAD;

// Convenient typedefs
typedef boost::shared_ptr<Shape> ShapePtr;	// ShapePtr -> shared_ptr<Shape>
typedef Array<ShapePtr> ShapeArray;			// ShapeArray -> Array<ShapePtr>
											//	-> Array<shared_ptr<Shape>>
int main()
{
	const unsigned arr_len = 3;	// Const parameter used for size of ShapeArrays

	// Instantiate 3 different ShapeArrays
	ShapeArray shapes(arr_len);	// ShapeArray for points

	// Set elements of each
	shapes[0] = ShapePtr(new Point(0.0, 1.0));
	shapes[1] = ShapePtr(new Line(Point(0.0, 0.0), Point(0.0,1.0)));
	shapes[2] = ShapePtr(new Circle(Point(0.0, 0.0), 1.0));


	// Print shapes
	cout << "------------------------------------------------" << endl;
	cout << "This program should print " << arr_len << " shapes: ";
	cout << "one Point, one Line, and one Circle." << endl << endl;
	cout << "Then it should print " << arr_len * 2 << " messages indicating ";
	cout << "each shape has been destroyed in memory." << endl << endl;
	cout << "This is because each Circle encompasses 2 total shapes: ";
	cout << "the circle, and the center point." << endl << endl;
	cout << "While each Line encompasses 3 shapes: the line, and it's start";
	cout << " and end points." << endl << endl;
	cout << "And each Point is a single shape." << endl << endl;
	cout << "Thus we'll see 3 + 2 + 1 = 6 destruction messages at the end.";
	cout << endl << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Beggin printing..." << endl;
	cout << "------------------------------------------------" << endl;
	for (unsigned i = 0; i < arr_len; ++i) {
		shapes[i]->Print(); cout << endl;
	}
	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Beggin destruction..." << endl;
	cout << "------------------------------------------------" << endl;

	return 0;
}