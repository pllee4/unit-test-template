/*
 * lion.hpp
 * Created on: Oct 09, 2021 21:09
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef LION_HPP
#define LION_HPP

#include "abstract/animal.hpp"

namespace pllee4 {
class Lion : public Animal {
 public:
  Lion(uint8_t age) : age_(age) {}

  uint8_t GetAge() const override { return age_; }

 private:
  uint8_t age_{0};
};
}  // namespace pllee4
#endif /* LION_HPP */
