#include "radixsort.h"

#include <gtest/gtest.h>

TEST(radixsort, correct)
{
    std::vector<uint32_t> test = {2530, 444, 53, 45, 4, 1, 87, 667};
    radixsort(test);

    for (uint32_t i = 1; i < test.size(); i++)
    {
        ASSERT_LT(test[i - 1], test[i]);
    }
}
