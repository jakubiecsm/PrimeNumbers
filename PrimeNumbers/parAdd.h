#pragma once

#include "util.h"
#include <omp.h>

void parAddFunc(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS);
void parAddDom(const int LOWER_BOUND, const int HIGHER_BOUND, const int NUMBER_OF_THREADS);