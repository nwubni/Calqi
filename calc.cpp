#include <algorithm>
#include <iostream>
#include <vector>

#include "library/calculator_functions.h"
#include "parsers/calculator_parser.h"

int main(int arg, char **argv) {
  std::vector<double> numbers{};
  std::vector<std::string> operators{};
  std::string expression{};
  double result{};

  if (arg < 2) {
    while (true) {
      std::cout << "> ";
      std::getline(std::cin, expression);

      if (expression == "exit" || expression == "quit" || expression == "q")
        break;

      parseExpression(expression, numbers, operators);
      result = evaluate(numbers, operators);

      std::cout << "\nAnswer: " << result << "\n";
    }
  } else {
    expression = argv[1];
    parseExpression(expression, numbers, operators);
    result = evaluate(numbers, operators);

    std::cout << "\nAnswer: " << result << "\n";
  }

  return 0;
}
