/***************************************************************************
 * File:		main_5_1_4.cpp
 * Author:		David Leather
 * Date:		2025-03-27
 * Purpose:		Explore random number generation in the boost library.
 *					- Simulate N_SIM draws of a fair 6-sided die
 *					- For each draw:
 *						- Keep track of frequency in a map (counter)
 *					- Divide each mapping by N_SIM
 *					- Give percentages in cout using 4-decimal precision 
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-27 - Initial implementation.
 *****************************************************************************/

#include <map>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>
#include <random>

// Set script parameter
const int N_SIM = 1000000;	// Number of draws from U({1,...,6})

int main()
{
	// Set-up RNG
	boost::random::mt19937 myRng;								// Initalize RNG
	std::random_device rd;
	myRng.seed(static_cast<boost::uint32_t> (rd()));	// Set seed
	boost::random::uniform_int_distribution<int> six(1, 6);		// Fair 6-sided die

	// Create a frequency map
	std::map<int, long> statistics; // Structure to hold outcome + frequencies
	
	// Initalize map to 0 for each int in domain
	for (int i = 1; i < 7; ++i)
	{
		statistics[i] = 0;
	}

	// Main loop
	int outcome;	// Initalize storage for draws
	for (unsigned int i = 0; i < N_SIM; ++i)
	{
		outcome = six(myRng);	// Roll the dice
		statistics[outcome]++;	// Increment the statistic
	}
	
	// Prepare output
	std::cout << "How many trials? " << N_SIM << std::endl << std::endl;
	std::cout.precision(4);	// Set precision to 4 decimal places
	std::cout << std::fixed;
	for (unsigned i = 1; i < 7; ++i)
	{
		std::cout << "Trial " << i << " has " << (statistics[i] * 100.0) / N_SIM;
		std::cout << "% outcomes" << std::endl;
		
	}
	
	return 0;
}
