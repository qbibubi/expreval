#pragma once

#include <iostream>
#include <string>

namespace debug {
template <typename T> void print_argument(const T &argument) {
  std::cout << argument << " ";
}

template <typename T, typename... Args>
void print_arguments(const std::string &message, const Args &...arguments) {
  print_argument(message);
  print_arguments(arguments...);
  std::cout << std::endl;
}
}; // namespace debug