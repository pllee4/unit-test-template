/*
 * ctrp.hpp
 *
 * Created on: Jul 11, 2022 11:52
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef CTRP_HPP
#define CTRP_HPP

#include <string>
#include <utility>

namespace pllee4 {
template <typename T>
class NameableObject {
 public:
  std::string GetName() const { return static_cast<T const&>(*this).GetName(); }
};

class MapBase : public NameableObject<MapBase> {
 public:
  std::string GetName() const { return "MapBase"; }
};

class Map : public NameableObject<Map> {
 public:
  explicit Map(const std::string& name) : name_(std::move(name)) {}
  std::string GetName() const { return name_; }

 private:
  std::string name_;
};

}  // namespace pllee4
#endif /* CTRP_HPP */
