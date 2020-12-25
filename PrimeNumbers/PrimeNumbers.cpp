#pragma once
#include <iostream>
#include "util.h"
#include "SequenceDivisionV1.h"
#include "SequenceDivisionV2.h"
#include "SequenceDivisionV3.h"
#include "sequenceEratostenesV1.h"
#include "parallelDivisionV1.h"

using namespace std;


int main() {
	int lowestBound, highestBound;

	util::getPrimeNumberBounds(&lowestBound, &highestBound);
	PrimeNumbersResult primeNumberResult(lowestBound, highestBound, false); //3rd parameter to true if eratostenes

	util::callPrimeNumbersCalculator(primeNumberResult, &performParallelDivisionV1);
	//util::callPrimeNumbersCalculator(primeNumberResult, &performSequenceDivisionV3Primes);
	util::displayResult(primeNumberResult);

	return 1;
}