/*
 * quick_sort.hpp
 *
 * Created on: Jun 20, 2022 21:35
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <algorithm>
#include <future>
#include <list>

namespace pllee4 {
namespace quick_sort {
template <typename T>
std::list<T> sequential_quick_sort(std::list<T> input) {
  if (input.empty()) return input;
  std::list<T> result;
  // transfer first element into result as pivot
  result.splice(result.begin(), input, input.begin());
  T const& pivot = *result.begin();

  // partition and get divide_point
  auto divide_point = std::partition(input.begin(), input.end(),
                                     [&](T const& t) { return t < pivot; });

  // get the lower part, input is now higher part
  std::list<T> lower_part;
  lower_part.splice(lower_part.end(), input, input.begin(), divide_point);

  auto new_lower(sequential_quick_sort(std::move(lower_part)));
  auto new_higher(sequential_quick_sort(std::move(input)));

  result.splice(result.begin(), new_lower);
  result.splice(result.end(), new_higher);
  return result;
}

template <typename T>
std::list<T> parallel_quick_sort(std::list<T> input) {
  if (input.empty()) return input;
  std::list<T> result;
  // transfer first element into result as pivot
  result.splice(result.begin(), input, input.begin());
  T const& pivot = *result.begin();

  // partition and get divide_point
  auto divide_point = std::partition(input.begin(), input.end(),
                                     [&](T const& t) { return t < pivot; });

  // get the lower part, input is now higher part
  std::list<T> lower_part;
  lower_part.splice(lower_part.end(), input, input.begin(), divide_point);

  std::future<std::list<T> > new_lower(
      std::async(&parallel_quick_sort<T>, std::move(lower_part)));
  auto new_higher(parallel_quick_sort(std::move(input)));

  result.splice(result.end(), new_higher);
  result.splice(result.begin(), new_lower.get());
  return result;
}

}  // namespace quick_sort
}  // namespace pllee4
#endif /* QUICK_SORT_HPP */
