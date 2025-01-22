/*****************************************************************************
 * File:		main_2_6_1.cpp
 * Author:		David Leather
 * Date:		2025-01-19
 * Purpose:		Tests the DavidLeather namespace/
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-19 - Initial implementation.
 *****************************************************************************/

// Header files
#include "DavidLeather.hpp"
#include <iostream>

using namespace std;

int main()
{
	DavidLeather::CAD::Line l;
	/***************************************************************************
	 *	First Run Output:
	 *		Constructing...
	 *		Constructing...
	 *		Constructing...
	 *		Assigning...
	 *		Destructing...
	 *		Constructing...
	 *		Assigning...
	 *		Destructing...
	 *  	Destructing...
	 *		Destructing...
	 **************************************************************************/

	/***************************************************************************
	 *	Second Run Output:
	 *		Constructing...
	 *		Constructing...
	 *  	Destructing...
	 *		Destructing...
	 **************************************************************************/

	// Note: Turned off print statements for constructor and destructor

	return 0;
}