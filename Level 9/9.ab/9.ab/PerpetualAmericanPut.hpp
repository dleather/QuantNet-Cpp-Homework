/**************************************************************************
 * File:        PerpetualAmericanPut.hpp
 * Author:      David Leather
 * Date:        2025-04-01
 * Purpose:     Header file for PerpetualAmericanPut class
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

#ifndef PERPETUAL_AMERICAN_PUT_HPP
#define PERPETUAL_AMERICAN_PUT_HPP

#include "OptionContract.hpp"
#include "PerpetualAmericanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <cmath>

template<typename NT = double>
class PerpetualAmericanPut : public PerpetualAmericanOption<NT> {
public:
	// Default Constructor
	PerpetualAmericanPut() : PerpetualAmericanOption<NT>() {}

	// Parametric constructor
	PerpetualAmericanPut(NT S, NT K, NT r, NT sig, NT b = 0)
		: PerpetualAmericanOption<NT>(S, K, r, sig, b) {}

	// Copy constructor
	PerpetualAmericanPut(const PerpetualAmericanPut<NT>& source)
		: PerpetualAmericanOption<NT>(source) {}

	// Destructor
	virtual ~PerpetualAmericanPut() {}

	// Implementation of Price method for call option
	NT price() const override
	{
		// Initialize parameters
		const NT epsilon = 1e-10;	// For checking if y2 is close to unity
		NT S = this->getS();
		NT K = this->getK();
		NT r = this->getR();
		NT b = this->getB();
		NT sig = this->getSig();

		// Compute y1
		NT y2 = 0.5 - (b / pow(sig, 2));
		y2 -= sqrt(pow((b / pow(sig, 2)) - 0.5, 2) + (2.0 * r / pow(sig, 2)));

		if (fabs(y2 - 1.0) > epsilon)
		{
			return (K / (1 - y2)) * pow(((y2 - 1) / y2) * (S / K), y2);
		}
		else
		{
			return S;
		}
	}

	// Implement clone method
	virtual boost::shared_ptr<PerpetualAmericanOption<NT>> clone() const override
	{
		return boost::make_shared<PerpetualAmericanPut<NT>>(*this);
	}

};

#endif	// PERPETUAL_AMERICAN_PUT_HPP
