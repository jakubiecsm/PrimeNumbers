#include "util.h"

void printAlgorithmName(string algorithmName);
void printPrimesFromDivision(bool* processedNumbers, int& howManyPrimeNumbers, const int HOW_MANY, const int LOWER_BOUND);
void printPrimesFromEratostenes(bool* processedNumbers, int& howManyPrimeNumbers, const int HIGHER_BOUND, const int LOWER_BOUND);
void printNumber(int index, int lowerBound, int howManyPrinted);

void util::displayResult(PrimeNumbersResult primeNumbersResult) {
	int howManyPrimeNumbers = 0;
	const int LOWER_BOUND = primeNumbersResult.getLowestBound();
	const int HIGHER_BOUND = primeNumbersResult.getHighestBound();
	bool* processedNumbers = primeNumbersResult.getProcessedNumbers();

	printAlgorithmName(primeNumbersResult.getAlgorithmName());

	if (primeNumbersResult.isEratostenes()) {
		printPrimesFromEratostenes(primeNumbersResult.getEratostenesProcessedNumbers(), howManyPrimeNumbers, HIGHER_BOUND, LOWER_BOUND);
	}
	else {
		const int SECTION_SIZE = HIGHER_BOUND - LOWER_BOUND + 1;
		printPrimesFromDivision(primeNumbersResult.getProcessedNumbers(), howManyPrimeNumbers, SECTION_SIZE, LOWER_BOUND);
	}

	cout << endl << endl << "Found: " << howManyPrimeNumbers << " prime numbers" << endl;
	cout << "Time of computation: " << primeNumbersResult.getComputingTime() * 10e6 << " us" << endl;
}

void printPrimesFromDivision(bool* processedNumbers, int& howManyPrimeNumbers, const int HOW_MANY, const int LOWER_BOUND) {
	for (int i = 0; i < HOW_MANY; ++i) {
		if (processedNumbers[i] == 1) {
			printNumber(i, LOWER_BOUND, howManyPrimeNumbers++);
		}
	}
}

void printPrimesFromEratostenes(bool* processedNumbers, int& howManyPrimeNumbers, const int HIGHER_BOUND, const int LOWER_BOUND) {
	for (int i = LOWER_BOUND - 2; i < HIGHER_BOUND - 1; ++i) {
		if (processedNumbers[i] == 1) {
			printNumber(i - LOWER_BOUND + 2, LOWER_BOUND, howManyPrimeNumbers++);
		}
	}
}

void printAlgorithmName(string algorithmName) {
	string SEPARATOR = "\n********************************************************\n";
	cout << SEPARATOR << algorithmName << SEPARATOR;
}

void printNumber(int index, int lowerBound, int howManyPrinted) {
	const int NUMBERS_IN_ROW = 10;

	if (index != 0 && howManyPrinted % NUMBERS_IN_ROW == 0) {
		cout << endl;
	}
	cout << lowerBound + index << "\t";
}

void util::getPrimeNumberBounds(int* lowestNumber, int* highestNumber) {

	cout << "Please enter lower bound number:"; 
	cin >> *lowestNumber;
	
	while (*lowestNumber < 0) {
		cout << "\nPlease enter lower bound number (above 0):";
		cin >> *lowestNumber;
	}

	cout << "\nPlease enter lower bound number:";
	cin >> *highestNumber;

	while (*lowestNumber > *highestNumber) {
		cout << "\nPlease enter higher bound number (above " << *lowestNumber - 1 << "):";
		cin >> *highestNumber;
	}

	system("CLS");
	cout << "Prime number will be calculated in range: [" << *lowestNumber << "; " << *highestNumber << "]\n\n";
	Sleep(2000);
}

void util::callPrimeNumbersCalculator(PrimeNumbersResult& primeNumbersResult,  void(*function)(PrimeNumbersResult&)) {
	function(primeNumbersResult);
}

bool util::isDivisible(int number, int divisor) {
	float result = (float)number / (float)divisor;
	
	return result == (int)result;
}

int util::getHighestDivisor(int number) {
	return (int)sqrt(number);
}
