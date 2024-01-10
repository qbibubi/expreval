#include "include/expreval.h"

int main() {
  // std::string expression = "(12 + 3) * (3 - 2) - 1";
  std::string expression = "3 + 4 * (2 - 7) / 5";
  auto postfix = expreval::shunting_yard(expression);

  while (!postfix->empty()) {
    std::cout << postfix->front() << ' ';
    postfix->pop();
  }
  std::cout << std::endl;

  return 0;
}
