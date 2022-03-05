/*
 * grid.hpp
 *
 * Created on: Mar 01, 2022 22:14
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef GRID_HPP
#define GRID_HPP

#include <cstddef>
#include <optional>
#include <vector>

namespace pllee4 {
template <typename T>
class Grid {
 public:
  explicit Grid(size_t width = default_width, size_t height = default_height)
      : width_{width}, height_{height} {
    cells_.resize(width);
    for (auto &column : cells_) {
      column.resize(height);
    }
  };
  virtual ~Grid() = default;

  // Explicitly default a copy constructor and assignment operator
  Grid(const Grid &src) = default;
  Grid &operator=(const Grid &rhs) = default;

  template <typename E>
  Grid(const Grid<E> &src) : Grid{src.GetWidth(), src.GetHeight()} {
    // the cros-initializer of this constructor delegates first to the non-copy
    // constructor to allocate the proper amount of memory
    for (size_t i{0}; i < width_; ++i) {
      for (size_t j{0}; j < height_; ++j) {
        cells_[i][j] = src.at(i, j);
      }
    }
  }

  template <typename E>
  Grid &operator=(const Grid<E> &rhs) {
    // Copy-and-swap idiom
    Grid<T> temp{rhs};
    swap(temp);
    return *this;
  }

  void swap(Grid &other) noexcept {
    std::swap(width_, other.width_);
    std::swap(height_, other.height_);
    std::swap(cells_, other.cells_);
  }

  const std::optional<T> &at(size_t x, size_t y) const {
    VerifyCoordinate(x, y);
    return cells_[x][y];
  }

  std::optional<T> &at(size_t x, size_t y) {
    return const_cast<std::optional<T> &>(std ::as_const(*this).at(x, y));
  }

  size_t GetHeight() const { return height_; }
  size_t GetWidth() const { return width_; }

  static const size_t default_width{10};
  static const size_t default_height{10};

 private:
  void VerifyCoordinate(size_t x, size_t y) const {
    if (x >= width_) {
      throw std::out_of_range("x exceeded width!");
    }
    if (y >= height_) {
      throw std::out_of_range("y exceeded height!");
    }
  }
  std::vector<std::vector<std::optional<T>>> cells_;
  size_t width_{0}, height_{0};
};
}  // namespace pllee4
#endif /* GRID_HPP */
