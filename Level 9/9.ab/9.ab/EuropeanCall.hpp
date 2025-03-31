/**************************************************************************
 * File:        EuropeanCall.hpp
 * Author:      David Leather
 * Date:        2025-03-28
 * Purpose:     Header file for EuropeanCall class
 *              Represents a European call option contract.
 *              Implements specific pricing for call options.
 *
 * Design:      1. Inherits from EuropeanOption
 *              2. Implements Price() for call options
 *              3. Implements call-specific Greeks (delta, theta)
 *
 * Version:     1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
 *****************************************************************************/

#ifndef EUROPEAN_CALL_HPP
#define EUROPEAN_CALL_HPP

#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

template<typename NT = double>
class EuropeanCall : public EuropeanOption<NT> {
public:
	// Default Constructor
	EuropeanCall() : EuropeanOption<NT>() {}

	// Parametric constructor
	EuropeanCall(NT S, NT K, NT T, NT r, NT sig, NT b = 0)
		: EuropeanOption<NT>(S, K, T, r, sig, b) {}

	// Copy constructor
	EuropeanCall(const EuropeanCall<NT>& source)
		: EuropeanOption<NT>(source) {}

	// Destructor
	virtual ~EuropeanCall() {}

	// Implementation of Price method for call option
	NT price() const override
	{
		// Initialize parameters
		NT S = this->getS();
		NT K = this->getK();
		NT T = this->getT();
		NT r = this->getR();
		NT b = this->getB();

		// Compute d1 and d2
		NT d1 = this->d1();
		NT d2 = this->d2();

		// Generalized Black-Scholes formula for call option
		return S * exp((b - r) * T) * this->N(d1) - K * exp(-r * T) * this->N(d2);
	}

	// Implement clone method
	virtual boost::shared_ptr<EuropeanOption<NT>> clone() const override
	{
		return boost::make_shared<EuropeanCall<NT>> (*this);
	}
};

#endif // EUROPEAN_CALL_HPP
