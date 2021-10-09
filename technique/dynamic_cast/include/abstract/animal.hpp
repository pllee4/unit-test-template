/*
 * animal.hpp
 * Created on: Oct 09, 2021 20:39
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <stdint.h>

namespace pllee4 {
struct Animal {
 public:
  virtual ~Animal() {}

  virtual uint8_t GetAge() const = 0;
};
}  // namespace pllee4

#endif /* ANIMAL_HPP */
