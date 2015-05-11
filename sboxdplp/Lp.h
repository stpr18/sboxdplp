#pragma once
#include "util.h"

template <unsigned int K2>
class Lp
{
private:
	int result_[K2][K2] = {};
	double prob_;

	Lp() {}

public:
	template <class SBOX>
	Lp(SBOX &sbox)
	{
		for (unsigned int x = 0; x < K2; ++x)
			for (unsigned int y = 0; y < K2; ++y)
				for (unsigned int s = 0; s < K2; ++s)
					if (util::parity32(s & x) == util::parity32(sbox.sbox(s) & y))
						++result_[x][y];

		int maxval = 0;

		for (unsigned int x = 1; x < K2; ++x) {
			for (unsigned int y = 1; y < K2; ++y) {
				int val = result_[x][y];
				val = val * 2 - K2;
				val = val * val;

				if (maxval < val) {
					maxval = val;
				}
			}
		}

		prob_ = (double)maxval / (double)(K2 * K2);
	}

	~Lp() {}

	double getProb() const
	{
		return prob_;
	}
};
