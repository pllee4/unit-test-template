/*
 * ui_mediator.cpp
 *
 * Created on: Nov 12, 2022 17:11
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "ui_mediator/ui_mediator.hpp"

namespace pllee4 {
void InputButton::IsPressed() {
  if (mediator_) mediator_->Notify(id_);
}

void InputKeyboard::IsTyped(const std::string &input) {
  input_ = input;
  if (mediator_) mediator_->Notify(id_);
}

UiMediator::UiMediator(std::shared_ptr<InputButton> submit_button,
                       std::shared_ptr<InputKeyboard> keyboard)
    : submit_button_(submit_button), keyboard_(keyboard) {}

void UiMediator::Setup() {
  submit_button_->SetMediator(shared_from_this());
  keyboard_->SetMediator(shared_from_this());
}

void UiMediator::Notify(const std::string &event) {
  // show output after submit button is pressed
  if (event == keyboard_->GetId()) keyboard_input_ = keyboard_->GetInput();
  if (event == submit_button_->GetId()) output_on_screen_ = keyboard_input_;
  last_event_ = event;
}
}  // namespace pllee4