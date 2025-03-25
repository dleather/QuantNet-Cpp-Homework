/***************************************************************************
 * File:		main_4_2a_1.cpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Turn Array class into a template class.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-24 - Initial implementation.
 *****************************************************************************/

// Header files
#include "DavidLeather.hpp"
#include <iostream>

using namespace std;
using namespace DavidLeather::CAD;
using namespace DavidLeather::Containers;

int main() {
	// Declare variables
	unsigned int size;

	// Create an Array object
	cout << "Input size: ";
	cin >> size;
	DavidLeather::Containers::Array<Point> points(size);
	cout << "The first element is " << points[0] << "." << endl;
	cout << "The last element is " << points[size-1] << "." << endl;

	return 0;

}