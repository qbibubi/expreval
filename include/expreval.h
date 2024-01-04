#pragma once

#include "debug.h"
#include "stack.h"

namespace expreval {

void recursive_descent_recognition(const std::string &expression);

class Parser;

}; // namespace expreval
