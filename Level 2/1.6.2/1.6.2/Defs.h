// Author: David Leather. Date: 01/06/2025
// QuantNet C++ Course 1. Level 2. Section 1.6. Exercise 2. 
// Purpose: Header file MAX2 and MAX3 macros

#ifndef DEFS_H
#define DEFS_H

#define MAX2(a, b) (a > b) ? a : b
#define MAX3(a, b, c) (a > b) ? MAX2(a, c) : MAX2(b, c)

#endif