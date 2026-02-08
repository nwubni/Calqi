
#include <algorithm>
#include <string>
#include <vector>

#include "../library/calculator_functions.h"
#include "../utilities/math_constants.h"
#include "calculator_parser.h"

namespace calqi {

void parseExpression(const std::string &expression,
                     std::vector<double> &numbers,
                     std::vector<std::string> &operators) {
  std::string number{};
  std::string function{};
  char previous_character{'\0'};

  for (const char &ch : expression) {
    if (ch == ' ')
      continue;

    if (std::isalpha(ch)) {
      function += ch;
      previous_character = ch;
      continue;
    }

    if (std::isdigit(ch) || ch == '.') {
      number += ch;
      previous_character = ch;
      continue;
    }

    if (calqi::math_constants.contains(function)) {
      numbers.push_back(calqi::math_constants.at(function));
      function.clear();
    }

    if (calqi::isOperator(std::string(1, ch))) {
      if (!number.empty()) {
        numbers.push_back(std::stod(number));
        number.clear();
      }

      if (!function.empty()) {
        operators.push_back(function);
        function.clear();
      }

      if ((previous_character == ')' || std::isdigit(previous_character)) &&
          ch == '(')
        operators.push_back("*");

      if (ch == '-' &&
          (previous_character == '\0' || previous_character == '(' ||
           previous_character == '+' || previous_character == '-' ||
           previous_character == '*' || previous_character == '/' ||
           previous_character == '%' || previous_character == '^')) {
        operators.push_back("neg");
        previous_character = ch;
        continue;
      }

      if (ch == previous_character &&
          (ch == '+' || ch == '*' || ch == '/' || ch == '%' || ch == '^'))
        continue;

      operators.push_back(std::string(1, ch));
    }

    previous_character = ch;
  }

  if (!number.empty())
    numbers.push_back(std::stod(number));

  if (!function.empty()) {
    if (calqi::math_constants.contains(function)) {
      numbers.push_back(calqi::math_constants.at(function));
      function.clear();
    } else {
      operators.push_back(function);
    }
  }

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());
}

} // namespace calqi