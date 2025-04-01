/**************************************************************************
 * File:        PerpetualAmericanCall.hpp
 * Author:      David Leather
 * Date:        2025-04-01
 * Purpose:     Header file for PerpetualAmericanCall class
 *              Represents a PerpetualAmerican call option contract.
 *              Implements specific pricing for call options.
 *
 * Design:      1. Inherits from PerpetualAmericanOption
 *              2. Implements Price() for call options
 *
 * Version:     1.0
 *
 * Change Log:
 * Version 1.0: 2025-04-01 - Initial implementation.
 *****************************************************************************/

#ifndef PERPETUAL_AMERICAN_CALL_HPP
#define PERPETUAL_AMERICAN_CALL_HPP

#include "OptionContract.hpp"
#include "PerpetualAmericanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <cmath>

template<typename NT = double>
class PerpetualAmericanCall : public PerpetualAmericanOption<NT> {
public:
	// Default Constructor
	PerpetualAmericanCall() : PerpetualAmericanOption<NT>() {}

	// Parametric constructor
	PerpetualAmericanCall(NT S, NT K, NT r, NT sig, NT b = 0)
		: PerpetualAmericanOption<NT>(S, K, r, sig, b) {}

	// Copy constructor
	PerpetualAmericanCall(const PerpetualAmericanCall<NT>& source)
		: PerpetualAmericanOption<NT>(source) {}

	// Destructor
	virtual ~PerpetualAmericanCall() {}

	// Implementation of Price method for call option
	NT price() const override
	{
		// Initialize parameters
		const NT epsilon = 1e-10;	// Tolerance for comparing if y1 if close to unity
		NT S = this->getS();
		NT K = this->getK();
		NT r = this->getR();
		NT b = this->getB();
		NT sig = this->getSig();

		// Compute y1
		NT y1 = 0.5 - (b / pow(sig, 2));
		y1 += sqrt(pow((b / pow(sig, 2)) - 0.5, 2) + (2.0 * r / pow(sig, 2)));

		if (fabs(y1 - 1.0) > epsilon)
		{
			return (K / (y1 - 1)) * pow(((y1 - 1) / y1) * (S / K), y1);
		}
		else
		{
			return S;
		}
	}

	// Implement clone method
	virtual boost::shared_ptr<PerpetualAmericanOption<NT>> clone() const override
	{
		return boost::make_shared<PerpetualAmericanCall<NT>>(*this);
	}

};

#endif	// PERPETUAL_AMERICAN_CALL_HPP
