/*****************************************************************************
 * File:		Stack.cpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Implementation file for the Stack template class. Uses composition with Array.
 *				- Composition with Array:
 *					-m_stack - Array of elements
 *					-m_current - current index (top of stack)
 *				- Stack Operations:
 *					+Push()     - Adds element to top of stack
 *					+Pop()      - Removes and returns top element
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-24 - Initial implementation.
 *****************************************************************************/
#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"
#include "Array.hpp"
#include <stdexcept>

using namespace DavidLeather::Containers;

namespace DavidLeather
{
	namespace Containers
	{
		// Default constructor
		template <typename T>
		Stack<T>::Stack() : m_stack(), m_current(0) {}

		// Size constuctor
		template <typename T>
		Stack<T>::Stack(unsigned size) : m_stack(size), m_current(0) {}

		// Copy constructor
		template <typename T>
		Stack<T>::Stack(const Stack<T>& source)
			: m_stack(source.m_stack), m_current(source.m_current) {}

		// Destructor
		template <typename T>
		Stack<T>::~Stack() {}

		// Assignment operator
		template <typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& source)
		{
			// Check for self-assignment
			if (this == &source)
			{
				return *this;
			}

			// Else, assign both m_stack and m_current
			m_stack = source.m_stack;
			m_current = source.m_current;

			return *this;
		}

		// Push(element) - Adds element to top of stack (m_current)
		template <typename T>
		void Stack<T>::Push(const T& element)
		{
			unsigned curr_ndx = m_current;		// Store in case of exception
			try
			{
				m_stack[m_current] = element;	// Assign to stack
				m_current++;					// Increment
			}
			catch (const ArrayException& e)
			{
				m_current = curr_ndx;			// Revert to old m_current value
				throw StackFullException();
			}
		}

		// Pop() - Returns the top element (and then (m_current)
		template <typename T>
		T Stack<T>::Pop()
		{
			m_current--;	// Decrement m_current
			try
			{
				return m_stack[m_current];
			}
			catch (const ArrayException& e)
			{
				m_current = 0;		// Reset m_current to zero
				throw StackEmptyException();
			}
		}
	}
}

#endif	// STACK_CPP