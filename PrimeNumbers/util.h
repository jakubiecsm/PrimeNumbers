#pragma once

#include "PrimeNumbersResult.h"
#include <Windows.h>
#include <chrono>

using namespace std;

namespace util {

	void displayResult(PrimeNumbersResult primeNumbersResult);
	void getPrimeNumberBounds(int* lowestNumber, int* highestNumber);
	void callPrimeNumbersCalculator(PrimeNumbersResult& primeNumbersResult, void (*function)(PrimeNumbersResult&));
	bool isDivisible(int number, int divisor);
	int getHighestDivisor(int number);
}
