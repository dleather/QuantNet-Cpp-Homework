/*****************************************************************************
 * File:		Stack.hpp
 * Author:		David Leather
 * Date:		2025-03-24
 * Purpose:		Header file for the Stack template class. Uses composition with Array.
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
#ifndef STACK_HPP
#define STACK_HPP

#include "Array.hpp"
#include <stdexcept>

namespace DavidLeather
{
	namespace Containers
	{
		class StackException : public std::exception
		{

		public:
			StackException() noexcept = default; // Default constructor
			virtual const char* what() const noexcept override
			{
				return "Stack exception occurred";
			}
		};

		class StackFullException : public StackException
		{
		public:
			StackFullException() noexcept = default; // Default constructor
			virtual const char* what() const noexcept override
			{
				return "Stack is full";
			}
		};

		class StackEmptyException : public StackException
		{
		public:
			StackEmptyException() noexcept = default; // Default constructor
			virtual const char* what() const noexcept override
			{
				return "Stack is empty";
			}
		};

		template <typename T>
		class Stack
		{
		private:
			Array<T> m_stack;
			unsigned m_current;

		public:
			// Constructors
			Stack();						// Default constructor
			Stack(unsigned size);			// Size constructor
			Stack(const Stack<T>& source);	// Copy constructor

			// Destructors
			virtual ~Stack();

			// Assignment operator
			Stack<T>& operator = (const Stack<T>& source);

			// Stack assignment and designment functions - Push() and Pop()
			void Push(const T& element);
			T Pop();
		};
	}
}

#ifndef STACK_CPP
#include "Stack.cpp"
#endif	// STACK_CPP

#endif	// STACK_HPP