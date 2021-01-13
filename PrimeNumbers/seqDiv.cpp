#include "seqDiv.h"

using namespace std;

void seqDiv1(const int LOWER_BOUND, const int HIGHER_BOUND) {

	int numberOfPrimes = 0;
	int* primeNumbers = new int[HIGHER_BOUND - LOWER_BOUND + 1];

	auto start = Clock::now();
	for (int number = LOWER_BOUND; number <= HIGHER_BOUND; ++number) {
		bool isPrime = true;
		const int HIGHEST_DIVISOR = util::getHighestDivisor(number);

		for (int divisor = 2; divisor <= HIGHEST_DIVISOR; ++divisor) {
			if (number % divisor == 0) {
				isPrime = false;
				break;
			}
		}
		
		if (isPrime) {
			primeNumbers[numberOfPrimes++] = number;
		}
	}
	auto end = Clock::now();

	double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

	util::displayProcessingTime(processingTime);
	util::displayPrimeNumbers(primeNumbers, numberOfPrimes);

	delete[] primeNumbers;
}


//Odd numbers except of 2 cannot be prime
void seqDiv2(const int LOWER_BOUND, const int HIGHER_BOUND) {

	int numberOfPrimes = 0;
	int startNumber = LOWER_BOUND;
	int* primeNumbers = new int[HIGHER_BOUND - LOWER_BOUND + 1];

	auto start = Clock::now();
	if (LOWER_BOUND % 2 == 0) {
		startNumber = LOWER_BOUND + 1;

		if (LOWER_BOUND == 2) {
			primeNumbers[numberOfPrimes++] = 2;
		}
	}

	for (int number = startNumber; number <= HIGHER_BOUND; number += 2) {
		bool isPrime = true;
		const int HIGHEST_DIVISOR = util::getHighestDivisor(number);

		for (int divisor = 3; divisor <= HIGHEST_DIVISOR; divisor += 2) {
			if (number % divisor == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			primeNumbers[numberOfPrimes++] = number;
		}
	}
	auto end = Clock::now();

	double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

	util::displayProcessingTime(processingTime);
	util::displayPrimeNumbers(primeNumbers, numberOfPrimes);
}

void seqDivPrimes1(const int LOWER_BOUND, const int HIGHER_BOUND) {
	const int INTERVAL = HIGHER_BOUND - LOWER_BOUND + 1;
	int numberOfPrimes = 0;
	int* primeNumbers = new int[INTERVAL];
	int* calculatedPrimes = new int[INTERVAL];
	int numberOfCalculatedPrimes;
	int startNumber = LOWER_BOUND;

	auto start = Clock::now();
	numberOfCalculatedPrimes = util::calculatePrimes(calculatedPrimes, util::getHighestDivisor(HIGHER_BOUND));

	for (int i = 0; i < numberOfCalculatedPrimes; ++i)
		if (calculatedPrimes[i] >= LOWER_BOUND) primeNumbers[numberOfPrimes++] = calculatedPrimes[i];

	if (numberOfPrimes) startNumber = primeNumbers[numberOfPrimes - 1] + 1;


	for (int number = startNumber; number <= HIGHER_BOUND; ++number) {
		bool isPrime = true;

		for (int i = 0; i < numberOfCalculatedPrimes; i++) {
			if (number % calculatedPrimes[i] == 0) {
				isPrime = false;
				break;
			}
		}
			
		if (isPrime) primeNumbers[numberOfPrimes++] = number;
	}
	auto end = Clock::now();
	double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

	util::displayProcessingTime(processingTime);
	util::displayPrimeNumbers(primeNumbers, numberOfPrimes);

	delete[] primeNumbers;
	delete[] calculatedPrimes;
}