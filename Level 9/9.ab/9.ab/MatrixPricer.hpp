/**************************************************************************
 * File:        MatrixPricer.hpp
 * Author:      David Leather
 * Date:        2025-04-01-2025
 * Purpose:     Header file for MatrixPricer utility class
 *              Provides functionality to price options across a range of
 *					parameters
 *              Creating price matrices for analysis.
 *
 * Design:      1. Utility class with static methods
 *              2. Template-based for flexibility
 *              3. Mesh generation for parameter ranges
 *              4. Matrix pricing for parameter combinations
 *
 * Version:     1.1
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
 * Version 1.1: 2025-04-01 - Changed from boost::function objects to std::function
 *								objects. Added overloaded method to priceRange 
 *								that defaults to price(). Created utility static
 *								functors for passing to priceRange and matrixRange.
 *****************************************************************************/

#ifndef MATRIX_PRICER_HPP
#define MATRIX_PRICER_HPP

#include <vector>
#include "OptionContract.hpp"
#include <functional>

// Class to represent a parameter range for batch pricing
template<typename NT = double>
class MeshGenerator {
private:
	std::vector<NT> m_values;

public:
	// Default constructor
	MeshGenerator() : m_values() {};

	// Copy constructor
	MeshGenerator(const MeshGenerator& source) : m_values(source.m_values) {}

	// Constructor for a range of values with step size
	MeshGenerator(NT start, NT end, NT step) {
		for (NT value = start; value <= end; value += step) {
			m_values.push_back(value);
		}
	}
	
	// Destructor
	~MeshGenerator() {};

	// Assignment operator
	MeshGenerator& operator=(const MeshGenerator& other) {
		if (this != &other) {
			m_values = other.m_values;
		}
		return *this;
	}

	// Size getter
	inline size_t size() const
	{
		return m_values.size();
	}

	// Access function via []
	inline NT operator [] (unsigned index) const
	{
		return m_values[index];
	}

	// Iterator pass-through
	typename std::vector<NT>::const_iterator begin() const
	{
		return m_values.begin();
	}
	typename std::vector<NT>::const_iterator end() const
	{
		return m_values.end();
	}
};

class MatrixPricer {
public:
	// Create a mesh array with uniform step size
	template<typename NT = double>
	static std::vector<NT> createMesh(NT start, NT end, NT h) {
		std::vector<NT> mesh;
		for (NT value = start; value <= end; value += h) {
			mesh.push_back(value);
		}
		return mesh;
	}

	// Price an option across a range of underlying asset prices
	template<typename OptionType, typename NT = double>
	static std::vector<NT> priceRange(
		const OptionType& option,
		NT S0,	// Start price
		NT S1,	// End price
		NT h,	// Step-size
		std::function<NT(const OptionType&)> func
	) {
		std::vector<NT> prices;
		prices.reserve(static_cast<unsigned>((S1 - S0) / h) + 1);

		for (NT s = S0; s <= S1; s += h) {
			OptionType optionCopy = option;		// Create a copy
			optionCopy.setS(s);					// Update S
			prices.push_back(func(optionCopy));
		}

		return prices;
	}

	// Overloaded version that uses price() by default
	template<typename OptionType, typename NT = double>
	static std::vector<NT> priceRange(
		const OptionType& option,
		NT S0,	// Start price
		NT S1,	// End price
		NT h	// Step-size
	) {
		
		// Cast the lambda to the right std::function type
		std::function<NT(const OptionType&)> priceFunc =
			[](const OptionType& opt) { return opt.price(); };
		
		return priceRange(option, S0, S1, h, priceFunc);
	}

	// Calculate prices for a 2D matrix of parameter combinations
	template<typename OptionType, typename NT = double>
	static std::vector<std::vector<NT>> priceMatrix(
		const OptionType& option,    // EuropeanCall, EuropeanPut, etc...
		MeshGenerator<NT>& param1,   // 1D Grid for 1st dimension, i.e. S
		MeshGenerator<NT>& param2,   // 1D grid for 2nd dimension, i.e. T
		std::function<void(OptionType&, NT)> setter1,  // Function object for 1st parameter
		std::function<void(OptionType&, NT)> setter2,  // Function object for 2nd parameter
		std::function<NT(const OptionType&)> calculator // Function object for calculating value
	) {
		// Initialize matrix
		std::vector<std::vector<NT>> matrix;
		matrix.reserve(param1.size());

		// Loop over param1
		for (unsigned i = 0; i < param1.size(); ++i) {
			// Initialize row
			std::vector<NT> row;
			row.reserve(param2.size());

			// Loop over second dimension
			for (unsigned j = 0; j < param2.size(); ++j) {
				OptionType optionCopy = option;     // Create a copy
				setter1(optionCopy, param1[i]);     // Set first parameter
				setter2(optionCopy, param2[j]);     // Set second parameter
				row.push_back(calculator(optionCopy)); // Use the calculator function
			}

			matrix.push_back(row);
		}

		return matrix;
	}

	// Overloaded version that defaults to using price()
	template<typename OptionType, typename NT = double>
	static std::vector<std::vector<NT>> priceMatrix(
		const OptionType& option,
		MeshGenerator<NT>& param1,
		MeshGenerator<NT>& param2,
		std::function<void(OptionType&, NT)> setter1,
		std::function<void(OptionType&, NT)> setter2
	) {
		// Cast the lambda to the right std::function type
		std::function<NT(const OptionType&)> priceFunc =
			[](const OptionType& opt) { return opt.price(); };

		return priceMatrix(
			option,
			param1,
			param2,
			setter1,
			setter2,
			priceFunc
		);
	}

	// Helper functions to create commonly used function objects
	template<typename OptionType, typename NT = double>
	static std::function<NT(const OptionType&)> priceFunctor() {
		return [](const OptionType& opt) { return opt.price(); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<NT(const OptionType&)> deltaFunctor() {
		return [](const OptionType& opt) { return opt.delta(); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<NT(const OptionType&)> gammaFunctor() {
		return [](const OptionType& opt) { return opt.gamma(); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<NT(const OptionType&)> vegaFunctor() {
		return [](const OptionType& opt) { return opt.vega(); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<NT(const OptionType&)> ddDeltaFunctor(NT h = 0.001) {
		return [h](const OptionType& opt) { return opt.ddDelta(h); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<NT(const OptionType&)> ddGammaFunctor(NT h = 0.001) {
		return [h](const OptionType& opt) { return opt.ddGamma(h); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<void(OptionType&, NT)> setSFunctor() {
		return [](OptionType& opt, NT val) { opt.setS(val); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<void(OptionType&, NT)> setTFunctor() {
		return [](OptionType& opt, NT val) { opt.setT(val); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<void(OptionType&, NT)> setKFunctor() {
		return [](OptionType& opt, NT val) { opt.setK(val); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<void(OptionType&, NT)> setRFunctor() {
		return [](OptionType& opt, NT val) { opt.setR(val); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<void(OptionType&, NT)> setSigFunctor() {
		return [](OptionType& opt, NT val) { opt.setSig(val); };
	}

	template<typename OptionType, typename NT = double>
	static std::function<void(OptionType&, NT)> setBFunctor() {
		return [](OptionType& opt, NT val) { opt.setB(val); };
	}

};

#endif // MATRIX_PRICER_HPP
