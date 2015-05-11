#pragma once
#include <cstdint>

class AesSbox
{
private:
	static const uint8_t sbox_[256];

public:
	AesSbox() = default;
	~AesSbox() = default;

	uint8_t sbox(uint8_t x)
	{
		return sbox_[x];
	}
};

