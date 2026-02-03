
#include <iostream>
#include <vector>

#include "calculator_functions.h"

int add(const int &a, const int &b) { return a + b; }

int subtract(const int &a, const int &b) { return a - b; }

int multiply(const int &a, const int &b) { return a * b; }

int divide(const int &a, const int &b) {
  if (b == 0) {
    std::cerr << "Error: Division by zero\n";
    return 0; // or handle error appropriately
  }

  return a / b;
}

bool isOperator(const char &c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

bool isAdditionOrSubtraction(const char &op) { return op == '+' || op == '-'; }

bool isMultiplicationOrDivision(const char &op) {
  return op == '*' || op == '/';
}

int evaluate(std::vector<int> &numbers, std::vector<char> &operators) {
  if (numbers.empty())
    return 0;

  char op{};
  int operand1{};
  int operand2{};
  int result{0};
  std::vector<int> tempNumbers{};
  std::vector<char> tempOperators{};

  while (!numbers.empty() && !operators.empty()) {
    operand1 = 0;

    if (!numbers.empty()) {
      operand1 = numbers.back();
      numbers.pop_back();
    }

    op = operators.back();
    operators.pop_back();

    if (!operators.empty() &&
        ((op != '(' && operators.back() == '(') ||
         (isAdditionOrSubtraction(op) &&
          isMultiplicationOrDivision(operators.back())))) {
      tempNumbers.push_back(operand1);
      tempOperators.push_back(op);
      continue;
    }

    while (
        !operators.empty() &&
        operators.back() ==
            '(') { // Advance to the innermost expression in nested parentheses
      operators.pop_back();
    }

    operand2 = 0;

    if (!numbers.empty()) {
      operand2 = numbers.back();
      numbers.pop_back();
    }

    switch (op) {
    case '(':
      if (result != 0)
        tempNumbers.push_back(result);

      if (operand2 != 0)
        numbers.push_back(operand2);

      if (operand1 != 0)
        numbers.push_back(operand1);

      continue;
    case ')':
      if (operand2 != 0)
        numbers.push_back(operand2);

      if (operand1 != 0)
        numbers.push_back(operand1);

      if (!tempNumbers.empty()) {
        numbers.push_back(tempNumbers.back());
        tempNumbers.pop_back();
      }

      if (!tempOperators.empty()) {
        operators.push_back(tempOperators.back());
        tempOperators.pop_back();
      }

      if (operators.empty()) {
        while (!tempNumbers.empty()) {
          numbers.push_back(tempNumbers.back());
          tempNumbers.pop_back();
        }
      }

      continue;
    case '+':
      result = add(operand1, operand2);
      break;
    case '-':
      result = subtract(operand1, operand2);
      break;
    case '*':
      result = multiply(operand1, operand2);
      break;
    case '/':
      result = divide(operand1, operand2);
      break;
    default:
      std::cerr << "Error: Unknown operator " << op << "\n";
      return 0;
    }

    numbers.push_back(result);
    result = 0;

    while (!tempNumbers.empty()) {
      numbers.push_back(tempNumbers.back());
      tempNumbers.pop_back();
    }

    while (!tempOperators.empty()) {
      operators.push_back(tempOperators.back());
      tempOperators.pop_back();
    }
  }

  if (!numbers.empty()) {
    result = numbers.back();
    numbers.pop_back();
  }

  return result;
}