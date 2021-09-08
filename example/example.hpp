/* 
 * example.hpp
 * Created on: Jun 10, 2021 21:17
 * Description: 
 * 
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */ 

#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

class Example {
  public:
    Example()= default;
    ~Example() = default;

    bool ReturnStaticLocalVariable();
    bool ReturnPrivateMember();
  private:
    bool first_ = true;
};

#endif /* EXAMPLE_HPP */
