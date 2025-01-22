/***************************************************************************
 * File:		main_3_6_2.cpp
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
using namespace DavidLeather::Containers;

int main() {

	// Create an Array object
	DavidLeather::Containers::Array arr;

	try
	{
		cout << arr[21] << endl;
	}
	catch (const ArrayException& exception)
	{
		cout << "Array Exception: " << exception.GetMessage() << endl;
	}

	return 0;

}