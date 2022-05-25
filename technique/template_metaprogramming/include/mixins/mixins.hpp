/*
 * mixins.hpp
 *
 * Created on: May 25, 2022 22:47
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef MIXINS_HPP
#define MIXINS_HPP

#include <string>

namespace pllee4 {
template <typename... Mixins>
class Point : public Mixins... {
 public:
  double x, y;
  Point() : Mixins()..., x(0.0), y(0.0) {}
  Point(double x, double y) : Mixins()..., x(x), y(y) {}
};

class Label {
 public:
  std::string label;
  Label() : label("") {}
};

class Color {
 public:
  unsigned char red = 0, green = 0, blue = 0;
};

}  // namespace pllee4
#endif /* MIXINS_HPP */
