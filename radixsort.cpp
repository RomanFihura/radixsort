#include "radixsort.h"

void countSort(std::vector<uint32_t> &v, uint32_t exp)
{

    std::vector<uint32_t> output(v.size());
    std::vector<uint32_t> count(10);

    // count of repeats current digit
    for (uint32_t i = 0; i < v.size(); i++)
        count[(v[i] / exp) % 10]++;

    // change count to right order (current digit)
    for (uint32_t i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (uint32_t i = v.size(); i > 0; i--)
    {
        output[count[(v[i - 1] / exp) % 10] - 1] = v[i - 1];
        count[(v.at(i - 1) / exp) % 10]--;
    }
    v = output;
}
void radixsort(std::vector<uint32_t> &v)
{
    uint32_t max = *std::max_element(v.begin(), v.end());

    for (uint32_t exp = 1; max / exp > 0; exp *= 10)
        countSort(v, exp);
}