#pragma once
#include "util.h"
#include "PrimeNumbersResult.h"
#include <iostream>

//Even numbers (except of 2) cannot be prime + if number is not divisible by 2, it won't be by 4, 6, 8... etc.
void performSequenceDivisionV3Primes(PrimeNumbersResult& primeNumbersResult);
