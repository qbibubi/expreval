#pragma once

#include <iostream>
#include <string>

namespace debug {
template <typename T> void print_argument(const T &argument) {
  std::cout << argument << " ";
}

template <typename... Args>
void log(const Args &...arguments) {
  (print_argument(arguments), ...);
  std::cout << std::endl;
}
}; // namespace debug
