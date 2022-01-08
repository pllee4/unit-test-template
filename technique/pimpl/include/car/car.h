/*
 * car.h
 * Created on: Jan 07, 2022 22:29
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef CAR_H
#define CAR_H

#include <memory>

namespace pllee4 {
class Car {
 public:
  Car();
  ~Car();

  std::string GetCarInfo();

 private:
  class impl;
  std::unique_ptr<impl> pimpl_;
};
}  // namespace pllee4
#endif /* CAR_H */
