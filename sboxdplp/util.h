#pragma once
#include <cstdint>

#if defined(_MSC_VER)
#include <intrin.h> 
#endif

namespace util
{
	static bool parity32(uint32_t v)
	{
#if defined(_MSC_VER)
		return (__popcnt(v) & 1) == 1;
#elif defined(__GNUC__)
		return (__builtin_popcount(v) & 1) == 1;
#else
		v ^= v >> 16;
		v ^= v >> 8;
		v ^= v >> 4;
		v &= 0xf;
		return ((0x6996 >> (int)v) & 1) == 1;
#endif
	}
}
