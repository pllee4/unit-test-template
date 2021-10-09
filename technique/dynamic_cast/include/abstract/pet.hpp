/*
 * pet.hpp
 * Created on: Oct 09, 2021 20:39
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef PET_HPP
#define PET_HPP

#include <string>

namespace pllee4 {
struct Pet {
 public:
  virtual ~Pet() {}

  virtual std::string GetName() const = 0;
};
}  // namespace pllee4

#endif /* PET_HPP */
