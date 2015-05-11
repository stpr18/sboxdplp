#pragma once
#include "util.h"

template <unsigned int K2>
class Dp
{
private:
	int result_[K2][K2] = {};
	double prob_;

	Dp() {};

public:
	template <class SBOX>
	Dp(SBOX &sbox)
	{
		for (unsigned int x = 0; x < K2; ++x)
			for (unsigned int y = 0; y < K2; ++y)
				++result_[x ^ y][sbox.sbox(x) ^ sbox.sbox(y)];

		int maxval = 0;

		for (unsigned int x = 1; x < K2; ++x) {
			for (unsigned int y = 0; y < K2; ++y) {
				int val = result_[x][y];

				if (maxval < val) {
					maxval = val;
				}
			}
		}

		prob_ = (double)maxval / (double)K2;
	}

	~Dp() {}

	double getProb() const
	{
		return prob_;
	}
};
