#include <gtest/gtest.h>

#include "sort.hpp"

TEST(Equal, without_equal_elemens) {
    int actual[] = {1, 8, 2, 5, 3, 11};
    const int actual_size = sizeof(actual) / sizeof(actual[0]);
    int expected[] = {1, 2, 3, 5, 8, 11};

    biv::insertion_sort(actual, actual_size);

    for (int i = 0; i < actual_size; i++) {
        ASSERT_EQ(expected[i], actual[i])
            << "Массивы отличаются в элементе с индексом " << i;
    }
}

TEST(Equal, with_equal_and_negative_elements) {
    int actual[] = {3, -2, 0, 3, -2, 1};
    const int actual_size = sizeof(actual) / sizeof(actual[0]);
    int expected[] = {-2, -2, 0, 1, 3, 3};

    biv::insertion_sort(actual, actual_size);

    for (int i = 0; i < actual_size; i++) {
        ASSERT_EQ(expected[i], actual[i])
            << "Массивы отличаются в элементе с индексом " << i;
    }
}

TEST(Equal, reverse_order) {
    int actual[] = {6, 5, 4, 3, 2, 1};
    const int actual_size = sizeof(actual) / sizeof(actual[0]);
    int expected[] = {1, 2, 3, 4, 5, 6};

    biv::insertion_sort(actual, actual_size);

    for (int i = 0; i < actual_size; i++) {
        ASSERT_EQ(expected[i], actual[i])
            << "Массивы отличаются в элементе с индексом " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
