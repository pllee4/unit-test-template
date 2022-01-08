#include "car/car.h"
#include "gtest/gtest.h"

using namespace pllee4;

TEST(Pimpl, GetCarInfo) {
  Car car;
  EXPECT_TRUE(car.GetCarInfo() == "Engine: Volvo Headlight: Philips");
}