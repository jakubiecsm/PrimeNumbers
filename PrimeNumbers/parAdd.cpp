#include "parAdd.h"

void parAddFunc(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS) {
	const int INTERVAL = HIGHER_BOUND - LOWER_BOUND + 1;
	int numberOfComplex = 0;
	bool* complexNumbers = new bool[INTERVAL]{ 0 };
	int* calculatedPrimes = new int[INTERVAL];
	int numberOfCalculatedPrimes;

	omp_set_num_threads(NUMBER_OF_THREADS);

	auto start = Clock::now();
	numberOfCalculatedPrimes = util::calculatePrimesSieve(calculatedPrimes, util::getHighestDivisor(HIGHER_BOUND));

#pragma omp parallel
	{
		//schedule(static, INTERVAL / NUMBER_OF_THREADS / 100)
		//schedule(dynamic, INTERVAL / NUMBER_OF_THREADS / 100)
		//schedule(dynamic, INTERVAL / NUMBER_OF_THREADS / 1000)
		//schedule(guided)
#pragma omp for schedule(guided)
		for (int i = 0; i < numberOfCalculatedPrimes; ++i) {
			int temp = 2 * calculatedPrimes[i];
			while (temp <= HIGHER_BOUND) {
				if (temp >= LOWER_BOUND && !complexNumbers[temp - LOWER_BOUND]) {
					complexNumbers[temp - LOWER_BOUND] = true;
				}
				temp += calculatedPrimes[i];
			}
		}

#pragma omp for reduction(+:numberOfComplex)
		for (int i = 0; i < INTERVAL; i++) {
			if (complexNumbers[i] == true) numberOfComplex++;
		}
	}

	auto end = Clock::now();
	double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
	int numberOfPrimes = INTERVAL - numberOfComplex;

	util::displayProcessingTime(processingTime);
	util::displayPrimesFromBool(complexNumbers, LOWER_BOUND, HIGHER_BOUND, numberOfPrimes);

	delete[] complexNumbers;
	delete[] calculatedPrimes;
}

void parAddDom(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS) {
	const int INTERVAL = HIGHER_BOUND - LOWER_BOUND + 1;
	int numberOfComplex = 0;
	bool* complexNumbers = new bool[INTERVAL]{ 0 };
	int* calculatedPrimes = new int[INTERVAL];
	int numberOfCalculatedPrimes;

	omp_set_num_threads(NUMBER_OF_THREADS);

	auto start = Clock::now();
	numberOfCalculatedPrimes = util::calculatePrimesSieve(calculatedPrimes, util::getHighestDivisor(HIGHER_BOUND));

#pragma omp parallel
	{
		//schedule(static, INTERVAL / NUMBER_OF_THREADS / 100)
		//schedule(dynamic, INTERVAL / NUMBER_OF_THREADS / 100)
		//schedule(dynamic, INTERVAL / NUMBER_OF_THREADS / 1000)
		//schedule(guided)
#pragma omp for schedule(guided)
		for (int multiplier = 2; multiplier <= HIGHER_BOUND/2; ++multiplier) {
			for (int i = 0; i < numberOfCalculatedPrimes; ++i) {
				int temp = calculatedPrimes[i] * multiplier;

				//exit loop if out of bounds
				if (temp > HIGHER_BOUND) break;
				if (temp < LOWER_BOUND) continue;

				//mark as complex when not marked already
				if (!complexNumbers[temp - LOWER_BOUND]) {
					complexNumbers[temp - LOWER_BOUND] = true;
				}
				
			}
		}

#pragma omp for reduction(+:numberOfComplex)
		for (int i = 0; i < INTERVAL; i++)
			if (complexNumbers[i] == true) numberOfComplex++;

	}

	auto end = Clock::now();
	double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
	int numberOfPrimes = INTERVAL - numberOfComplex;
	util::displayProcessingTime(processingTime);
	util::displayPrimesFromBool(complexNumbers, LOWER_BOUND, HIGHER_BOUND, numberOfPrimes);

	delete[] complexNumbers;
	delete[] calculatedPrimes;
}
