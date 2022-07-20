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

  virtual bool ReportedBy(const Engineer&) const = 0;
  virtual bool ReportedBy(const SeniorEngineer&) const = 0;
  virtual bool ReportedBy(const PrincipalEngineer&) const = 0;
};

class Engineer : public Employee {
 public:
  bool ReportsTo(const Employee& employee) const override {
    return employee.ReportedBy(*this);
  }
  bool ReportedBy(const Engineer&) const override { return false; }
  bool ReportedBy(const SeniorEngineer&) const override { return false; }
  bool ReportedBy(const PrincipalEngineer&) const override { return false; }
};

class SeniorEngineer : public Employee {
 public:
  bool ReportsTo(const Employee& employee) const override {
    return employee.ReportedBy(*this);
  }
  bool ReportedBy(const Engineer&) const override { return true; }
  bool ReportedBy(const SeniorEngineer&) const override { return false; }
  bool ReportedBy(const PrincipalEngineer&) const override { return false; }
};

class PrincipalEngineer : public Employee {
 public:
  bool ReportsTo(const Employee& employee) const override {
    return employee.ReportedBy(*this);
  }
  bool ReportedBy(const Engineer&) const override { return true; }
  bool ReportedBy(const SeniorEngineer&) const override { return true; }
  bool ReportedBy(const PrincipalEngineer&) const override { return false; }
};
}  // namespace pllee4

#endif /* DOUBLE_DISPATCH_HPP */
