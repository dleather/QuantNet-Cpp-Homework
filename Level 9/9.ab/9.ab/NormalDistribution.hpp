/**************************************************************************
 * File:		NormalDistribution.hpp
 * Author:		David Leather
 * Date:		2025-03-28
 * Purpose:		Header file for parametric NormalDistribution struct. Contains
 *					- Contains static functions pdf and cdf which will adjust
 *						to parametric type.
 *
 * Version:		1.0
 *
 * Change Log:
 * Version 1.0: 2025-03-27 - Initial implementation.
 *****************************************************************************/
#ifndef NORMAL_DISTRIBUTION_HPP
#define NORMAL_DISTRIBUTION_HPP

#include <boost/math/distributions/normal.hpp>

template<typename NT = double>
struct NormalDistribution {
	static NT pdf(NT x) {
		static const boost::math::normal_distribution<NT> dist(NT(0), NT(1));
		return boost::math::pdf(dist, x);
	}

	static NT cdf(NT x) {
		static const boost::math::normal_distribution<NT> dist(NT(0), NT(1));
		return boost::math::cdf(dist, x);
	}
};

#endif // NORMAL_DISTRIBUTION_HPP
