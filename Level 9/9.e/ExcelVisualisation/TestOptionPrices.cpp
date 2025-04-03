/**************************************************************************
 * File:        TestOptionPrices.cpp
 * Author:      David Leather
 * Date:        2025-04-03
 * Purpose:     Computes range of option prices and outputs to excel file.
 *
 * Version:     1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-28 - Initial implementation.
 *****************************************************************************/

#include <cmath>
#include <string>
#include <iostream>
#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include "EuropeanPut.hpp"
#include "EuropeanCall.hpp"
#include <vector>
#include "MatrixPricer.hpp"
#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"

int main()
{
	// Set parameters
	double S0 = 10.0;	// Lower bound of underlying range
	double S1 = 50.0;	// Upper bound of underlying range
	double h = 1.0;		// Step size
	double T = 0.25;	// Time-to-expiry
	double K = 35.0;	// Strike price
	double r = 0.08;	// risk-free rate
	double sig = 0.3;	// volatility

	// Initalize option
	EuropeanCall<double> call;

	// Generate Mesh
	MeshGenerator<double> mesh(S0, S1, h);

	// Initlaize vector of prices and underlying 
	std::vector<double> prices;
	prices.reserve(mesh.size());
	std::vector<double> Ss;
	Ss.reserve(mesh.size());

	// Fill out data
	for (unsigned i = 0; i < mesh.size(); ++i)
	{
		Ss.push_back(mesh[i]);
		call = EuropeanCall<double>::EuropeanCall(Ss[i], K, T, r, sig);
		prices.push_back(call.price());
	}

	// Initalize Excel Driver
	std::string sheetName("European Call Prices");
	ExcelDriver& excel = ExcelDriver::Instance();
	excel.MakeVisible(true);

	// Set labels
	std::string rowLabel("row1");
	std::list<std::string> colLabels = {"S", "Call Price"};

	// Create chart
	excel.CreateChart(Ss, prices, "Call Option Prices", "Stock Price", "Option Value");

	return 0;
}




