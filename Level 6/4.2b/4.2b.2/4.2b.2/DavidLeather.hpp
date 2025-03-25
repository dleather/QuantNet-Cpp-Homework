/*******************************************************************************
 * File:		DavidLeather.hpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Header file for DavidLeather namespace. Includes sub-namespaces:
 *					- CAD
 *						- Point
 *						- Circle
 *						- Line
 *					- Container
 *						- Array
 *						- NumericArray
 *
 * Version:		1.2
 *
 * Change Log:
 * Version 1.0: 2025-01-19 - Initial implementation.
 * Version 1.1: 2025-01-21 - Included Shape Base Class
 * Version 1.2: 2025-03-24 - Inlcuded NumericArray class.
 ******************************************************************************/

#ifndef DAVIDLEATHER_HPP
#define DAVIDLEATHER_HPP


// Include all classes
#include "Shape.hpp"
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "NumericArray.hpp"

// Define namespace
namespace DavidLeather
{
	namespace CAD
	{
		// Include Shape, Point, Circle, and Line in header files for each
	}

	namespace Containers
	{
		// Include Array class in Array.hpp
	}
}

#endif // DAVIDLEATHER_HPP