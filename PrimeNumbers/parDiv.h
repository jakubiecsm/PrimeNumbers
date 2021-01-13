#pragma once

#include "util.h"
#include <omp.h>

void parDiv1(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS);
void parDiv2(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS);
void parDivPrimes1(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS);
