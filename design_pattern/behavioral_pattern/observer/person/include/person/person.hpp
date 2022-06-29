/*
 * person.hpp
 *
 * Created on: Jun 29, 2022 22:04
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef PERSON_HPP
#define PERSON_HPP

#include <boost/signals2.hpp>
#include <string>

namespace pllee4 {
template <typename T>
struct Observable {
  boost::signals2::signal<void(T &, const std::string &)> property_changed;
};

struct Person : Observable<Person> {
  Person(int age) : age(age) {}

  int GetAge() const { return age; }

  void SetAge(const int age) {
    if (this->age == age) return;
    this->age = age;
    property_changed(*this, "age");
  }

 private:
  int age;
};
}  // namespace pllee4

#endif /* PERSON_HPP */
