#include "include/expreval.h"

int main() {
  std::string expression = "(12 + 3) * (3 - 2) - 1";
  expreval::shunting_yard(expression);
  return 0;
}
