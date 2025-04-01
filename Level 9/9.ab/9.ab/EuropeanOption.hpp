/**************************************************************************
 * File:        EuropeanOption.hpp
 * Author:      David Leather
 * Date:        2025-03-31
 * Purpose:     Header file for EuropeanOption class
 *					+ EuropeanOption(S, K, T, r, sig, b)
 *					+ price()
 *					+ putCallParityCheck()
 *					+ putFromCall()
 *					+ callFromPut()
 *
 * Design:      1. Inherits from OptionContract
 *              2. Remains abstract with pure virtual price() method
 *              3. Implements helper methods for d1, d2 using Boost
 *              4. Provides methods for Greeks calculations
 *              5. Implements put-call parity checks
 *
 * Version:     1.3
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
 * Version 1.1: 2025-03-29 - Implemented put-call parity check and conversion.
 * Version 1.2: 2025-03-31 - Implemented Gamma an Vega formulas
 * Version 1.2: 2025-03-31 - Implemented divided difference methods.
 *****************************************************************************/

#ifndef EUROPEAN_OPTION_HPP
#define EUROPEAN_OPTION_HPP

#include <cmath>
#include "NormalDistribution.hpp"
#include "OptionContract.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

template <typename NT>
class EuropeanOption : public OptionContract<NT> 
{
protected:
	// Normal PDF helper function
	NT n(NT x) const
	{
		return NormalDistribution<NT>::pdf(x);
	}

	// Normal CDF helper function
	NT N(NT x) const
	{
		return NormalDistribution<NT>::cdf(x);
	}

public:
	// Default Constructor
	EuropeanOption() : OptionContract<NT>() {}

	// Parametric Constructor
	EuropeanOption(NT S, NT K, NT T, NT r, NT sig, NT b = 0)
		: OptionContract<NT>(S, K, T, r, sig, b) {}

	EuropeanOption(const EuropeanOption<NT>& source)
		: OptionContract<NT>(source) {}

	// Destructor
	virtual ~EuropeanOption() {}

	// Pure virtual method - will be implemented by Call and Put classes
	virtual NT price() const override = 0;

	// Common methods for Black-Scholes calculations

	// Calculate d1 parameter from Black-Scholes formula
	NT d1() const {
		NT S = this->getS();
		NT K = this->getK();
		NT T = this->getT();
		NT r = this->getR();
		NT sig = this->getSig();
		NT b = this->getB();

		return (log(S / K) + (b + 0.5 * sig * sig) * T) / (sig * sqrt(T));
	}

	// Calculate d2 parameter from Black-Scholes formula
	NT d2() const {
		return d1() - this->getSig() * sqrt(this->getT());
	}

	// Calculate put price from call price using put-call parity
	static NT callToPut(const EuropeanOption<NT>& call, NT C) {
		NT S = call.getS();
		NT K = call.getK();
		NT T = call.getT();
		NT r = call.getR();

		return C + K * exp(-r * T) - S;
	}

	// Calculate call price from put price using put-call parity
	static NT putToCall(const EuropeanOption<NT>& put, NT P) {
		NT S = put.getS();
		NT K = put.getK();
		NT T = put.getT();
		NT r = put.getR();

		return P - K * exp(-r * T) + S;
	}

	// Put-call parity validation
	static bool putCallParityCheck(
		const EuropeanOption<NT>& call,	// EuropeanCallOption object
		const EuropeanOption<NT>& put,	// EuropeanPutOption object
		NT tol = 1e-5					// Numerical tolerance
	) {
		// Extract parameters
		NT S = call.getS();
		NT K = call.getK();
		NT T = call.getT();
		NT r = call.getR();

		// Compute option prices
		NT C = call.price();
		NT P = put.price();

		// Compute both sides of put-call parity
		NT lhs = C + K * exp(-r * T);
		NT rhs = P + S;

		// Return boolean
		return fabs(lhs - rhs) < tol;
	}

	// Greek calculations - common for both call and put options

	// Gamma - second derivative of option price wrt the underlying
	NT gamma() const {
		NT S = this->getS();
		NT T = this->getT();
		NT sig = this->getSig();
		NT b = this->getB();
		NT r = this->getR();
		NT d1_val = d1();

		return n(d1_val) * exp((b - r) * T) / (S * sig * sqrt(T));
	}

	// Vega - derivative of option price wrt volatility
	NT vega() const {
		NT S = this->getS();
		NT T = this->getT();
		NT b = this->getB();
		NT r = this->getR();
		NT d1_val = d1();

		return S * sqrt(T) * exp((b - r) * T) * n(d1_val);
	}

	// Numerical approximation of delta using divided differences
	NT ddDelta(NT h = 0.001) const {
		// Create copies with slightly modified S
		boost::shared_ptr<EuropeanOption<NT>> plush = this->clone();
		plush->setS(this->getS() + h);

		boost::shared_ptr<EuropeanOption<NT>> minush = this->clone();
		minush->setS(this->getS() - h);

		// Calculate price at S+h and S-h
		NT price_plush = plush->price();
		NT price_minush = minush->price();

		// Return approximation of first derivative
		return (price_plush - price_minush) / (2.0 * h);
	}

	// Numerical approximation of gamma using divided differences
	NT ddGamma(NT h = 0.001) const {
		// Create copies with modified S
		boost::shared_ptr<EuropeanOption<NT>> center = this->clone();

		boost::shared_ptr<EuropeanOption<NT>> plush = this->clone();
		plush->setS(this->getS() + h);

		boost::shared_ptr<EuropeanOption<NT>> minush = this->clone();
		minush->setS(this->getS() - h);

		// Calculate prices
		NT price_center = center->price();
		NT price_plush = plush->price();
		NT price_minush = minush->price();

		// Return approximation of second derivative
		return (price_plush - 2.0 * price_center + price_minush) / (h * h);
	}

	// Virtual clone method for making copies in derived classes
	virtual boost::shared_ptr<EuropeanOption<NT>> clone() const = 0;
};

#endif // EUROPEAN_OPTION_HPP
