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

std::string GetAnimalInfo1(Animal *animal) {
  std::string info;
  auto pet = dynamic_cast<Pet *>(animal);
  if (pet) info += "name: " + pet->GetName() + " ";
  info += "age: " + std::to_string(animal->GetAge());
  return info;
}

std::string GetAnimalInfo2(Animal *animal) {
  std::string info;
  try {
    Pet &pet = dynamic_cast<Pet &>(*animal);
    info += "name: " + pet.GetName() + " ";
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  info += "age: " + std::to_string(animal->GetAge());
  return info;
}

TEST(DynamicCast, DownCastUsingPointer) {
  Animal *animal = new Lion(2);
  EXPECT_TRUE(GetAnimalInfo1(animal) == "age: 2");
  animal = new Dog("Lucky", 5);
  EXPECT_TRUE(GetAnimalInfo1(animal) == "name: Lucky age: 5");
  delete animal;
}

TEST(DynamicCast, DownCastUsingReference) {
  Animal *animal = new Lion(2);
  EXPECT_TRUE(GetAnimalInfo2(animal) == "age: 2");
  animal = new Dog("Lucky", 5);
  EXPECT_TRUE(GetAnimalInfo2(animal) == "name: Lucky age: 5");
  delete animal;
}