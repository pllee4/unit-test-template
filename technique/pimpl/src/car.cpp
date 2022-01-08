/*
 * car.cpp
 * Created on: Jan 07, 2022 22:40
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "car/car.h"

#include "car_impl.cpp"

namespace pllee4 {
Car::Car() : pimpl_(new impl) {}

Car::~Car() = default;

std::string Car::GetCarInfo() { return pimpl_->GetCarInfo(); }
}  // namespace pllee4