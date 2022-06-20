/* 
 * quick_sort_unittest.cpp
 * 
 * Created on: Jun 20, 2022 21:35
 * Description: 
 * 
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */ 

#include "quick_sort/quick_sort.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace pllee4;
using namespace quick_sort;

#include <iostream>

TEST(QuickSort, SequentialSort) {
  std::list<int> list = {100, 1, 400, 3, 4};
  auto result = sequential_quick_sort(list);
  std::list<int> test_list = {1, 3, 4, 100, 400};
  ASSERT_THAT(result, testing::ElementsAreArray(test_list));
}

TEST(QuickSort, ParallelSort) {
  std::list<int> list = {100, 1, 400, 3, 4};
  auto result = parallel_quick_sort(list);
  std::list<int> test_list = {1, 3, 4, 100, 400};
  ASSERT_THAT(result, testing::ElementsAreArray(test_list));
}