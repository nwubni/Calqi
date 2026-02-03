
#include <algorithm>
#include <string>
#include <vector>

#include "calculator_parser.h"
#include "../library/calculator_functions.h"

void parseExpression(const std::string &expression, std::vector<int> &numbers,
                     std::vector<char> &operators) {
  std::string number{};
  char previousCharacter{};

  for (const char &ch : expression) {
    if (std::isdigit(ch)) {
      number += ch;
      previousCharacter = ch;
      continue;
    }

    if (isOperator(ch)) {
      if (!number.empty()) {
        numbers.push_back(std::stoi(number));
        number.clear();
      }

      if ((previousCharacter == ')' || std::isdigit(previousCharacter)) &&
          ch == '(')
        operators.push_back('*');

      operators.push_back(ch);
    }

    previousCharacter = ch;
  }

  if (!number.empty())
    numbers.push_back(std::stoi(number));

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());
}