#include "grid/grid.hpp"

#include "gtest/gtest.h"

using namespace pllee4;

TEST(GridMethodTemplate, CopyConstructor) {
  Grid<int> myIntGrid;
  myIntGrid.at(0, 0) = 10;
  Grid<int> anotherIntGrid{myIntGrid};
  int y{anotherIntGrid.at(0, 0).value_or(0)};
  EXPECT_EQ(y, 10);
}

TEST(GridMethodTemplate, TemplatizedCopyConstructor) {
  Grid<int> myIntGrid;
  myIntGrid.at(0, 0) = 10;
  Grid<double> myDoubleGrid{myIntGrid};
  double y{myDoubleGrid.at(0, 0).value_or(0.0)};
  EXPECT_EQ(y, 10.0);
}

TEST(GridMethodTemplate, TemplatizedAssignmentOperator) {
  Grid<int> myIntGrid;
  myIntGrid.at(0, 0) = 10;
  Grid<double> myDoubleGrid;
  myDoubleGrid = myIntGrid;
  double y{myDoubleGrid.at(0, 0).value_or(0.0)};
  EXPECT_EQ(y, 10.0);
}

TEST(Grid, Exception) {
  Grid<double> myDoubleGrid{10, 10};
  try {
    myDoubleGrid.at(100, 0) = 10.0;
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("x exceeded width!"));
  }
  try {
    myDoubleGrid.at(0, 100) = 10.0;
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("y exceeded height!"));
  }
}

TEST(Grid, PointerTypes) {
  Grid<const char*> myStringGrid;
  myStringGrid.at(5, 5) = "hello";
  const char* string{myStringGrid.at(5, 5).value_or(" ")};
  EXPECT_EQ(string, "hello");
}

TEST(Grid, TemplateTypes) {
  Grid<std::vector<int>> gridOfVectors;
  std::vector<int> myVector{1, 2, 3, 4};
  gridOfVectors.at(5, 5) = myVector;
  std::vector<int> testVector{gridOfVectors.at(5, 5).value()};
  EXPECT_EQ(testVector, myVector);
}

TEST(Grid, FreeStore) {
  auto myGridOnFreeStore{std::make_unique<Grid<int>>(2, 2)};
  myGridOnFreeStore->at(0, 0) = 10;
  int y{myGridOnFreeStore->at(0, 0).value_or(0)};
  EXPECT_EQ(y, 10);
}