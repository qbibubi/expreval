#pragma once

#include <iostream>
#include <string>

namespace debug {
template <typename T> void print_argument(const T &argument);
template <typename... Args> void log(const Args &...arguments);
}; // namespace debug
