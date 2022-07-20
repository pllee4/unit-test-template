/*
 * double_dispatch_unittest.cpp
 *
 * Created on: Jul 20, 2022 21:13
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "double_dispatch/double_dispatch.hpp"

#include <memory>

#include "gtest/gtest.h"

using namespace pllee4;

TEST(DoubleDispatchTest, RuntimePolymorphism) {
  Engineer engineer;
  SeniorEngineer senior_engineer;
  PrincipalEngineer principal_engineer;
  std::unique_ptr<Employee> employee;

  employee = std::make_unique<Engineer>(engineer);

  EXPECT_FALSE(employee->ReportsTo(engineer));
  EXPECT_TRUE(employee->ReportsTo(senior_engineer));
  EXPECT_TRUE(employee->ReportsTo(principal_engineer));

  employee.reset(new SeniorEngineer{senior_engineer});
  EXPECT_FALSE(employee->ReportsTo(engineer));
  EXPECT_FALSE(employee->ReportsTo(senior_engineer));
  EXPECT_TRUE(employee->ReportsTo(principal_engineer));

  employee.reset(new PrincipalEngineer{principal_engineer});
  EXPECT_FALSE(employee->ReportsTo(engineer));
  EXPECT_FALSE(employee->ReportsTo(senior_engineer));
  EXPECT_FALSE(employee->ReportsTo(principal_engineer));
}