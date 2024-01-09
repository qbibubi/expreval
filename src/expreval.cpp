#include "expreval.h"

bool expreval::is_operator(char token) {
  return token == '+' || token == '-' || token == '*' || token == '/';
}

int expreval::get_precedence(char op) {
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
  std::queue<std::string> output;
  std::stack<char> operators;

  for (char c : expression) {
    if (std::isspace(c)) {
      continue;
    }

    if (std::isdigit(c)) {
      std::string operand;
      while (std::isdigit(c) || (c == '.' && std::isdigit(expression[c + 1]))) {
        operand += c;
        ++c;
        if (static_cast<std::size_t>(c) >= expression.size()) {
          break;
        }
      }
      output.push(operand);

    } else if (is_operator(c)) {
      using namespace expreval;

      while (!operators.empty() && is_operator(operators.top()) &&
             get_precedence(c) <= get_precedence(operators.top())) {
        output.push(std::string(1, operators.top()));
        operators.pop();
      }
      operators.push(c);

    } else if (c == '(') {
      operators.push(c);

    } else if (c == ')') {
      while (!operators.empty() && operators.top() != '(') {
        output.push(std::string(1, operators.top()));
        operators.pop();
      }

      if (!operators.empty() && operators.top() == '(') {
        operators.pop();
      } else {
        // hadnle shit
        std::cerr << "Mismatched parenthesis!" << std::endl;
        return {};
      }
    }
  }

  return output;
}
