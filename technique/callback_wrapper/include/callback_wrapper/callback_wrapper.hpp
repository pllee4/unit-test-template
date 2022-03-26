/*
 * callback_wrapper.hpp
 *
 * Created on: Mar 21, 2022 22:30
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef CALLBACK_WRAPPER_HPP
#define CALLBACK_WRAPPER_HPP

#include <any>
#include <memory>
#include <type_traits>

#include "function_traits/function_traits.hpp"

namespace pllee4 {
struct CallbackWrapper {
  struct CallbackBase {
    virtual bool operator()(const std::type_info& type) const = 0;
    virtual void operator()(const std::any& data) = 0;
    virtual ~CallbackBase() {}
  };

  template <typename T>
  struct Wrapper : public CallbackBase {
    typedef typename function_traits<T>::template arg<0> arg_type;
    Wrapper(const T& t) : wrapped_obj(t) {}

    bool operator()(const std::type_info& type) const override {
      if (typeid(arg_type) == type) {
        return true;
      } else {
        return false;
      }
    }

    void operator()(const std::any& data) override {
      wrapped_obj(std::any_cast<arg_type>(data));
    }

    T wrapped_obj;
  };

  template <typename T>
  CallbackWrapper(T&& obj)
      : wrapped_callback(
            std::make_unique<Wrapper<typename std::remove_reference<T>::type>>(
                std::forward<T>(obj))) {}

  bool operator()(const std::type_info& type) {
    return (*wrapped_callback)(type);
  }

  void operator()(const std::any& data) { (*wrapped_callback)(data); }

  std::unique_ptr<CallbackBase> wrapped_callback;
};
}  // namespace pllee4
#endif /* CALLBACK_WRAPPER_HPP */