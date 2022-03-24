/*
 * function_traits_unittest.cpp
 *
 * Created on: Mar 24, 2022 21:52
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "function_traits/function_traits.hpp"

#include "gtest/gtest.h"

bool FunctionWithThreeArity(int a, float b, bool c) { return true; }

template <typename T>
auto GetArity(T t) {
  return function_traits<T>::arity;
}

template <typename T>
bool SameReturnType(T t, const std::type_info& type) {
  typedef typename function_traits<T>::result_type return_type;
  return (typeid(return_type) == type);
}

template <typename T>
bool SameTypeArity0(T t, const std::type_info& type) {
  typedef typename function_traits<T>::template arg<0> arg_type;
  return (typeid(arg_type) == type);
}

TEST(FunctionTraits, Arity) { EXPECT_EQ(GetArity(FunctionWithThreeArity), 3); }

TEST(FunctionTraits, ReturnType) {
  EXPECT_FALSE(SameReturnType(FunctionWithThreeArity, typeid(void)));
  EXPECT_TRUE(SameReturnType(FunctionWithThreeArity, typeid(bool)));
}

TEST(FunctionTraits, Type) {
  EXPECT_FALSE(SameTypeArity0(FunctionWithThreeArity, typeid(double)));
  EXPECT_TRUE(SameTypeArity0(FunctionWithThreeArity, typeid(int)));
}