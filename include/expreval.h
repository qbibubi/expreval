#pragma once

#include "debug.h"
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>

namespace expreval {

void shunting_yard(const std::string &expression);
void remove_whitespace(std::string &expression);

}; // namespace expreval
