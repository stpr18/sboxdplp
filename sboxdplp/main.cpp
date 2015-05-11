#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "AesSbox.h"
#include "Dp.h"
#include "Lp.h"

int main()
{
	AesSbox sbox;
	Dp<256> dp(sbox);
	Lp<256> lp(sbox);

	std::cout << dp.getProb() << std::endl;
	std::cout << lp.getProb() << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}
