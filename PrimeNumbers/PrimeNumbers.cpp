#pragma once
#include <iostream>
#include "util.h"
#include "seqDiv.h"
#include "parDiv.h"
#include "seqAdd.h"
#include "parAdd.h"


int main() {
	int lowerBound, higherBound;

	for (int i = 2; i <= 8; i *= 2) {
		lowerBound = 2;
		higherBound = 100000000;
		parAddDom(lowerBound, higherBound, i);


		lowerBound = 50000000;
		higherBound = 100000000;
		parAddDom(lowerBound, higherBound, i);

		lowerBound = 2;
		higherBound = 50000000;
		parAddDom(lowerBound, higherBound, i);
	}



	//seqDiv2(lowerBound, higherBound);
	//seqDivPrimes1(lowerBound, higherBound);
	//seqAdd(lowerBound, higherBound);
	//seqAdd(lowerBound, higherBound);
	//parAddFunc(lowerBound, higherBound, 8);
	//parAddDom(lowerBound, higherBound, 8);
	//parDiv1(lowerBound, higherBound, 8);
	//parDiv2(lowerBound, higherBound, 8);
	//seqDivPrimes1(lowerBound, higherBound);
	//parDivPrimes1(lowerBound, higherBound, 8);

	return 1;
}