#pragma once

#include <stdint.h>
#include <vector>

uint32_t getMax(std::vector<uint32_t> v);
void countSort(std::vector<uint32_t> &v, uint32_t exp);
void radixsort(std::vector<uint32_t> &v);
