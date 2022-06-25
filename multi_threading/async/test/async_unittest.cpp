/*
 * async_unittest.cpp
 *
 * Created on: Jun 25, 2022 17:59
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include <unistd.h>

#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

#include "gtest/gtest.h"

TEST(Future, Simple) {
  auto promise = std::promise<int>();
  int count = 0;
  auto producer = std::thread([&] {
    while (++count < 3) {
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    promise.set_value(count);
  });

  auto future = promise.get_future();
  auto consumer = std::thread([&] {
    auto value = future.get();
    EXPECT_EQ(value, 3);
  });

  producer.join();
  consumer.join();
}

TEST(Future, PackagedTask) {
  auto calculateSum = [](int a, int b) { return a + b; };

  std::packaged_task<int(int, int)> task{calculateSum};
  auto future{task.get_future()};
  // task can only be moved, cannot be copied
  std::thread my_thread{std::move(task), 1, 2};

  auto result{future.get()};
  EXPECT_EQ(result, 3);
  my_thread.join();
}

TEST(Future, AsyncDefault) {
  auto calculateSum = []() { return 123; };

  auto future{std::async(calculateSum)};
  auto result{future.get()};
  EXPECT_EQ(result, 123);
}

TEST(Future, Async) {  // asynchronously
  auto calculateSum = []() { return 123; };

  auto future{std::async(std::launch::async, calculateSum)};
  auto result{future.get()};
  EXPECT_EQ(result, 123);
}

TEST(Future, AsyncDeferred) {  // synchronously
  auto calculateSum = []() { return 123; };

  auto my_future{std::async(std::launch::deferred, calculateSum)};
  auto result{my_future.get()};
  EXPECT_EQ(result, 123);
}