#include "SequenceDivisionV1.h"

bool isNumberPrime(int number);
void calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult);


void performSequenceDivisionV1Primes(PrimeNumbersResult& primeNumbersResult) {

	primeNumbersResult.setAlgorithmName("Sequence primes by division V1");
	auto start = std::chrono::high_resolution_clock::now();
	calculatePrimeNumbers(primeNumbersResult);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	primeNumbersResult.setComputingTime(elapsed.count());	

}

void calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult) {
	const int LOWER_BOUND = primeNumbersResult.getLowestBound();
	const int HIGHER_BOUND = primeNumbersResult.getHighestBound();
	int numbersToCalculate = HIGHER_BOUND - LOWER_BOUND + 1;
	bool* numbers = primeNumbersResult.getProcessedNumbers();

	for (int i = 0; i < numbersToCalculate; ++i) {
		//actual number is index + LOWER_BOUND
		if (isNumberPrime(i + LOWER_BOUND)) {
			numbers[i] = true;
		}
	}
}

bool isNumberPrime(int number) {
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


