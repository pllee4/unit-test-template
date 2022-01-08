/*
 * car_impl.cpp
 * Created on: Jan 07, 2022 22:46
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "car/car.h"
#include "car/details/engine.h"
#include "car/details/headlight.h"

namespace pllee4 {
class Car::impl {
 public:
  impl() {}

  ~impl() {}

  std::string GetCarInfo() {
    return "Engine: " + Engine::GetEngineName() +
           " Headlight: " + Headlight::GetHeadlightName();
  };
};
}  // namespace pllee4