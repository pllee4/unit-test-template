/*
 * merge_sort.hpp
 *
 * Created on: Mar 02, 2022 23:30
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <algorithm>
#include <iterator>

namespace pllee4 {
namespace merge_sort {
template <typename T>
void Merge(T array[], const int left, const int mid, const int right) {
  const auto left_arr_size = mid - left + 1;
  const auto right_arr_size = right - mid;

  // Create temp arrays
  std::vector<T> left_arr(array + left, array + left + left_arr_size);
  std::vector<T> right_arr(array + mid + 1, array + mid + 1 + right_arr_size);

  auto left_arr_index = 0,       // Initial index of first sub-array
      right_arr_index = 0;       // Initial index of second sub-array
  auto merged_arr_index = left;  // Initial index of merged array

  // Merge the temp arrays back into array[left..right]
  while (left_arr_index < left_arr_size && right_arr_index < right_arr_size) {
    if (left_arr[left_arr_index] <= right_arr[right_arr_index]) {
      array[merged_arr_index] = left_arr[left_arr_index];
      left_arr_index++;
    } else {
      array[merged_arr_index] = right_arr[right_arr_index];
      right_arr_index++;
    }
    merged_arr_index++;
  }
  // Copy the remaining elements of
  // left[], if there are any
  while (left_arr_index < left_arr_size) {
    array[merged_arr_index] = left_arr[left_arr_index];
    left_arr_index++;
    merged_arr_index++;
  }
  // Copy the remaining elements of
  // right[], if there are any
  while (right_arr_index < right_arr_size) {
    array[merged_arr_index] = right_arr[right_arr_index];
    right_arr_index++;
    merged_arr_index++;
  }
}
template <typename T>
void MergeSort(T array[], const int begin, const int end) {
  if (begin >= end) return;

  auto mid = begin + (end - begin) / 2;
  MergeSort(array, begin, mid);
  MergeSort(array, mid + 1, end);
  Merge(array, begin, mid, end);
}
}  // namespace merge_sort
}  // namespace pllee4

#endif /* MERGE_SORT_HPP */
