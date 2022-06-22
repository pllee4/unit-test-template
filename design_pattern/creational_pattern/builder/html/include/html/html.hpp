/*
 * html.hpp
 *
 * Created on: Jun 22, 2022 22:23
 * Description:
 *
 * Reference:
 * Design Patterns in Modern C++: Reusable Approaches for Object-Oriented
 * Software Design
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef HTML_HPP
#define HTML_HPP

#include <string>
#include <vector>

namespace pllee4 {
struct HtmlElement {
  std::string name;
  std::string text;
  std::vector<HtmlElement> elements;

  HtmlElement() = default;
  HtmlElement(const std::string &name, const std::string &text)
      : name(name), text(text) {}

  // simplify for easier test
  std::string str() const {
    std::string full_str{name};
    for (const auto &elem : elements) {
      full_str.append("\n->" + elem.name + " " + elem.text);
    }
    return full_str;
  }
};

struct HtmlBuilder {
  HtmlElement root;

  HtmlBuilder(const std::string &root_name) { root.name = root_name; }

  HtmlBuilder &add_child(const std::string &child_name,
                         const std::string &child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
  }

  std::string str() { return root.str(); }
};
}  // namespace pllee4
#endif /* HTML_HPP */
