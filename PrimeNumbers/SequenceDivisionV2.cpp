#include "SequenceDivisionV2.h"

namespace SequenceDivisionV2 {
	bool isNumberPrime(int number);
	void calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult);
}



void performSequenceDivisionV2Primes(PrimeNumbersResult& primeNumbersResult) {

	primeNumbersResult.setAlgorithmName("Sequence primes by division V2");
	auto start = std::chrono::high_resolution_clock::now();
	SequenceDivisionV2::calculatePrimeNumbers(primeNumbersResult);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	primeNumbersResult.setComputingTime(elapsed.count());

}

void SequenceDivisionV2::calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult) {
	const int LOWER_BOUND = primeNumbersResult.getLowestBound();
	const int HIGHER_BOUND = primeNumbersResult.getHighestBound();
	int numbersToCalculate = HIGHER_BOUND - LOWER_BOUND + 1;
	bool* numbers = primeNumbersResult.getProcessedNumbers();
	int index = 0;

	//Start with odd number
	if (LOWER_BOUND == 1) {
		numbers[1] = true;
		index = 2;
	}
	else if (LOWER_BOUND == 2) {
		numbers[0] = true;
		index = 1;
	}
	else if (LOWER_BOUND % 2 == 0) {
		index = 1;
	}

	//Don't perform computations for even numbers
	for (index; index < numbersToCalculate; index += 2) {
		//actual number is index + LOWER_BOUND
		if (isNumberPrime(index + LOWER_BOUND)) {
			numbers[index] = true;
		}
	}

}

bool SequenceDivisionV2::isNumberPrime(int number) {
	if (number == 1) {
		return false;
	}
	else if (number == 2) {
		return true;
	}

	int lowestDivisor = 2;
	int highestDivisor = util::getHighestDivisor(number);

	for (int divisor = lowestDivisor; divisor <= highestDivisor; ++divisor) {
		if (util::isDivisible(number, divisor)) {
			return false;
		}
	}

	return true;
}