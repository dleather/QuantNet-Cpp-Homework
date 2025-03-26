/***************************************************************************
 * File:		main_4_2b_2.cpp
 * Author:		David Leather
 * Date:		2025-03-26
 * Purpose:		Test the NumericArray<T> class.
 *
 * Version:		1.1
 *
 * Change Log:
 * Version 1.0: 2025-03-24 - Initial implementation.
 * Version 1.1: 2025-03-24 - Now explicitly catches ArrayException.

 *****************************************************************************/


#include <iostream>
#include "DavidLeather.hpp"

using namespace std;
using namespace DavidLeather::Containers;
using namespace DavidLeather::CAD;

int main() {
    // Test with doubles
    cout << "Testing NumericArray with doubles:" << endl;

    // Create two arrays
    NumericArray<double> doubleArray1(3);
    doubleArray1[0] = 1.5;
    doubleArray1[1] = 2.5;
    doubleArray1[2] = 3.5;

    NumericArray<double> doubleArray2(3);
    doubleArray2[0] = 0.5;
    doubleArray2[1] = 1.0;
    doubleArray2[2] = 1.5;

    // Display arrays
    cout << "Array1: ";
    for (unsigned i = 0; i < doubleArray1.Size(); i++) {
        cout << doubleArray1[i] << " ";
    }
    cout << endl;

    cout << "Array2: ";
    for (unsigned i = 0; i < doubleArray2.Size(); i++) {
        cout << doubleArray2[i] << " ";
    }
    cout << endl;

    // Test scaling
    NumericArray<double> scaledArray = doubleArray1 * 2.0;
    cout << "Array1 * 2.0: ";
    for (unsigned i = 0; i < scaledArray.Size(); i++) {
        cout << scaledArray[i] << " ";
    }
    cout << endl;

    // Test addition
    try {
        NumericArray<double> sumArray = doubleArray1 + doubleArray2;
        cout << "Array1 + Array2: ";
        for (unsigned i = 0; i < sumArray.Size(); i++) {
            cout << sumArray[i] << " ";
        }
        cout << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    // Test dot product
    try {
        double dotProduct = doubleArray1.DotProduct(doubleArray2);
        cout << "Dot product: " << dotProduct << endl;
    }
    catch (const ArrayException& e) {
        cout << "Exception: " << e.GetMessage() << endl;
    }

    // Test with different size arrays
    NumericArray<double> doubleArray3(2);
    cout << "\nTesting with different size arrays:" << endl;
    try {
        NumericArray<double> sumArray = doubleArray1 + doubleArray3;
    }
    catch (const ArrayException& e) {
        cout << "Exception: " << e.GetMessage() << endl;
    }

    return 0;

    // Type Assumptions: This code should work for any sub-types of int and float
    //  such as int, unsigned, short, long, float, double, float32, float64,...
    // Yes, I can create a numeric array with Point objects but the * operator
    //  and the DotProduct member function will not work. The + operator would 
    //  work because there is a method to add two Point objects.
}