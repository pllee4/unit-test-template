/*
 * double_dispatch.hpp
 *
 * Created on: Jul 19, 2022 22:07
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef DOUBLE_DISPATCH_HPP
#define DOUBLE_DISPATCH_HPP

namespace pllee4 {
class Engineer;
class SeniorEngineer;
class PrincipalEngineer;

class Employee {
 public:
  virtual bool ReportsTo(const Employee& employee) const = 0;

  virtual bool IsUnder(const Engineer&) const = 0;
  virtual bool IsUnder(const SeniorEngineer&) const = 0;
  virtual bool IsUnder(const PrincipalEngineer&) const = 0;
};

class Engineer : Employee {
 public:
  bool ReportsTo(const Employee& employee) const override {
    return employee.IsUnder(*this);
  }
  bool IsUnder(const Engineer&) const override { return false; }
  bool IsUnder(const SeniorEngineer&) const override { return true; }
  bool IsUnder(const PrincipalEngineer&) const override { return true; }
};

class SeniorEngineer : Employee {
 public:
  bool ReportsTo(const Employee& employee) const override {
    return employee.IsUnder(*this);
  }
  bool IsUnder(const Engineer&) const override { return false; }
  bool IsUnder(const SeniorEngineer&) const override { return false; }
  bool IsUnder(const PrincipalEngineer&) const override { return true; }
};

class PrincipalEngineer : Employee {
 public:
  bool ReportsTo(const Employee& employee) const override {
    return employee.IsUnder(*this);
  }
  bool IsUnder(const Engineer&) const override { return false; }
  bool IsUnder(const SeniorEngineer&) const override { return false; }
  bool IsUnder(const PrincipalEngineer&) const override { return false; }
};
}  // namespace pllee4

#endif /* DOUBLE_DISPATCH_HPP */
