/**************************************************************************
 * File:        PerpetualAmericanOption.hpp
 * Author:      David Leather
 * Date:        2025-04-01
 * Purpose:     Header file for PerputalAmericanOption class
 *					+ PerpetualAmericanOption(S, K, T, r, sig, b)
 *					+ price()
 *
 * Design:      1. Inherits from OptionContract
 *              2. Remains abstract with pure virtual price() method
 *
 * Version:     1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
 *****************************************************************************/

#ifndef PERPETUAL_AMERICAN_OPTION_HPP
#define PERPETUAL_AMERICAN_OPTION_HPP

#include "OptionContract.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

template <typename NT>
class PerpetualAmericanOption : public OptionContract<NT>
{
public:
	// Default Constructor
	PerpetualAmericanOption() : OptionContract<NT>() {}

	// Parametric Constructor
	PerpetualAmericanOption(NT S, NT K, NT r, NT sig, NT b = 0)
		: OptionContract<NT>(S, K, 0.0, r, sig, b) {}

	// Copy constructor
	PerpetualAmericanOption(const PerpetualAmericanOption<NT>& source)
		: OptionContract<NT>(source) {}

	// Destructor
	virtual ~PerpetualAmericanOption() {}

	// Pure virtual method - will be implemented by Call and Put classes
	virtual NT price() const override = 0;

	// Virtual clone method for making copies in derived classes
	virtual boost::shared_ptr<PerpetualAmericanOption<NT>> clone() const = 0;
};

#endif	// PERPETUAL_AMERICAN_OPTION_HPP
