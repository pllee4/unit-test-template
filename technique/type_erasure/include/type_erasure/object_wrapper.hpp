/*
 * object_wrapper.hpp
 *
 * Created on: Mar 22, 2022 21:19
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef OBJECT_WRAPPER_HPP
#define OBJECT_WRAPPER_HPP

#include <memory>

namespace pllee4 {
struct ObjectWrapper {
  template <typename T>
  ObjectWrapper(T&& obj)
      : wrapped_object(std::make_shared<Wrapper<T>>(std::forward<T>(obj))) {}

  struct ObjectBase {
    virtual int operator()() const = 0;
    virtual ~ObjectBase() {}
  };

  template <typename T>
  struct Wrapper : public ObjectBase {
    Wrapper(const T& t) : wrapped_object(t) {}

    int operator()() const override { return wrapped_object(); }
    T wrapped_object;
  };

  auto operator()() const { return (*wrapped_object)(); }

  std::shared_ptr<ObjectBase> wrapped_object;
};
}  // namespace pllee4
#endif /* OBJECT_WRAPPER_HPP */