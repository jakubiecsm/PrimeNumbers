#include "SequenceDivisionV3.h"

namespace SequenceDivisionV3 {
	bool isNumberPrime(int number);
	void calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult);
}


void performSequenceDivisionV3Primes(PrimeNumbersResult& primeNumbersResult) {

	primeNumbersResult.setAlgorithmName("Sequence primes by division V3");
	auto start = std::chrono::high_resolution_clock::now();
	SequenceDivisionV3::calculatePrimeNumbers(primeNumbersResult);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	primeNumbersResult.setComputingTime(elapsed.count());

}

void SequenceDivisionV3::calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult) {
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

bool SequenceDivisionV3::isNumberPrime(int number) {
	if (number == 1) {
		return false;
	}
	else if (number == 2) {
		return true;
	}

	int lowestDivisor = 3;
	int highestDivisor = util::getHighestDivisor(number);

	//Divide only by odd numbers (all even nubmers were rejected earlier)
	for (int divisor = lowestDivisor; divisor <= highestDivisor; divisor += 2) {
		if (util::isDivisible(number, divisor)) {
			return false;
		}
	}

	return true;
}
