/**************************************************************************
 * File:        EuropeanPut.hpp
 * Author:      David Leather
 * Date:        2025-03-28
 * Purpose:     Header file for EuropeanPut class
 *              Represents a European put option contract.
 *              Implements specific pricing for put options.
 *
 * Design:      1. Inherits from EuropeanOption
 *              2. Implements price() for put options
 *              3. Implements call-specific Greeks (delta, theta)
 *
 * Version:     1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
 * Version 1.1: 2025-03-31 - Added functions for delta() and theta()
 *****************************************************************************/

#ifndef EUROPEAN_PUT_HPP
#define EUROPEAN_PUT_HPP

#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "NormalDistribution.hpp"

template<typename NT = double>
class EuropeanPut : public EuropeanOption<NT> {
public:
	// Default Constructor
	EuropeanPut() : EuropeanOption<NT>() {}

	// Parametric constructor
	EuropeanPut(NT S, NT K, NT T, NT r, NT sig, NT b = 0)
		: EuropeanOption<NT>(S, K, T, r, sig, b) {}

	// Copy constructor
	EuropeanPut(const EuropeanPut<NT>& source)
		: EuropeanOption<NT>(source) {}

	// Destructor
	virtual ~EuropeanPut() {}

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

		// Generalized Black-Scholes formula for put option
		return K * exp(-r * T) * this->N(-d2) - S * exp((b - r) * T) * this->N(-d1);
	}

	// Implement clone method
	virtual boost::shared_ptr<EuropeanOption<NT>> clone() const override
	{
		return boost::make_shared<EuropeanPut<NT>>(*this);
	}

	// Greeks computation - Specific to european put

	// Delta - Derivative of Call price with respect to underlying
	NT delta() const {
		NT T = this->getT();
		NT b = this->getB();
		NT r = this->getR();
		NT d1_val = this->d1();

		return (this->N(d1_val) - 1.0) * exp((b - r) * T);
	}

	// Theta - negative of derivative of call price wrt to time
	NT theta() const {
		NT S = this->getS();
		NT T = this->getT();
		NT sig = this->getSig();
		NT b = this->getB();
		NT r = this->getR();
		NT K = this->getK();
		NT d1_val = this->d1();
		NT d2_val = this->d2();

		return -((S * sig * exp((b - r) * T) * this->n(d1_val)) / (2.0 * sqrt(T)))
			+ (b - r) * S * exp((b - r) * T) * this->N(-d1_val) + r * K* exp(-r * T)
			* this->N(-d2_val);
	}
};

#endif // EUROPEAN_PUT_HPP
