// TestBSPDE1.cpp
//
// Testing 1 factor BS model.
//
// (C) Datasim Education BV 2005-2011
//

#include "FdmDirector.hpp"

#include <iostream>
#include <string>
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"

namespace BS // Black Scholes
{
	double sig = 0.3;
	double K = 100.0;
	double T = 30.0;
	double r = 0.08;
	double D = 0.0;		// aka q
	double St =  100.0;	// Underlying price to evaluate acc. at
	double P = 1.24750;	// Underlying put price
	double C = 92.17570;	// Underlying call price

	double mySigma (double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu (double x, double t)
	{
		
		return (r - D) * x;
	
	}

	double myB (double x, double t)
	{	
	
		return  -r;
	}

	double myF (double x, double t)
	{
		return 0.0;
	}

	double myBCL (double t)		
	{
		// Put
		return K *exp(-r * t);
	}

	double myBCR (double t)
	{
			
		// Put
		return 0.0; // P
	}

	double myIC (double x)
	{ // Payoff 
	
		// Put
		return max(K - x, 0.0);
	}

	double mySt()
	{
		return St;
	}

	double myP()
	{
		return P;
	}

	double myC()
	{
		return C;
	}

}


int main()
{
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	double St = BS::mySt();	// Strike price when given ground truth
	double P = BS::myP();	// Coresponding put price given in batch
	double C = BS::myC();	// Corresponding call price given in batch

	int J = static_cast<int>(5*BS::K); int N = 1000000-1; // k = O(h^2) !!!!!!!!!

	double Smax = 3*BS::K;			// Magix

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BS::T, J, N);

	fdir.doit();
	
	cout << "Finished\n";

	// Locate the index in xarr closest to St
	const std::vector<double>& xarr = fdir.xarr;
	std::vector<double>::const_iterator it = std::lower_bound(xarr.begin(), xarr.end(), St);
	size_t index = std::distance(xarr.begin(), it);

	// Retrieve the corresponding value from the solution vector
	const std::vector<double>& fdmPrices = fdir.current();
	double fdmPrice = fdmPrices[index];

	// Display results
	cout << "Underlying Price (St): " << St << "\n";
	cout << "FDM Put Price: " << fdmPrice << "\n";
	cout << "True Put Price: " << P << "\n";
	cout << "|error|: " << fabs(P - fdmPrice) << "\n";

	return 0;
}
