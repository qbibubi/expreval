#include "expreval.h"

bool is_operator(const char &token) {
  return token == '+' || token == '-' || token == '*' || token == '/';
}

int get_precedence(const char &op) {
  if (op == '+' || op == '-') {
    return 1;
  }
  if (op == '*' || op == '/') {
    return 2;
  }
  return 0;
}

std::optional<std::queue<std::string>>
expreval::shunting_yard(const std::string &expression) {
  if (expression.empty() && expression.data() != nullptr) {
    return std::nullopt;
  }
  std::queue<std::string> output;
  std::stack<char> operators;

  for (const auto &c : expression) {
    if (std::isspace(c)) {
      continue;
    }

    if (std::isdigit(c)) {
      //
    } else if (is_operator(c)) {
      //
    } else if (c == '(') {
      //
    } else if (c == ')') {
      //
    }
  }

  return output;
}
