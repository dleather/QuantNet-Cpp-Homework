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
#include <string>
#include <iostream>
#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include "EuropeanPut.hpp"
#include "EuropeanCall.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/function.hpp>
#include <boost/bind/bind.hpp>
#include <vector>
#include "MatrixPricer.hpp"

// Script parameters
double tol = 0.0001;	// 1e-04


int main()
{
	std::cout << "-----------------------------------------------\n";
	std::cout << "-----------------    PART A    ----------------\n";
	std::cout << "-----------------------------------------------\n\n";

	std::cout << "-----------------------------------------------\n";
	std::cout << "---   Part A1: Closed-form Prices   -----------\n";
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

	// Initialize variables
	BatchData batch; double T; double K; double sig; double r; double S;
	double C; double P; EuropeanPut<double> put; EuropeanCall<double> call;
	double C2; double P2;
	for (unsigned i = 0; i < 4; ++i)
	{
		batch = batches[i];

		// Extract parameters from the current batch
		T   = boost::get<0>(batch);
		K   = boost::get<1>(batch);
		sig = boost::get<2>(batch);
		r   = boost::get<3>(batch);
		S   = boost::get<4>(batch);
		C   = boost::get<5>(batch);
		P   = boost::get<6>(batch);

		// Define the put and call objects
		put = EuropeanPut<double>::EuropeanPut(S, K, T, r, sig, r);
		call = EuropeanCall<double>::EuropeanCall(S, K, T, r, sig, r);

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
		C2 = EuropeanOption<double>::putToCall(put, put.price());
		P2 = EuropeanOption<double>::callToPut(call, call.price());
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
	}
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
	std::cout << "-----------------------------------------------\n";

	// Test priceRange()
	std::cout << "-----------------------------------------------\n";
	std::cout << "Testing Range Pricer\n";
	std::cout << "-----------------------------------------------\n\n";
	// Set price functor
	boost::function<double(const EuropeanPut<double>&)> price_func =
		boost::bind(&EuropeanPut<double>::price, _1);
	// Set underlying price range
	std::vector<double> prices = MatrixPricer::priceRange(put, S0, S1, h, price_func);
	std::cout << "Prices: ";
	for (it = prices.begin(); it != prices.end(); ++it)
	{
		std::cout << *it << ", ";
	}
	std::cout << "\n";

	// Test priceMatrix() - S = {1,...,10} and T = {1, ..., 10}
	std::cout << "-----------------------------------------------\n";
	std::cout << "Testing Matrix Pricer\n";
	std::cout << "-----------------------------------------------\n\n";
	S0 = 1; S1 = 10;					// Upper and lower bounds for S grid
	double T0 = 1; double T1 = 10;		// Upper and lower bounds for T grid
	MeshGenerator<double> mesh_S(S0, S1, h);	// Mesh grid for S
	MeshGenerator<double> mesh_T(T0, T1, h);	// Mesh grid for T
	// Function object for 1st setter
	boost::function<void(EuropeanPut<double>&, double)> setS_func =
		boost::bind(&EuropeanPut<double>::setS, _1, _2);
	// Function object for second setter
	boost::function<void(EuropeanPut<double>&, double)> setT_func =
		boost::bind(&EuropeanPut<double>::setT, _1, _2);
	std::vector<std::vector<double>> price_matrix =
		MatrixPricer::priceMatrix(
			put,
			mesh_S,
			mesh_T,
			setS_func,
			setT_func
		);
	std::cout << "Price Matrix (rows = S, columns = T):\n";
	for (std::size_t i = 0; i < price_matrix.size(); ++i) {
		for (std::size_t j = 0; j < price_matrix[i].size(); ++j) {
			std::cout << price_matrix[i][j] << ", ";
		}
		std::cout << "\n";
	}

	std::cout << "-----------------------------------------------\n";
	std::cout << "---------   Part A2: The Greeks   --------------\n";
	std::cout << "-----------------------------------------------\n\n";
	std::cout << "Computing the Greeks for European future call and put...\n";
	// Set parameters
	K = 100.0; S = 105.0; T = 0.5; double b = 0.0; sig = 0.36; r = 0.1;

	// Define objects
	EuropeanPut<double> fput
		= EuropeanPut<double>::EuropeanPut(S, K, T, r, sig, b);
	EuropeanCall<double> fcall
		= EuropeanCall<double>::EuropeanCall(S, K, T, r, sig, b);

	// Compute gammas
	double put_gamma = fput.gamma();
	double put_delta = fput.delta();
	double put_theta = fput.theta();
	double put_vega = fput.vega();
	double call_gamma = fcall.gamma();
	double call_delta = fcall.delta();
	double call_theta = fcall.theta();
	double call_vega = fcall.vega();
	std::string ssep = "  |  ";

	std::cout << ssep << "Greek" << ssep << "Put" << ssep << "Call" << "  |\n";
	std::cout << "-----------------------------------------------\n\n";
	std::cout << ssep << "Gamma" << ssep << put_gamma << ssep << call_gamma << "  |\n";
	std::cout << ssep << "Delta" << ssep << put_delta << ssep << call_delta << "  |\n";
	std::cout << ssep << "Theta" << ssep << put_theta << ssep << call_theta << "  |\n";
	std::cout << ssep << "Vega " << ssep << put_vega << ssep << call_vega << "  |\n";
	bool delta_check = (fabs(put_delta - -0.3566) <= tol)
		&& (fabs(call_delta - 0.5946) <= tol);
	std::cout << "Pass delta comparison? " << (delta_check ? "Yes!\n" : "No\n\n");

	std::cout << "Computing the Delta for call for S: 10, 11,..., 50:\n";
	boost::function<double(const EuropeanCall<double>&)> delta_func =
		boost::bind(&EuropeanCall<double>::delta, _1);
	std::vector<double> deltas;
	deltas = MatrixPricer::priceRange(fcall, 10.0, 50.0, 1.0, delta_func);
	std::cout << "|    S    |  Deltas | << \n";
	std::cout << "---------------------\n";
	for (int i = 0; i < deltas.size(); ++i)
	{
		std::cout << "| " << 10.0 + i << " | " << deltas[i] << " |\n";
	}
	std::cout << "---------------------\n\n";

	std::cout << "Using MatrixPricer to output matrix of Gammas over\n";
	std::cout << " a grid of S = 90,91,100. And K = 100, 101, ..., 110\n\n";
	mesh_S = MeshGenerator<double>(90.0, 100.0, 1.0);
	MeshGenerator<double> mesh_K = MeshGenerator<double>(100.0, 110.0, 1.0);
	boost::function<void(EuropeanCall<double>&, double)> setK_func =
		boost::bind(&EuropeanCall<double>::setK, _1, _2);
	boost::function<void(EuropeanCall<double>&, double)> setS2_func = boost::bind(&EuropeanCall<double>::setS, _1, _2);
	std::vector<std::vector<double>> delta_matrix;	// Initalize matrix
	delta_matrix = MatrixPricer::priceMatrix(fcall, mesh_S, mesh_K, setS2_func, setK_func);
	std::cout << "Delta Matrix (rows = S, columns = K):\n";
	for (std::size_t i = 0; i < delta_matrix.size(); ++i) {
		for (std::size_t j = 0; j < delta_matrix[i].size(); ++j) {
			std::cout << delta_matrix[i][j] << ", ";
		}
		std::cout << "\n";
	}
	std::cout << "---------------------\n\n";
	std::cout << "Computing the Delta and Gamma from before with divided differences...\n\n";

	// Compute gammas
	double put_ddgamma = fput.ddGamma();
	double put_dddelta = fput.ddDelta();
	double call_ddgamma = fcall.ddGamma();
	double call_dddelta = fcall.ddDelta();

	std::cout << ssep << "Greek" << ssep << "Put" << ssep << "Call" << "  |\n";
	std::cout << "-----------------------------------------------\n\n";
	std::cout << ssep << "Gamma" << ssep << put_ddgamma << ssep << call_ddgamma << "  |\n";
	std::cout << ssep << "Delta" << ssep << put_dddelta << ssep << call_dddelta << "  |\n";
	std::cout << ssep << "Theta" << ssep << put_theta << ssep << call_theta << "  |\n";
	std::cout << ssep << "Vega " << ssep << put_vega << ssep << call_vega << "  |\n";
	delta_check = (fabs(put_dddelta - -0.3566) <= tol)
		&& (fabs(call_dddelta - 0.5946) <= tol);
	std::cout << "Pass delta comparison? " << (delta_check ? "Yes!\n" : "No\n\n");

	std::cout << "Ok, that worked. Now let's show the abs. error from h = 10^16\n";
	std::cout << ", 10^15, ... , 10\^1 for Delta and Gamma.\n";
	// Initalize loop variables
	double put_delta_err; double put_gamma_err;
	double call_delta_err; double call_gamma_err;
	h = std::pow(10.0, -16.0);
	std::vector<double> mean_abs_errs(16);
	for (unsigned i = 0; i < 16; ++i)
	{
		// Compute double-difference Delta and Gamma
		put_dddelta = fput.ddDelta(h);
		put_ddgamma = fput.ddGamma(h);
		call_dddelta = fcall.ddDelta(h);
		call_ddgamma = fcall.ddGamma(h);

		// Compute errors
		put_delta_err = fabs(put_dddelta - put_delta);
		put_gamma_err = fabs(put_ddgamma - put_gamma);
		call_delta_err = fabs(call_dddelta - call_delta);
		call_gamma_err = fabs(call_ddgamma - call_gamma);

		// Print output
		std::cout << "-------------------------\n";
		std::cout << "h: 1e-" << 16 - i << "\n";
		std::cout << "abs(call delta error): " << call_delta_err << "\n";
		std::cout << "abs(put delta error): " << put_delta_err << "\n";
		std::cout << "abs(call gamma error): " << call_gamma_err << "\n";
		std::cout << "abs(put gamma error): " << put_gamma_err << "\n";
		mean_abs_errs[i] = put_delta_err + put_gamma_err + call_delta_err;
		mean_abs_errs[i] += call_gamma_err;
		mean_abs_errs[i] /= 4.0;
		std::cout << "mean abs. error.: " << mean_abs_errs[i] << "\n";
		std::cout << "------------------------\n\n";

		// Increment h
		h *= 10.0;

	}

	// Make notes on observations
	std::cout << "The difference method for gamma which uses centered\n";
	std::cout << "differences are suceptible to round-off error amplified\n";
	std::cout << "by the denominator h^2.\n";
	std::cout << "Optimal h is around 1e-3.\n\n";

	std::cout << "Now lets retry A2.b, and compute the abs error for the range\n";
	std::cout << "of deltas....";
	// Initalize vector of dd deltas and corresponding functor
	std::vector<double> dddeltas;
	boost::function<double(const EuropeanOption<double>&)> dddelta_func =
		boost::bind(&EuropeanOption<double>::ddDelta, _1);
	dddeltas = MatrixPricer::priceRange(fcall, 10.0, 50.0, 1.0, dddelta_func);
	std::vector<double> abs_errs2(dddeltas.size());
	std::cout << "----------    Delta Pricer ---------\n";
	std::cout << "|    S    |  Closed-Form  |  Divided-Diff  |  abs. err.  |<< \n";
	std::cout << "---------------------\n";
	double mean_abs_err = 0.0;
	double abs_err;
	for (int i = 0; i < deltas.size(); ++i)
	{
		abs_err = fabs(dddeltas[i] - deltas[i]);
		mean_abs_err += abs_err;
		std::cout << "|  " << 10.0 + i << "  |  " << deltas[i] << "  |  ";
		std::cout << dddeltas[i] << "  |  " << abs_err  << "  |\n";
	}
	mean_abs_err /= dddeltas.size();
	std::cout << "mean abs err: " << mean_abs_err;
	std::cout << "---------------------\n\n";


	return 0;
}
