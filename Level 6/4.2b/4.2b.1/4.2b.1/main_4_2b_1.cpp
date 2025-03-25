/***************************************************************************
 * File:		main_4_2b_1.cpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Add static variable for default size to array template class.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-24 - Initial implementation.
 *****************************************************************************/

// Header files
#include <iostream>
#include "DavidLeather.hpp"

using namespace std;
using namespace DavidLeather::Containers;


int main() {

	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;

	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;

	intArray1.DefaultSize(15);

	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;

	// Output (commas are \n):
		// 10, 10, 10, 15, 15, 10

	// Explanation:
		// Calling `intArray1.DefaultSize(15);` only changes the static member variable
		// for Array<int> but Array<double> is its own class and thus seperate variable.

	return 0;

}