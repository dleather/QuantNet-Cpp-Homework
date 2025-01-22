/***************************************************************************
 * File:		main_3_6_1.cpp
 * Author:		David Leather
 * Date:		2025-01-22
 * Purpose:		1. Create an Array object amd access an element that does not exist.
 *					Result: This code does not run.
 *				2. Place the code inside a try/catch block and if caught print msg.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-22 - Initial implementation.
 *****************************************************************************/

// Header files
#include "DavidLeather.hpp"
#include <iostream>

using namespace std;
using namespace DavidLeather::CAD;

int main() {

	// Create an Array object
	DavidLeather::Containers::Array arr;

	try
	{
		cout << arr[21] << endl;
	}
	catch (int err)
	{
		if (err == -1)
		{
			cout << "The index to access the Array element is out-of-bounds.";
			cout << endl;
		}
	}

	return 0;

}