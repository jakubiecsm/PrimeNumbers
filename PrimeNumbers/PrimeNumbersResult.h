#pragma once
#include <iostream>
#include <string.h>


class PrimeNumbersResult {

private:

	bool eratostenes;
	int lowestBound;
	int highestBound;
	bool* processedNumbers;
	bool* eratostenesProcessedNumbers;
	int* primeNumbers;
	double computingTime;
	std::string algorithmName;

public:
	PrimeNumbersResult(int lowestBound, int highestBound, bool isEratostenes = false);
	~PrimeNumbersResult();

	bool isEratostenes();
	bool* getProcessedNumbers();
	bool* getEratostenesProcessedNumbers();
	double getComputingTime();
	int getLowestBound();
	int getHighestBound();
	std::string getAlgorithmName();
	
	void setProcessedNumbers(bool* processedNumbers);
	void setComputingTime(double computingTime);
	void setAlgorithmName(std::string algorithmName);

};

