/*
 * shoelace_unittest.cpp
 *
 * Created on: Aug 06, 2023 13:05
 * Description:
 *
 * Copyright (c) 2023 Pin Loon Lee (pllee4)
 */

#include <cmath>
#include <vector>

#include "gtest/gtest.h"

template <typename T>
struct Vertex {
  T x;
  T y;
};

template <typename T>
T GetArea(std::vector<Vertex<T>> vertices) {
  T sum1 = 0;
  T sum2 = 0;

  for (std::size_t i = 0; i < vertices.size() - 1; ++i) {
    sum1 += vertices[i].x * vertices[i + 1].y;
    sum2 += vertices[i + 1].x * vertices[i].y;
  }
  sum1 += vertices[vertices.size() - 1].x * vertices[0].y;
  sum2 += vertices[0].x * vertices[vertices.size() - 1].y;

  return std::abs(sum1 - sum2) / 2;
}

TEST(Shoelace, Square) {
  EXPECT_EQ(GetArea<int>({{1, 1}, {1, 4}, {3, 4}, {3, 1}}), 6);
}

TEST(Shoelace, Triangle) {
  EXPECT_EQ(GetArea<int>({{-3, 1}, {0, 4}, {3, 1}}), 9);
}

TEST(Shoelace, Trapezium) {
  EXPECT_EQ(GetArea<int>({{-4, 0}, {0, 10}, {5, 10}, {6, 0}}), 75);
}
