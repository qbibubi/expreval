#pragma once

#include "debug.h"
#include <algorithm>
#include <cctype>
#include <optional>
#include <queue>
#include <stack>
#include <vector>

namespace expreval {

bool is_operator(const char &token);
int get_precedence(const char &op);

std::optional<std::queue<std::string>>
shunting_yard(const std::string &expression);

}; // namespace expreval
