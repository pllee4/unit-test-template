/*
 * function_traits.hpp
 *
 * Created on: Mar 23, 2022 21:26
 * Description:
 *
 * Reference:
 * https://betterprogramming.pub/inspecting-properties-of-callables-with-function-traits-in-c-6bb2d9388fc5
 * 
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef FUNCTION_TRAITS_HPP
#define FUNCTION_TRAITS_HPP

#include <cstddef>
#include <tuple>
#include <type_traits>

template <typename Function>
struct function_traits
    : public function_traits<decltype(
          &std::remove_reference<Function>::type::operator())> {};

template <typename ClassType, typename ReturnType, typename... Arguments>
struct function_traits<ReturnType (ClassType::*)(Arguments...) const>
    : function_traits<ReturnType (*)(Arguments...)> {};

template <typename ClassType, typename ReturnType, typename... Arguments>
struct function_traits<ReturnType (ClassType::*)(Arguments...)>
    : function_traits<ReturnType (*)(Arguments...)> {};

template <typename ReturnType, typename... Arguments>
struct function_traits<ReturnType (*)(Arguments...)> {
  typedef ReturnType result_type;

  template <std::size_t Index>
  using arg =
      typename std::tuple_element<Index, std::tuple<Arguments...> >::type;

  static constexpr std::size_t arity = sizeof...(Arguments);
};
#endif /* FUNCTION_TRAITS_HPP */