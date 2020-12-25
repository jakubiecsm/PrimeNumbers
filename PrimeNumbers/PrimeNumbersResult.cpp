#include "PrimeNumbersResult.h"

void initializeArrayWithOnes(bool* array, int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = 1;
	}
}

PrimeNumbersResult::PrimeNumbersResult(int lowestBound, int highestBound, bool eratostenes) {
	this->eratostenes = eratostenes;
	this->lowestBound = lowestBound;
	this->highestBound = highestBound;
	this->computingTime = 0;
	this->processedNumbers = new bool[highestBound - lowestBound + 1]{ 0 };
	this->eratostenesProcessedNumbers = new bool[highestBound - 1];
	initializeArrayWithOnes(this->eratostenesProcessedNumbers, highestBound - 1);
}

PrimeNumbersResult::~PrimeNumbersResult() {
}

bool PrimeNumbersResult::isEratostenes() {
	return eratostenes;
}

bool* PrimeNumbersResult::getProcessedNumbers() {
	return processedNumbers;
}

bool* PrimeNumbersResult::getEratostenesProcessedNumbers() {
	return eratostenesProcessedNumbers;
}

double PrimeNumbersResult::getComputingTime() {
	return computingTime;
}

int PrimeNumbersResult::getLowestBound() {
	return lowestBound;
}

int PrimeNumbersResult::getHighestBound() {
	return highestBound;
}

std::string PrimeNumbersResult::getAlgorithmName() {
	return algorithmName;
}

void PrimeNumbersResult::setProcessedNumbers(bool* processedNumbers) {
	this->processedNumbers = processedNumbers;
}

void PrimeNumbersResult::setComputingTime(double computingTime) {
	this->computingTime = computingTime;
}

void PrimeNumbersResult::setAlgorithmName(std::string algorithmName) {
	this->algorithmName = algorithmName;
}
