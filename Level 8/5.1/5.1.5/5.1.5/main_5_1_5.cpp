/***************************************************************************
 * File:		main_5_1_5.cpp
 * Author:		David Leather
 * Date:		2025-03-27
 * Purpose:		Modifies TestNormalDistribution.cpp (DataSim Education (C))
 *					- Normal Dist. -> Exponential Dist.
 *					- Gamma Dist. -> Poisson Dist.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-27 - Initial implementation.
 *****************************************************************************/

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;

int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	double lambda = 2.0;						// Shape parameter for exp
	exponential_distribution<> myExp(lambda);	// Default type is 'double'
	cout << "Mean: " << mean(myExp) << ", standard deviation: " << standard_deviation(myExp) << endl;

	// Distributional properties
	double x = 10.25;

	cout << "pdf: " << pdf(myExp, x) << endl;
	cout << "cdf: " << cdf(myExp, x) << endl;

	// Choose another data type and now a Exp(1)
	exponential_distribution<float> myExp2; 
	cout << "Mean: " << mean(myExp2) << ", standard deviation: " << standard_deviation(myExp2) << endl;
	
	cout << "pdf: " << pdf(myExp2, x) << endl;
	cout << "cdf: " << cdf(myExp2, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\n***exponential distribution (lambda = " << lambda << "): \n";
	cout << "mean: " << mean(myExp) << endl;
	cout << "variance: " << variance(myExp) << endl;
	cout << "median: " << median(myExp) << endl;
	cout << "mode: " << mode(myExp) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExp) << endl;
	cout << "kurtosis: " << kurtosis(myExp) << endl;
	cout << "characteristic function: " << chf(myExp, x) << endl;
	cout << "hazard: " << hazard(myExp, x) << endl;

	// Poisson distribution
	poisson_distribution<double> myPoisson(lambda);

	double val = 13.0;
	cout << endl <<  "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));

		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";

	}

	return 0;
}
