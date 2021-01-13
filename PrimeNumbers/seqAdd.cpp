#include "seqAdd.h"

void seqAdd(const int LOWER_BOUND, const int HIGHER_BOUND) {
	const int INTERVAL = HIGHER_BOUND - LOWER_BOUND + 1;
	int numberOfComplex = 0;
	bool* complexNumbers = new bool[INTERVAL]{ 0 };
	int* calculatedPrimes = new int[INTERVAL];
	int numberOfCalculatedPrimes;

	auto start = Clock::now();
	numberOfCalculatedPrimes = util::calculatePrimesSieve(calculatedPrimes, util::getHighestDivisor(HIGHER_BOUND));

	for (int i = 0; i < numberOfCalculatedPrimes; ++i) {
		int temp = 2 * calculatedPrimes[i];
		while (temp <= HIGHER_BOUND) {
			if (temp >= LOWER_BOUND) {
				if (!complexNumbers[temp - LOWER_BOUND]) {
					numberOfComplex++;
				}
				complexNumbers[temp - LOWER_BOUND] = true;
			}
			temp += calculatedPrimes[i];
		}
	}
	auto end = Clock::now();
	double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
	int numberOfPrimes = INTERVAL - numberOfComplex;

	util::displayProcessingTime(processingTime);
	util::displayPrimesFromBool(complexNumbers, LOWER_BOUND, HIGHER_BOUND, numberOfPrimes);

	delete[] complexNumbers, calculatedPrimes;
}
