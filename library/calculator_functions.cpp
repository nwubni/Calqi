
#include <cmath>
#include <iostream>
#include <vector>

#include "../library/trigonometric_functions.h"
#include "../utilities/operator_list.h"
#include "calculator_functions.h"

double add(const double &a, const double &b) { return a + b; }

double subtract(const double &a, const double &b) { return a - b; }

double multiply(const double &a, const double &b) { return a * b; }

double divide(const double &a, const double &b) {
  if (b == 0) {
    std::cerr << "Error: Division by zero\n";
    return 0; // or handle error appropriately
  }

  return a / b;
}

double power(const double &a, const double &b) { return std::pow(a, b); }

bool isOperator(const std::string &op) { return operators.contains(op); }

bool isAdditionOrSubtraction(const std::string &op) {
  return op == "+" || op == "-";
}

bool isMultiplicationOrDivision(const std::string &op) {
  return op == "*" || op == "/" || op == "^";
}

double evaluate(std::vector<double> &numbers,
                std::vector<std::string> &operators) {
  if (numbers.empty())
    return 0;

  std::string op{};
  double operand1{};
  double operand2{};
  double result{0};
  std::vector<double> tempNumbers{};
  std::vector<std::string> tempOperators{};

  while (!numbers.empty() && !operators.empty()) {
    /*std::cout << "\nTemp Numbers\n";
    for (int i{0}; i < tempNumbers.size(); i++) {
      std::cout << tempNumbers[i] << "\n";
    }

    std::cout << "\nTemp Operators\n";
    for (int i{0}; i < tempOperators.size(); i++) {
      std::cout << tempOperators[i] << "\n";
    }

    std::cout << "\nNumbers\n";
    for (int i{0}; i < numbers.size(); i++) {
      std::cout << numbers[i] << "\n";
    }

    std::cout << "\nOperators\n";
    for (int i{0}; i < operators.size(); i++) {
      std::cout << operators[i] << "\n";
    }*/

    operand1 = 0;

    if (!numbers.empty()) {
      operand1 = numbers.back();
      numbers.pop_back();
    }

    op = operators.back();
    operators.pop_back();

    if (!trigonometricFunctions.contains(op) && !operators.empty() &&
        trigonometricFunctions.contains(operators.back())) {
      tempNumbers.push_back(operand1);
      tempOperators.push_back(op);
      continue;
    }

    // Still working on functions and nested functions
    if (trigonometricFunctions.contains(op) && !operators.empty() &&
        (operators.back() == "(" ||
         trigonometricFunctions.contains(operators.back()))) {
      numbers.push_back(operand1);
      tempOperators.push_back(op);

      while (!operators.empty() && operators.back() == "(") {
        operators.pop_back();
      }

      while (!operators.empty() &&
             trigonometricFunctions.contains(operators.back())) {
        tempOperators.push_back(operators.back());
        operators.pop_back();

        while (!operators.empty() && operators.back() == "(") {
          operators.pop_back();
        }
      }

      continue;
    }

    /*if (!operators.empty() &&
    trigonometricFunctions.contains(operators.back())) {
      tempNumbers.push_back(operand1);
      tempOperators.push_back(op);

      continue;
    }

    if (trigonometricFunctions.contains(op) && (!operators.empty() &&
    operators.back() == "(")) { numbers.push_back(operand1);
      tempOperators.push_back(op);
      continue;
    }*/
    // Still working on functions and nested functions

    if (op == "^" && (!operators.empty() && operators.back() == "(")) {
      tempNumbers.push_back(operand1);
      tempOperators.push_back(op);
      continue;
    }

    if (!operators.empty() &&
        ((op != "(" && operators.back() == "(") ||
         (isAdditionOrSubtraction(op) &&
          isMultiplicationOrDivision(operators.back())))) {
      tempNumbers.push_back(operand1);
      tempOperators.push_back(op);
      continue;
    }

    while (
        !operators.empty() &&
        operators.back() ==
            "(") { // Advance to the innermost expression in nested parentheses
      operators.pop_back();
    }

    operand2 = 0;

    if (!numbers.empty()) {
      operand2 = numbers.back();
      numbers.pop_back();
    }

    if (trigonometricFunctions.contains(op)) {
      numbers.push_back(operand2);

      result = trigonometricFunctions.at(op)(operand1);

      while (!tempOperators.empty() &&
             trigonometricFunctions.contains(
                 tempOperators.back())) { // Handle nested function
        result = trigonometricFunctions.at(tempOperators.back())(result);
        tempOperators.pop_back();
      }

      numbers.push_back(result);
      result = 0;

      continue;
    } else if (op == "(") {
      if (result != 0)
        tempNumbers.push_back(result);

      if (operand2 != 0)
        numbers.push_back(operand2);

      if (operand1 != 0)
        numbers.push_back(operand1);

      continue;
    } else if (op == ")") {
      // if (operand2 != 0)
        numbers.push_back(operand2);

      // if (operand1 != 0)
        numbers.push_back(operand1);

      if (!tempOperators.empty()) {
        operators.push_back(tempOperators.back());
        tempOperators.pop_back();
      }

      if (!tempNumbers.empty() &&
          (operators.empty() ||
           !trigonometricFunctions.contains(operators.back()))) {
        numbers.push_back(tempNumbers.back());
        tempNumbers.pop_back();
      }

      /*if (operators.empty()) {
        while (!tempNumbers.empty()) {
          numbers.push_back(tempNumbers.back());
          tempNumbers.pop_back();
        }
      }*/

      continue;
    } else if (op == "+") {
      result = add(operand1, operand2);
    } else if (op == "-") {
      result = subtract(operand1, operand2);
    } else if (op == "*") {
      result = multiply(operand1, operand2);
    } else if (op == "/") {
      result = divide(operand1, operand2);
    } else if (op == "^") {
      result = power(operand1, operand2);
    } else {
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