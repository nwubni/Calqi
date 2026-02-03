#include <algorithm>
#include <iostream>
#include <vector>

#include "parsers/calculator_parser.h"
#include "library/calculator_functions.h"

int main(int arg, char** argv) {
  if (arg < 2) {
    std::cerr << "Usage: " << argv[0] << " <expression>\n";
    return 1;
  }

  std::vector<int> numbers{};
  std::vector<char> operators{};
  std::string expression = argv[1];

  parseExpression(expression, numbers, operators);

  int result = evaluate(numbers, operators);

  std::cout << "\nAnswer: " << result << "\n";

  return 0;
}
