#include "sequenceEratostenesV1.h"

namespace sequenceEratostenesV1 {
	void eraseMultiplifications(bool* numbers, const int ARRAY_SIZE, int baseNumber);
	void calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult);
}


void performSequenceEratostenesV1(PrimeNumbersResult& primeNumbersResult) {

	primeNumbersResult.setAlgorithmName("Sequence primes - Eratostenes V1");
	auto start = std::chrono::high_resolution_clock::now();
	sequenceEratostenesV1::calculatePrimeNumbers(primeNumbersResult);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	primeNumbersResult.setComputingTime(elapsed.count());

}

void sequenceEratostenesV1::calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult) {
	const int LOWER_BOUND = primeNumbersResult.getLowestBound();
	const int HIGHER_BOUND = primeNumbersResult.getHighestBound();
	const int MAX_DIVISOR = util::getHighestDivisor(HIGHER_BOUND);
	const int NUMBERS_TO_CALCULATE = MAX_DIVISOR - 1;
	bool* numbers = primeNumbersResult.getEratostenesProcessedNumbers();

	for (int index = 0; index < NUMBERS_TO_CALCULATE; ++index) {
		int currentNumber = index + 2;
		if (numbers[index] == 1) {
			sequenceEratostenesV1::eraseMultiplifications(numbers, HIGHER_BOUND - 1, currentNumber);
		}
	}
}

void sequenceEratostenesV1::eraseMultiplifications(bool* numbers, const int ARRAY_SIZE, int baseNumber) {
	const int startIndex = 2 * baseNumber - 2;

	for (int index = startIndex; index < ARRAY_SIZE; index += baseNumber) {
		numbers[index] = 0;
	}

}

