/**************************************************************************
 * File:        main.cpp
 * Author:      David Leather
 * Date:        2025-03-29
 * Purpose:     Fully test each and every aspect of your option pricing classes,
 *				to ensure correctness prior to submission. And answer the following...
 * 
 *				Part A:
 *					1. Exact Solution for One-Factor Plain Options
 *						a. Implement formulas for pricing european puts and calls.
 *						b. Add conversion from put-to-call and vice-versa using
 *							put-call parity. As well as a validation checker for 
 *							put-call parity.
 *						c. Write a global function that produces a mesh array
 *							of doubles seperated by a mesh size `h`
 *						d. Extend (c) to be able to compute option prices as a
 *							any of the option parameters. The purpose is to
 *							input a matrix of option parameters and receive a
 *							matrix of option prices as the result. Encapsulate
 *							this functionality in the most flexible/robust way
 *							you can think of.
 *
 * Version:     1.1
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
 * Version 1.1: 2025-03-29 - Solved A.1.b and A.1.c.
 *****************************************************************************/

#include <cmath>
#include <iostream>
#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include "EuropeanPut.hpp"
#include "EuropeanCall.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <vector>
#include "MatrixPricer.hpp"

// Script parameters
double tol = 0.00001;	// 1e-05


int main()
{
	std::cout << "-----------------------------------------------\n";
	std::cout << "-----------------    PART A    ----------------\n";
	std::cout << "-----------------------------------------------\n\n";

	// Create an alias for each batch instance
	using BatchData = boost::tuple<double, double, double, double, double, double, double>;
	
	// Each batch is (T, K, sig, r, S, C, P)
	std::vector<BatchData> batches = {
		boost::make_tuple(0.25, 65.0, 0.30, 0.08, 60.0, 2.13337, 5.84628),
		boost::make_tuple(1.0, 100.0, 0.2, 0.0, 100.0, 7.96557, 7.96557),
		boost::make_tuple(1.0, 10.0, 0.50, 0.12, 5.0, 0.204058, 4.07326),
		boost::make_tuple(30.0, 100.0, 0.30, 0.08, 100.0, 92.17570, 1.24750)
	};
	
	// Loop through each batch and compute and compare the prices
	for (unsigned i = 0; i < 4; ++i)
	{
		BatchData batch = batches[i];

		// Extract parameters from the current batch
		double T   = boost::get<0>(batch);
		double K   = boost::get<1>(batch);
		double sig = boost::get<2>(batch);
		double r   = boost::get<3>(batch);
		double S   = boost::get<4>(batch);
		double C   = boost::get<5>(batch);
		double P   = boost::get<6>(batch);

		// Define the put and call objects
		EuropeanPut<double> put(S, K, T, r, sig, r);
		EuropeanCall<double> call(S, K, T, r, sig, r);

		// Print output and compare
		std::cout.precision(4);
		std::cout << "-----------------------------------------------\n";
		std::cout << "Batch : " << i + 1 << "\n";
		std::cout << "-----------------------------------------------\n";
		std::cout << "Given Put Price: " << P << "\n";
		std::cout << "Computed Put Price: " << put.price() << "\n";
		std::cout << "Numerically Equivalent? " << ((fabs(P - put.price()) < tol)
			? "True" : "False") << "\n";
		std::cout << "Given Call Price: " << C << "\n";
		std::cout << "Computed Call Price: " << call.price() << "\n";
		std::cout << "Numerically Equivalent? ";
		std::cout << ((fabs(C - call.price()) < tol) ? "True" : "False") << "\n";

		// Check put-call Parity
		double C2 = EuropeanOption<double>::putToCall(put, put.price());
		double P2 = EuropeanOption<double>::callToPut(call, call.price());
		std::cout << "Put to Call: " << C2 << "\n";
		std::cout << "Numerically Equivalent? ";
		std::cout << ((fabs(C - C2) < tol) ? "True" : "False") << "\n";
		std::cout << "Cal to Put: " << P2 << "\n";
		std::cout << "Numerically Equivalent? ";
		std::cout << ((fabs(P - P2) < tol) ? "True" : "False") << "\n";
		std::cout << "Put-Call Parity Checker Working? ";
		std::cout << (EuropeanOption<double>::putCallParityCheck(call, put, tol)
			? "True" : "False") << "\n";
		std::cout << "-----------------------------------------------\n\n";

		// Test MeshGenerator
		double S0 = 1.0;		// Start price
		double S1 = 20.0;		// End price
		double h = 1.0;	// Step size
		MeshGenerator<double> S_grid(S0, S1, h);
		std::cout << "-----------------------------------------------\n";
		std::cout << "Testing MeshGenerator\n";
		std::cout << "-----------------------------------------------\n\n";
		std::cout << "Grid from " << S0 << " to " << S1 << " with step-size ";
		std::cout << h << ":\n";
		std::vector<double>::const_iterator it;
		for (it = S_grid.begin(); it != S_grid.end(); ++it)
		{
			std::cout << *it << ", ";
		}
		std::cout << ".\n";
		std::cout << "Mesh grid size: " << S_grid.size() << "\n";
		std::cout << "-----------------------------------------------\n";

		// Test matrix pricer
		batch = batches[0];

		// Test createMesh
		std::vector<double> mesh = MatrixPricer::createMesh(S0, S1, h);
		std::cout << "Grid: ";
		for (it = mesh.begin(); it != mesh.end(); ++it)
		{
			std::cout << *it << ", ";
		}
		std::cout << "\n";

		// Test priceRange()
		std::vector<double> prices = MatrixPricer::priceRange(put, S0, S1, h);
		std::cout << "Prices: ";
		for (it = prices.begin(); it != prices.end(); ++it)
		{
			std::cout << *it << ", ";
		}
		std::cout << "\n";

		// Test priceMatrix() - S = {1,...,10} and T = {1, ..., 10}
		S0 = 1; S1 = 10;
		double T0 = 1; double T1 = 10;
		MeshGenerator<double> mesh_S(S0, S1, h);
		MeshGenerator<double> mesh_T(S0, S1, h);
		std::vector<std::vector<double>> price_matrix =
			MatrixPricer::priceMatrix(
				put,
				mesh_S,
				mesh_T,
				static_cast<void (EuropeanPut<double>::*)(double)>(&EuropeanPut<double>::S),
				static_cast<void (EuropeanPut<double>::*)(double)>(&EuropeanPut<double>::T)
			);
		std::cout << "Price Matrix (rows = S, columns = T):\n";
		for (std::size_t i = 0; i < price_matrix.size(); ++i) {
			for (std::size_t j = 0; j < price_matrix[i].size(); ++j) {
				std::cout << price_matrix[i][j] << ", ";
			}
			std::cout << "\n";
		}

	}

	return 0;
}
