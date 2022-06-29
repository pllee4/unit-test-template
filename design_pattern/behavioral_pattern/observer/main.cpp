// #include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <iostream>
#include <string>

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

int main(int argc, char **argv) {
  Person p{123};
  auto conn = p.property_changed.connect(
      [](Person &my_person, const std::string &prop_name) {
        std::cout << prop_name << " has been changed to" << std::endl;
        std::cout << my_person.GetAge() << std::endl;
      });

  p.SetAge(20);  // name has been changed
  conn.disconnect();
}