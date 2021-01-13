#pragma once

#include "util.h"

void util::displayProcessingTime(double processingTime) {
	cout << "\nCalculation time: " << processingTime << " us" << endl;
}

void util::displayPrimeNumbers(int* primeNumbers, const int NUMBER_OF_PRIMES) {
	string SEPARATOR = "\n********************************************************\n";
	cout << SEPARATOR << "Found " << NUMBER_OF_PRIMES << " prime numbers" << SEPARATOR;

	sort(primeNumbers, primeNumbers + NUMBER_OF_PRIMES);

	for (int i = 0; i < NUMBER_OF_PRIMES; ++i) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << primeNumbers[i] << "\t";
	}

}

void util::displayPrimesFromBool(bool* complexNumbers, const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_PRIMES) {
	string SEPARATOR = "\n********************************************************\n";
	cout << SEPARATOR << "Found " << NUMBER_OF_PRIMES << " prime numbers" << SEPARATOR;

	int alreadyPrinted = 0;
	const int INTERVAL_SIZE = HIGHER_BOUND - LOWER_BOUND + 1;

	for (int i = 0; i < INTERVAL_SIZE; ++i) {
		if (!complexNumbers[i]) {
			if (alreadyPrinted++ % 10 == 0) {
				cout << endl;
			}
			cout << i + LOWER_BOUND << "\t";
		}
	}
}

void util::getPrimeNumberBounds(int* lowestNumber, int* highestNumber) {

	cout << "Please enter lower bound number:"; 
	cin >> *lowestNumber;
	
	while (*lowestNumber < 0) {
		cout << "\nPlease enter lower bound number (above 0):";
		cin >> *lowestNumber;
	}

	cout << "\nPlease enter higher bound number:";
	cin >> *highestNumber;

	while (*lowestNumber > *highestNumber) {
		cout << "\nPlease enter higher bound number (above " << *lowestNumber - 1 << "):";
		cin >> *highestNumber;
	}

	system("CLS");
	cout << "Prime number will be calculated in range: [" << *lowestNumber << "; " << *highestNumber << "]\n\n";
	Sleep(2000);
}

bool util::isDivisible(int number, int divisor) {
	float result = (float)number / (float)divisor;
	
	return result == (int)result;
}

int util::getHighestDivisor(int number) {
	return (int)sqrt(number);
}

//Function returns number of already calculated primes
int util::calculatePrimes(int* primes, const int NUMBER) {
	int numberOfPrimes;
	if (NUMBER <= 2) {
		primes[0] = 2;
		return 1;
	}
	else numberOfPrimes = calculatePrimes(primes, getHighestDivisor(NUMBER));

	bool isPrime;
	for (int number = primes[numberOfPrimes - 1]; number <= NUMBER; ++number) {
		isPrime = true;
		for (int i = 0; i < numberOfPrimes; ++i) {
			if (number % primes[i] == 0) {
				isPrime = false;
				break;
			}
		}
			
		if (isPrime) primes[numberOfPrimes++] = number;
	}

	return numberOfPrimes;
}

int util::calculatePrimesSieve(int* primes, const int NUMBER) {
	bool* areNotPrime = new bool[NUMBER + 1]{ 0 };
	int numberOfCalculatedPrimes = 0;

	for (int number = 2; number <= NUMBER; ++number) {
		if (!areNotPrime[number]) {
			for (int i = 2 * number; i <= NUMBER; i += number) 
				areNotPrime[i] = true;
			
			primes[numberOfCalculatedPrimes++] = number;
		}
	}
	return numberOfCalculatedPrimes;
}