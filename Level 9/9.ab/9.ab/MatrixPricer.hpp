/**************************************************************************
 * File:        MatrixPricer.hpp
 * Author:      David Leather
 * Date:        2025-03-29
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
 * Version:     1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
 *****************************************************************************/

#ifndef MATRIX_PRICER_HPP
#define MATRIX_PRICER_HPP

#include <vector>
#include "OptionContract.hpp"

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
		NT h	// Step-size
	) {
		std::vector<NT> prices;
		prices.reserve(static_cast<unsigned>((S1 - S0) / h) + 1);

		for (NT s = S0; s <= S1; s += h) {
			OptionType optionCopy = option;		// Create a copy
			optionCopy.S(s);					// Update S
			prices.push_back(optionCopy.price());
		}

		return prices;
	}

	// Calculate prices for a 2D matrix of parameter combinations
	template<typename OptionType, typename NT = double>
	static std::vector<std::vector<NT>> priceMatrix(
		const OptionType& option,	// EuropeanCall, EuropeanPut, etc...
		MeshGenerator<NT>& param1,	// 1D Grid for 1st dimension, i.e. S
		MeshGenerator<NT>& param2,	// 1D grid for 2nd dimension, i.e. T
		void (OptionType::* setter1)(NT),		// Function pointer to 1st dimension setter
		void (OptionType::*setter2)(NT)		// Function pointer to 2nd dimension setter
	) {
		// Initialize matrix
		std::vector<std::vector<NT>> matrix;
		matrix.reserve(param1.size());

		// Loop over param1
		for (unsigned i = 0; i < param1.size(); ++i) {
			// Intialize row
			std::vector<NT> row;
			row.reserve(param2.size());

			// Loop over second dimension
			for (unsigned j = 0; j < param2.size(); ++j) {
				OptionType optionCopy = option;		// Create a copy
				(optionCopy.*setter1)(param1[i]);	// Set first parameter
				(optionCopy.*setter2)(param2[j]);	// Set second parameter
				row.push_back(optionCopy.price());
			}

			matrix.push_back(row);
		}

		return matrix;
	}

};

#endif // MATRIX_PRICER_HPP
