/***************************************************************************
 * File:		main_4_2b_3.cpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Test the PointArray<T> class.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-24 - Initial implementation.
 *****************************************************************************/

#include <iostream>
#include "DavidLeather.hpp"

using namespace std;
using namespace DavidLeather::Containers;
using namespace DavidLeather::CAD;

int main() {

    // Create a PointArray with 3 elements
    PointArray points(3);

    // Set points in the array
    points.SetElement(0, Point(0.0, 0.0));    // Origin
    points.SetElement(1, Point(3.0, 0.0));    // 3 units right
    points.SetElement(2, Point(3.0, 4.0));    // Up 4 units

    // Display the points
    cout << "Points in array:" << endl;
    for (unsigned i = 0; i < points.Size(); i++) {
        cout << "Point " << i << ": " << points[i] << endl;
    }

    // Calculate length
    try {
        cout << "Total length between points: " << points.Length() << endl;

        // Test with a small array (should throw exception)
        PointArray smallArray(1);
        smallArray.SetElement(0, Point(1.0, 1.0));

        cout << "Trying to calculate length with insufficient points..." << endl;
        double length = smallArray.Length();
    }
    catch (const std::exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}