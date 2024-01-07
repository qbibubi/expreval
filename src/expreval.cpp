#include "expreval.h"
#include <cctype>

void expreval::shunting_yard(td::string &expression) {
  std::stack<std::string> operators;
  std::queue<std::string> postfix_expressions;

  remove_whitespace(expression);
}

void expreval::remove_whitespace(std::string &expression) {
  expression.erase(
      std::remove_if(expression.begin(), expression.end(), ::isspace),
      expression.end());
}
