#include "radixsort.h"

// func to get max element
uint32_t getMax(std::vector<uint32_t> v)
{
    uint32_t max = v[0];
    for (uint32_t i = 1; i < v.size(); i++)
        if (v[i] > max)
            max = v[i];
    return max;
}
// A function to do counting sort of v[] according to current digit by exp
void countSort(std::vector<uint32_t> &v, uint32_t exp)
{
    uint32_t output[v.size()]; // output array
    uint32_t count[10] = {0};

    // count of repeats current digit
    for (uint32_t i = 0; i < v.size(); i++)
        count[(v[i] / exp) % 10]++;

    // change count to right order (current digit)
    for (uint32_t i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (uint32_t i = v.size(); i > 0; i--)
    {
        output[count[(v[i - 1] / exp) % 10] - 1] = v[i - 1];
        count[(v[i - 1] / exp) % 10]--;
    }
    // sorting arr by current digit (whole number)
    for (uint32_t i = 0; i < v.size(); i++)
        v[i] = output[i];
}
void radixsort(std::vector<uint32_t> &v)
{
    // finding max element to know have many digits we have
    uint32_t m = getMax(v);

    // sort for each digit
    for (uint32_t exp = 1; m / exp > 0; exp *= 10)
        countSort(v, exp);
}