/**************************************************************************
 * File:		OptionContract.hpp
 * Author:		David Leather
 * Date:		2025-03-28
 * Purpose:		Header file for OptionContract ABC
 *					- S		:: price of underlying
 *					- K		:: strike price
 *					- T		:: time to expiry
 *					- r		:: short rate
 *					- sig	:: volatility parameter
 *					- b		:: cost to carry
 *					+ OptionContract(S, K, T, t, sig)
 *					+ price() - PVMF to price options.
 *
 * Design choice:	1. ABC Class for all future options. Hierarchy:
 *						- OptionContract -> EuropeanOption -> EuropeanPut
 *					2. Parametric template for numeric type, `NT`
 *					3. VPMF `price()` to be redefined by subclass
 *					4. Validation checking
 *					5. Cost to carry parameter defaults to 0.
 *					6. Everything defined solely in the header.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-27 - Initial implementation.
 *****************************************************************************/

#ifndef OPTION_CONTRACT_HPP
#define OPTION_CONTRACT_HPP

#include <stdexcept>

template<typename NT>	// Numeric Type
class OptionContract
{
private:
	NT m_S;	// Price of underlying security
	NT m_K;	// Strike price
	NT m_T;	// Time to expiry
	NT m_r;	// Short rate
	NT m_sig;	// Standard deviation
	NT m_b;	// Cost to carry

public:
	// Default Constructor
	OptionContract() : m_S(), m_K(), m_T(), m_r(), m_sig(), m_b() {};

	// Copy Constructor
	OptionContract(const OptionContract<NT>& source)
		: m_S(source.m_S), m_K(source.m_K), m_T(source.m_T), m_r(source.m_r),
			m_sig(source.m_sig), m_b(source.m_b) {};

	// Parameter constructor
	OptionContract(NT S, NT K, NT T, NT r, NT sig, NT b)
	{

		// Validation check
		if (S <= 0) throw std::invalid_argument("Underlying price must be positive");
		if (K <= 0) throw std::invalid_argument("Strike price must be positive");
		if (T < 0) throw std::invalid_argument("Time to expiry must be non-negative");
		if (sig < 0) throw std::invalid_argument("Volatility must be non-negative");

		// Assignment
		m_S = S;
		m_K = K;
		m_T = T;
		m_r = r;
		m_sig = sig;
		m_b = b;

	};

	// Destructor
	virtual ~OptionContract() {};

	// VPMF - Price
	virtual NT price() const = 0;	// PMVF to compute price of subtypes

	// Getters
	NT S() const { return m_S; };
	NT K() const { return m_K; };
	NT T() const { return m_T; };
	NT r() const { return m_r; };
	NT sig() const { return m_sig; };
	NT b() const { return m_b; };

	// Setters
	inline void S(NT input)
	{
		if (input <= 0) throw std::invalid_argument("Underlying price must be positive");
		m_S = input;
	}
	inline void K(NT input)
	{
		if (input <= 0) throw std::invalid_argument("Strike price must be positive");
		m_K = input;
	}
	inline void T(NT input)
	{
		if (input < 0) throw std::invalid_argument("Time-to-expiry must be non-negative");
		m_T = input;
	}
	inline void r(NT input) { m_r = input; }
	inline void sig(NT input)
	{
		if (input < 0) throw std::invalid_argument("Std. dev. must be non-negative");
		m_sig = input;
	}
	inline void b(NT input) { m_b = input; }
	inline void setParameters(NT S, NT K, NT T, NT r, NT sig, NT b = 0)
	{
		// Validation check
		if (S <= 0) throw std::invalid_argument("Underlying price must be positive");
		if (K <= 0) throw std::invalid_argument("Strike price must be positive");
		if (T < 0) throw std::invalid_argument("Time to expiry must be non-negative");
		if (sig < 0) throw std::invalid_argument("Volatility must be non-negative");

		// Assignment
		m_S = S;
		m_K = K;
		m_T = T;
		m_r = r;
		m_sig = sig;
		m_b = b;
	}
};

#endif	// OPTION_CONTRACT_HPP
