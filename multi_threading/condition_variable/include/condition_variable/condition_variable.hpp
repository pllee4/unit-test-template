/*
 * condition_variable.hpp
 *
 * Created on: Jun 04, 2022 10:07
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef CONDITION_VARIABLE_HPP
#define CONDITION_VARIABLE_HPP

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

namespace pllee4 {
template <typename T>
class Messaging {
 public:
  Messaging() = default;
  ~Messaging() {
    if (receiver_.joinable()) {
      receiver_.join();
    }
  }

  void Run() { receiver_ = std::thread(&Messaging::Receiver, this); }

  T GetValue() const { return value_; }

  void PutMessage(const T &value) {
    {
      std::lock_guard<std::mutex> lock(mutex_);
      msg_queue_.push(value);
    }
    cv_.notify_one();
  }

 private:
  T value_;
  std::thread receiver_;
  std::condition_variable cv_;
  std::mutex mutex_;

  std::queue<T> msg_queue_;

  void Receiver() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [&]() { return not msg_queue_.empty(); });
    value_ = msg_queue_.front();
    msg_queue_.pop();
    lock.unlock();
  }
};
}  // namespace pllee4

#endif /* CONDITION_VARIABLE_HPP */
