/*
 * grid.hpp
 * Created on: Nov 28, 2021 21:29
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef GRID_HPP
#define GRID_HPP

#include <cstddef>
#include <optional>
#include <vector>

namespace pllee4 {
template <typename T, size_t WIDTH = 10, size_t HEIGHT = 10>
class Grid {
 public:
  Grid() = default;
  virtual ~Grid() = default;

  // Explicitly default a copy constructor and assignment operator
  Grid(const Grid &src) = default;
  Grid &operator=(const Grid &rhs) = default;

  const std::optional<T> &at(size_t x, size_t y) const {
    VerifyCoordinate(x, y);
    return cells_[x][y];
  }
  std::optional<T> &at(size_t x, size_t y) {
    return const_cast<std::optional<T> &>(std ::as_const(*this).at(x, y));
  }

  size_t GetHeight() const { return HEIGHT; }
  size_t GetWidth() const { return WIDTH; }

 private:
  void VerifyCoordinate(size_t x, size_t y) const {
    if (x >= WIDTH) {
      throw std::out_of_range("x exceeded width!");
    }
    if (y >= HEIGHT) {
      throw std::out_of_range("y exceeded height!");
    }
  };

  std::optional<T> cells_[WIDTH][HEIGHT];
};
}  // namespace pllee4

#endif /* GRID_HPP */
