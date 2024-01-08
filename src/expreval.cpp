#include "expreval.h"
#include <cctype>

std::vector<char> expreval::tokenize(const std::string &expression) {
  std::vector<char> tokens;
  for (const auto &token : expression) {
    tokens.push_back(token);
  }
  return tokens;
}

bool is_operator(const char &token) {
  return token == '+' || token == '-' || token == '*' || token == '/';
}

void expreval::shunting_yard(const std::string &expression) {
  if (expression.empty() && expression.data() != nullptr) {
    return;
  }

  std::stack<char> operators;
  std::queue<std::string> output;
  for (const auto &c : expression) {
    if (std::isspace(c)) {
      // continue
    } else if (std::isdigit(c)) {
      //
    } else if (is_operator(c)) {
      //
    } else if (c == '(') {
      //
    } else if (c == ')') {
      //
    }
  }
}
