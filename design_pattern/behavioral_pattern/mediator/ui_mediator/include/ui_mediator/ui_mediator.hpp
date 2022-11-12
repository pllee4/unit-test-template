/*
 * ui_mediator.hpp
 *
 * Created on: Nov 12, 2022 16:31
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef UI_MEDIATOR_HPP
#define UI_MEDIATOR_HPP

#include <memory>
#include <string>

namespace pllee4 {
class UiMediator;

struct UiEvent {
 protected:
  std::shared_ptr<UiMediator> mediator_;

 public:
  void SetMediator(std::shared_ptr<UiMediator> mediator) {
    mediator_ = mediator;
  }
};

class InputButton : public UiEvent {
 public:
  explicit InputButton(const std::string &id) : id_(id) {}
  // mock function that the button is pressed
  void IsPressed();

  std::string GetId() const { return id_; }

 private:
  std::string id_;
};

class InputKeyboard : public UiEvent {
 public:
  explicit InputKeyboard(const std::string &id) : id_(id) {}
  // mock function that there is input from the keyboard
  void IsTyped(const std::string &input);

  std::string GetInput() const { return input_; }
  std::string GetId() const { return id_; }

 private:
  std::string id_;
  std::string input_;
};

class UiMediator : public std::enable_shared_from_this<UiMediator> {
 public:
  UiMediator(std::shared_ptr<InputButton> submit_button,
             std::shared_ptr<InputKeyboard> keyboard);

  void Setup();
  void Notify(const std::string &event);

  std::string GetLastEvent() const { return last_event_; }
  std::string GetOutputOnScreen() const { return output_on_screen_; }

 private:
  std::shared_ptr<InputButton> submit_button_;
  std::shared_ptr<InputKeyboard> keyboard_;

  std::string keyboard_input_;
  std::string output_on_screen_;
  std::string last_event_;
};

}  // namespace pllee4
#endif /* UI_MEDIATOR_HPP */
