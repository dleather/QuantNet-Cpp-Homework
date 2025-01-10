/******************************************************
 * File:		Defs.h
 * Author:		David Leather
 * Date:		2025-01-06
 * Purpose:		Header file MAX2 and MAX3 macros
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-01-06 - Initial implementation.
 ******************************************************/

#ifndef DEFS_H
#define DEFS_H

// MAX2 returns max(a, b)
#define MAX2(a, b) (a > b) ? a : b

// MAX3 returns max(a, b, c)
#define MAX3(a, b, c) (a > b) ? MAX2(a, c) : MAX2(b, c)

#endif