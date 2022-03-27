/*
 * constexpr_for.hpp
 *
 * Created on: Mar 27, 2022 18:41
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef CONSTEXPR_FOR_HPP
#define CONSTEXPR_FOR_HPP

#include <cstddef>
#include <tuple>

template <auto Start, auto End, auto Inc, class F>
constexpr void constexpr_for(F &&f) {
  if constexpr (Start < End) {
    f(std::integral_constant<decltype(Start), Start>());
    constexpr_for<Start + Inc, End, Inc>(f);
  }
}

template <class F, class Tuple>
constexpr void constexpr_for_tuple(F &&f, Tuple &&tuple) {
  constexpr size_t cnt = std::tuple_size_v<std::decay_t<Tuple>>;
  constexpr_for<size_t(0), cnt, size_t(1)>(
      [&](auto i) { f(std::get<i.value>(tuple)); });
}

#endif /* CONSTEXPR_FOR_HPP */
