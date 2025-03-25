/***************************************************************************
 * File:		main_4_2b_4.cpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Test the Stack<T> class.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-24 - Initial implementation.
 *****************************************************************************/
#include "Stack.hpp"
#include <iostream>

using namespace std;
using namespace DavidLeather::Containers;

int main()
{
    // Create a stack of integers with size 3
    Stack<int> stack(3);

    // Push elements onto the stack
    cout << "Pushing elements: 10, 20, 30" << endl;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    // Try to push to a full stack
    try
    {
        cout << "Trying to push to a full stack..." << endl;
        stack.Push(40);
    }
    catch (const StackException& e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    // Pop elements from the stack
    cout << "\nPopping elements:" << endl;
    cout << "First pop: " << stack.Pop() << endl;  // Should be 30
    cout << "Second pop: " << stack.Pop() << endl; // Should be 20
    cout << "Third pop: " << stack.Pop() << endl;  // Should be 10

    // Try to pop from an empty stack
    try
    {
        cout << "\nTrying to pop from an empty stack..." << endl;
        int value = stack.Pop();
    }
    catch (const StackException& e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}