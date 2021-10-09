/*
 * dog.hpp
 * Created on: Oct 09, 2021 21:09
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef DOG_HPP
#define DOG_HPP

#include "abstract/animal.hpp"
#include "abstract/pet.hpp"

namespace pllee4 {
class Dog : public Animal, public Pet {
 public:
  Dog(std::string name, uint8_t age) : name_(name), age_(age) {}

  uint8_t GetAge() const override { return age_; }
  std::string GetName() const override { return name_; }

 private:
  std::string name_;
  uint8_t age_{0};
};
}  // namespace pllee4
#endif /* DOG_HPP */
