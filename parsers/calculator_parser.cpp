
#include <algorithm>
#include <string>
#include <vector>

#include "../library/calculator_functions.h"
#include "calculator_parser.h"

void parseExpression(const std::string &expression, std::vector<double> &numbers,
                     std::vector<std::string> &operators) {
  std::string number{};
  std::string function{};
  char previousCharacter{};

  for (const char &ch : expression) {
    if (ch == ' ')
      continue;

    if (std::isalpha(ch)) {
      function += ch;
      previousCharacter = ch;
      continue;
    }

    if (std::isdigit(ch) || ch == '.') {
      number += ch;
      previousCharacter = ch;
      continue;
    }

    if (isOperator(std::string(1, ch))) {
      if (!number.empty()) {
        numbers.push_back(std::stod(number));
        number.clear();
      }

      if (!function.empty()) {
        operators.push_back(function);
        function.clear();
      }

      if ((previousCharacter == ')' || std::isdigit(previousCharacter)) &&
          ch == '(')
        operators.push_back("*");

      if (ch == previousCharacter && (ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '^'))
        continue;

        operators.push_back(std::string(1, ch));
    }

    previousCharacter = ch;
  }

  if (!number.empty())
    numbers.push_back(std::stod(number));

  if (!function.empty())
    operators.push_back(function);

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());
}