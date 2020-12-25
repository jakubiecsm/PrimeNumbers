#include "parallelDivisionV1.h"

namespace parallelDivisionV1 {
	void calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult);
}

void performParallelDivisionV1(PrimeNumbersResult& primeNumbersResult) {

	primeNumbersResult.setAlgorithmName("Parallel primes by division V1");
	auto start = std::chrono::high_resolution_clock::now();
	parallelDivisionV1::calculatePrimeNumbers(primeNumbersResult);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	primeNumbersResult.setComputingTime(elapsed.count());

}

void parallelDivisionV1::calculatePrimeNumbers(PrimeNumbersResult& primeNumbersResult) {
	const int LOWER_BOUND = primeNumbersResult.getLowestBound();
	const int HIGHER_BOUND = primeNumbersResult.getHighestBound();
	int numbersToCalculate = HIGHER_BOUND - LOWER_BOUND + 1;
	bool* numbers = primeNumbersResult.getProcessedNumbers();
	int index = 0;
	int sindex = 0; //index of an array from which to start computations

	//Start with odd number
	if (LOWER_BOUND == 1 || LOWER_BOUND == 2) {
		numbers[1] = true;
		sindex = 2;
	}
	else if (LOWER_BOUND == 2) {
		numbers[0] = true;
		sindex = 1;
	}
	else if (LOWER_BOUND % 2 == 0) {
		sindex = 1;
	}

	omp_set_num_threads(8);

#pragma omp parallel
	{
#pragma omp for
		for (index = sindex; index < numbersToCalculate; index += 2) {
			//actual number is index + LOWER_BOUND
			if (parallelDivisionCommon::isNumberPrime(index + LOWER_BOUND)) {
				numbers[index] = true;
			}
		}
	}

}
