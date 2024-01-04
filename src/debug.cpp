#include "debug.h"

template <typename T> void debug::print_argument(const T &argument) {
  std::cout << argument << ' ';
}

template <typename... Args> void debug::log(const Args &...arguments) {
  (print_argument(arguments), ...);
  std::cout << std::endl;
}
