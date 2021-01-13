#pragma once

#include "parDiv.h"

void parDiv1(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS) {

	int numberOfPrimes = 0;
	int* primeNumbers = new int[HIGHER_BOUND - LOWER_BOUND + 1]{ 0 };

	omp_set_num_threads(NUMBER_OF_THREADS);

	auto start = Clock::now();
#pragma omp parallel
	{
		int* localPrimeNumbers = new int[(HIGHER_BOUND - LOWER_BOUND + 1) / 4];
		int localNumberOfPrimes = 0;
		bool isPrime;

#pragma omp for nowait
		for (int number = LOWER_BOUND; number <= HIGHER_BOUND; ++number) {
			isPrime = true;
			const int HIGHEST_DIVISOR = util::getHighestDivisor(number);

			for (int divisor = 2; divisor <= HIGHEST_DIVISOR; ++divisor) {
				if (number % divisor == 0) {
					isPrime = false;
					break;
				}
			}

			if (isPrime) {
				localPrimeNumbers[localNumberOfPrimes++] = number;
			}
		}
#pragma omp critical
		{
			copy(localPrimeNumbers, localPrimeNumbers + localNumberOfPrimes, primeNumbers + numberOfPrimes);
			numberOfPrimes += localNumberOfPrimes;
		}
		delete[] localPrimeNumbers;
	}
	auto end = Clock::now();

	double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

	util::displayProcessingTime(processingTime);
	util::displayPrimeNumbers(primeNumbers, numberOfPrimes);
}

void parDiv2(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS) {
	const int INTERVAL = HIGHER_BOUND - LOWER_BOUND + 1;
	int numberOfPrimes = 0;
	int* primeNumbers = new int[INTERVAL]{ 0 };
	int startNumber = LOWER_BOUND;

	omp_set_num_threads(NUMBER_OF_THREADS);

	auto start = Clock::now();
	if (LOWER_BOUND % 2 == 0) {
		startNumber = LOWER_BOUND + 1;
		if (LOWER_BOUND == 2) primeNumbers[numberOfPrimes++] = 2;
	}

#pragma omp parallel
	{
		int* localPrimeNumbers = new int[INTERVAL / 4];
		int localNumberOfPrimes = 0;
		bool isPrime;

#pragma omp for nowait
		for (int number = startNumber; number <= HIGHER_BOUND; number += 2) {
			isPrime = true;
			const int HIGHEST_DIVISOR = util::getHighestDivisor(number);

			for (int divisor = 3; divisor <= HIGHEST_DIVISOR; divisor += 2)
				if (number % divisor == 0) {
					isPrime = false;
					break;
				}

			if (isPrime) localPrimeNumbers[localNumberOfPrimes++] = number;
		}
#pragma omp critical
		{
			copy(localPrimeNumbers, localPrimeNumbers + localNumberOfPrimes, primeNumbers + numberOfPrimes);
			numberOfPrimes += localNumberOfPrimes;
		}
		delete[] localPrimeNumbers;
	}
	auto end = Clock::now();

	double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

	util::displayProcessingTime(processingTime);
	util::displayPrimeNumbers(primeNumbers, numberOfPrimes);

	delete[] primeNumbers;
}

void parDivPrimes1(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS) {
	const int INTERVAL = HIGHER_BOUND - LOWER_BOUND + 1;
	int numberOfPrimes = 0;
	int* primeNumbers = new int[INTERVAL]{ 0 };
	int* calculatedPrimes = new int[INTERVAL]{ 0 };
	int numberOfCalculatedPrimes;
	int startNumber = LOWER_BOUND;

	omp_set_num_threads(NUMBER_OF_THREADS);
	auto start = Clock::now();
	numberOfCalculatedPrimes = util::calculatePrimes(calculatedPrimes, util::getHighestDivisor(HIGHER_BOUND));
	
	for (int i = 0; i < numberOfCalculatedPrimes; ++i)
		if (calculatedPrimes[i] >= LOWER_BOUND) primeNumbers[numberOfPrimes++] = calculatedPrimes[i];

	if (numberOfPrimes) startNumber = primeNumbers[numberOfPrimes - 1] + 1;
	
#pragma omp parallel
	{
		int* localPrimeNumbers = new int[(INTERVAL) / 4];
		int localNumberOfPrimes = 0;
		bool isPrime = true;

		//schedule(static, INTERVAL / NUMBER_OF_THREADS / 100)
		//schedule(dynamic, INTERVAL / NUMBER_OF_THREADS / 100)
		//schedule(dynamic, INTERVAL / NUMBER_OF_THREADS / 1000)
		//schedule(guided)
#pragma omp for
		for (int number = startNumber; number <= HIGHER_BOUND; number++) {

			if (number % 2 == 0) continue;
		
			isPrime = true;
			for (int i = 0; i < numberOfCalculatedPrimes; i++) {
				if (number % calculatedPrimes[i] == 0) {
					isPrime = false;
					break;
				}
			}

			if (isPrime) localPrimeNumbers[localNumberOfPrimes++] = number;
		}
#pragma omp critical
		{
			copy(localPrimeNumbers, localPrimeNumbers + localNumberOfPrimes, primeNumbers + numberOfPrimes);
			numberOfPrimes += localNumberOfPrimes;
		}
		delete[] localPrimeNumbers;
	}
	auto end = Clock::now();

	double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

	util::displayProcessingTime(processingTime);
	util::displayPrimeNumbers(primeNumbers, numberOfPrimes);

	delete[] primeNumbers;
	delete[] calculatedPrimes;
}