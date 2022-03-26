/*
 * variadic_overloading.hpp
 *
 * Created on: Mar 26, 2022 22:47
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef VARIADIC_OVERLOADING_HPP
#define VARIADIC_OVERLOADING_HPP

#include <cstdint>
#include <type_traits>
#include <vector>

namespace pllee4 {
template <typename T>
class SubIndexObj {
 public:
  T operator[](uint16_t idx) { return subindex_table[idx]; }

  template <typename E>
  void UpdateSubIndexTable(E value) {
    static_assert(std::is_same<T, E>::value,
                  "Only same type of element is allowed");
    subindex_table.emplace_back(value);
  }

  template <typename E, typename... Es>
  void UpdateSubIndexTable(E value, Es... values) {
    UpdateSubIndexTable(value);
    UpdateSubIndexTable(values...);
  }

  std::vector<T> GetSubIndexTable() const { return subindex_table; }

 private:
  std::vector<T> subindex_table;
};
}  // namespace pllee4
#endif /* VARIADIC_OVERLOADING_HPP */