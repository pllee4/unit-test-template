/* 
 * example.cpp
 * Created on: Jun 10, 2021 21:12
 * Description: 
 * 
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */ 

#include "example.hpp"

bool Example::ReturnOnce() {
  static bool first = true;
  if (first) {
    first = false;
    return true;
  } 
  return first;
}