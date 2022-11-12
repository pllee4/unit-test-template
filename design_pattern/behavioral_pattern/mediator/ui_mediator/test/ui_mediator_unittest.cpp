/*
 * ui_mediator_unittest.cpp
 *
 * Created on: Nov 12, 2022 17:22
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "ui_mediator/ui_mediator.hpp"

#include "gtest/gtest.h"

using namespace pllee4;

TEST(MediatorTest, UiMediator) {
  auto submit_button = std::make_shared<InputButton>("Submit Button");
  auto keyboard = std::make_shared<InputKeyboard>("Keyboard");
  auto ui_mediator = std::make_shared<UiMediator>(submit_button, keyboard);
  ui_mediator->Setup();

  submit_button->IsPressed();
  EXPECT_STREQ(std::string{"Submit Button"}.c_str(),
               ui_mediator->GetLastEvent().c_str());

  keyboard->IsTyped("InputFromKeyboard");
  EXPECT_STREQ(std::string{"Keyboard"}.c_str(),
               ui_mediator->GetLastEvent().c_str());

  submit_button->IsPressed();
  EXPECT_STREQ(std::string{"InputFromKeyboard"}.c_str(),
               ui_mediator->GetOutputOnScreen().c_str());
}