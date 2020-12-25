#pragma once
#include "util.h"
#include "PrimeNumbersResult.h"
#include "parallelDivisionCommon.h"
#include <omp.h>
#include <iostream>

//Parallel division will be done with best sequence approach
void performParallelDivisionV1(PrimeNumbersResult& primeNumberResult);
