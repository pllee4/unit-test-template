
#include "merge_sort/merge_sort.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace pllee4;
using namespace merge_sort;

TEST(MergeSort, Sort) {
  int arr[] = {100, 1, 400, 3, 4};
  MergeSort<int>(arr, 0, 5);
  int test_arr[] = {1, 3, 4, 100, 400};
  ASSERT_THAT(std::vector<int>(arr, arr + 5),
              testing::ElementsAreArray(test_arr));
}