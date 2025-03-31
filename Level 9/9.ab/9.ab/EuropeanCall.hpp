/**************************************************************************
 * File:        EuropeanCall.hpp
 * Author:      David Leather
 * Date:        2025-03-31
 * Purpose:     Header file for EuropeanCall class
 *              Represents a European call option contract.
 *              Implements specific pricing for call options.
 *
 * Design:      1. Inherits from EuropeanOption
 *              2. Implements Price() for call options
 *              3. Implements call-specific Greeks (delta, theta)
 *
 * Version:     1.1
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
 * Version 1.1: 2025-03-31 - Added delta() and theta() functions.
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

	// Greek calculations - Specific to European Call
	
	// Delta - derivative of option
	NT delta() const {
		NT T = this->getT();
		NT b = this->getB();
		NT r = this->getR();
		NT d1_val = d1();

		return N(d1_val) * exp((b - r) * T);
	}

	// Theta - negative of derivative of call price wrt to time
	NT theta() const {
		NT S = this->getS();
		NT T = this->getT();
		NT sig = this->getSig();
		NT b = this->getB();
		NT r = this->getR();
		NT K = this->getK();
		NT d1_val = d1();
		NT d2_val = d2();

		return -((S * sig * exp((b - r) * T) * n(d1_val)) / (2.0 * sqrt(T)))
			- (b - r) * S * exp((b - r) * T) * N(d1_val) - r * K * exp(-r * T)
			* N(d2_val);
	}
};

#endif // EUROPEAN_CALL_HPP
