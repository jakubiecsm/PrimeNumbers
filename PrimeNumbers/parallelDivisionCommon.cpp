#include "parallelDivisionCommon.h"



bool parallelDivisionCommon::isNumberPrime(int number) {
	if (number == 1) {
		return false;
	}
	else if (number == 2) {
		return true;
	}

	int lowestDivisor = 3;
	int highestDivisor = util::getHighestDivisor(number);

	for (int divisor = lowestDivisor; divisor <= highestDivisor; divisor += 2) {
		if (util::isDivisible(number, divisor)) {
			return false;
		}
	}

	return true;
}
