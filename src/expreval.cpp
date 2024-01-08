#include "expreval.h"

void expreval::remove_whitespace(std::string &expression) {
  expression.erase(
      std::remove_if(expression.begin(), expression.end(), ::isspace),
      expression.end());
}

std::vector<char> expreval::tokenize(const std::string &expression) {
  std::vector<char> tokens;
  for (const auto &token : expression) {
    tokens.push_back(token);
  }
  return tokens;
}

void expreval::shunting_yard(std::string &expression) {
  if (expression.empty() && expression.data() != nullptr) {
    return;
  }

  std::stack<char> operators;
  std::stack<char> output;
  remove_whitespace(expression);

  // tokenize
  std::vector<char> tokens = tokenize(expression);
  while (!tokens.empty()) {
    for (const auto &token : tokens) {
      if (std::isdigit(token)) {
        output.push(token);
      }
    }
  }
}
