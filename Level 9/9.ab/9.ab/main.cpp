/**************************************************************************
 * File:        main.cpp
 * Author:      David Leather
 * Date:        2025-03-28
 * Purpose:     Fully test each and every aspect of your option pricing classes,
 *				to ensure correctness prior to submission. And answer the following...
 * 
 *				Part A:
 *					a. Implement formulas for pricing european puts and calls.
 *
 * Version:     1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
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

// Script parameters
double tol = 0.00001;	// 1e-05

int main()
{
	std::cout << "-----------------    PART A    ----------------\n";

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
		std::cout << "--------------------------------------\n";
		std::cout << "Batch : " << i + 1 << "\n";
		std::cout << "Given Put Price: " << P << "\n";
		std::cout << "Computed Put Price: " << put.price() << "\n";
		std::cout << "Numerically Equivalent? " << (fabs(P - put.price()) < tol) << "\n";
		std::cout << "Given Call Price: " << C << "\n";
		std::cout << "Computed Call Price: " << call.price() << "\n";
		std::cout << "Numerically Equivalent? " << (fabs(C - call.price()) < tol) << "\n";
		std::cout << "--------------------------------------\n\n";

	}

	return 0;
}
