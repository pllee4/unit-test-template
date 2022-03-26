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
  using return_type = typename function_traits<T>::result_type;
  return (typeid(return_type) == type);
}

template <std::size_t Index, typename T>
bool SameTypeArity(T t, const std::type_info& type) {
  using arg_type = typename function_traits<T>::template arg<Index>;
  return (typeid(arg_type) == type);
}

TEST(FunctionTraits, Arity) { EXPECT_EQ(GetArity(FunctionWithThreeArity), 3); }

TEST(FunctionTraits, ReturnType) {
  EXPECT_FALSE(SameReturnType(FunctionWithThreeArity, typeid(void)));
  EXPECT_TRUE(SameReturnType(FunctionWithThreeArity, typeid(bool)));
}

TEST(FunctionTraits, Type) {
  EXPECT_TRUE(SameTypeArity<0>(FunctionWithThreeArity, typeid(int)));
  EXPECT_TRUE(SameTypeArity<1>(FunctionWithThreeArity, typeid(float)));
  EXPECT_TRUE(SameTypeArity<2>(FunctionWithThreeArity, typeid(bool)));
}

TEST(FunctionTraits, ValidCallable) {
  EXPECT_TRUE(FunctionWithThreeArity(1, 1.0, true));
}