#pragma once

#include "debug.h"
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <vector>

namespace expreval {
std::vector<char> tokenize(const std::string &expression);
void shunting_yard(const std::string &expression);
}; // namespace expreval
