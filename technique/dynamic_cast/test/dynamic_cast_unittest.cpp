/*
 * dynamic_cast_unittest.cpp
 * Created on: Oct 09, 2021 21:24
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "dog.hpp"
#include "lion.hpp"

#include "gtest/gtest.h"

using namespace pllee4;

std::string GetAnimalInfo(Animal *animal) {
  std::string info;
  auto pet = dynamic_cast<Pet *>(animal);
  if (pet) info += "name: " + pet->GetName() + " ";
  info += "age: " + std::to_string(animal->GetAge());
  return info;
}

TEST(DynamicCast, DownCast) {
  Animal *animal = new Lion(2);
  EXPECT_TRUE(GetAnimalInfo(animal) == "age: 2");
  animal = new Dog("Lucky", 5);
  EXPECT_TRUE(GetAnimalInfo(animal) == "name: Lucky age: 5");
  delete animal;
}