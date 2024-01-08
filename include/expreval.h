#pragma once

#include "debug.h"
#include <algorithm>
#include <cctype>
#include <stack>
#include <vector>

namespace expreval {
void remove_whitespace(std::string &expression);
std::vector<char> tokenize(const std::string &expression);
void shunting_yard(std::string &expression);
}; // namespace expreval
