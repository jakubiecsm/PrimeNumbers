#pragma once

#include <Windows.h>
#include <chrono>
#include <algorithm>
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

namespace util {

	void displayProcessingTime(double processingTime);
	void displayPrimeNumbers(int* primeNumbers, const int NUMBER_OF_PRIMES);
	void displayPrimesFromBool(bool* complexNumbers, const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_PRIMES);
	void getPrimeNumberBounds(int* lowestNumber, int* highestNumber);
	bool isDivisible(int number, int divisor);
	int getHighestDivisor(int number);
	int calculatePrimes(int* primes, const int NUMBER);
	int calculatePrimesSieve(int* primes, const int NUMBER);
}
