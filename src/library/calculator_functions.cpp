
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#include "../library/math_functions.h"
#include "../utilities/function_error_messages.h"
#include "../utilities/function_validator.h"
#include "../utilities/operator_list.h"
#include "calculator_functions.h"

namespace calqi {

double add(const double &a, const double &b) { return a + b; }

double subtract(const double &a, const double &b) { return a - b; }

double multiply(const double &a, const double &b) { return a * b; }

double modulo(const double &a, const double &b) { return (int)a % (int)b; }

double divide(const double &a, const double &b) {
  if (b == 0) {
    throw std::invalid_argument("Division by zero");
    std::cerr << "Error: Division by zero\n";
    return 0; // or handle error appropriately
  }

  return a / b;
}

double abs(const double &a) { return std::abs(a); }

bool isOperator(const std::string &op) { return calqi::operators.contains(op); }

bool isAdditionOrSubtraction(const std::string &op) {
  return op == "+" || op == "-";
}

bool isMultiplicationOrDivision(const std::string &op) {
  return op == "*" || op == "/" || op == "%" || op == "^";
}

double evaluate(std::vector<double> &numbers,
                std::vector<std::string> &operators) {
  if (numbers.empty())
    return 0;

  std::string op{};
  double operand1{};
  double operand2{};
  double result{0};
  bool operand1_set{false};
  bool operand2_set{false};
  std::vector<double> temp_numbers{};
  std::vector<std::string> temp_operators{};

  while (!numbers.empty() && !operators.empty()) {
    /*std::cout << "\nTemp Numbers\n";
    for (int i{0}; i < temp_numbers.size(); i++) {
      std::cout << temp_numbers[i] << "\n";
    }

    std::cout << "\nTemp Operators\n";
    for (int i{0}; i < temp_operators.size(); i++) {
      std::cout << temp_operators[i] << "\n";
    }

    std::cout << "\nNumbers\n";
    for (int i{0}; i < numbers.size(); i++) {
      std::cout << numbers[i] << "\n";
    }

    std::cout << "\nOperators\n";
    for (int i{0}; i < operators.size(); i++) {
      std::cout << operators[i] << "\n";
    }*/

    operand1_set = false;
    operand2_set = false;
    operand1 = 0;

    if (!numbers.empty()) {
      operand1 = numbers.back();
      numbers.pop_back();
      operand1_set = true;
    }

    // Advance to the innermost expression to process nested parenthesis
    while (!operators.empty() && operators.back() == "(") {
      operators.pop_back();
    }

    op = operators.back();
    operators.pop_back();

    if (!calqi::math_functions.contains(op) && !operators.empty() &&
        calqi::math_functions.contains(operators.back())) {
      temp_numbers.push_back(operand1);
      temp_operators.push_back(op);
      continue;
    }

    if (!operators.empty() && operators.back() == "^" &&
        (isAdditionOrSubtraction(op) || isMultiplicationOrDivision(op))) {
      temp_numbers.push_back(operand1);
      temp_operators.push_back(op);
      continue;
    }

    // Processes functions and nested function calls
    if (calqi::math_functions.contains(op) && !operators.empty() &&
        (operators.back() == "(" ||
         calqi::math_functions.contains(operators.back()))) {
      numbers.push_back(operand1);
      temp_operators.push_back(op);

      while (!operators.empty() &&
             operators.back() == "(") { // Advance to the innermost expression
                                        // to process nested parenthesis
        operators.pop_back();
      }

      while (!operators.empty() &&
             calqi::math_functions.contains(operators.back())) {
        temp_operators.push_back(operators.back());
        operators.pop_back();

        while (!operators.empty() &&
               operators.back() == "(") { // Advance to the innermost expression
                                          // to process nested parenthesis
          operators.pop_back();
        }
      }

      continue;
    }

    if (op == "^" && (!operators.empty() && operators.back() == "(")) {
      temp_numbers.push_back(operand1);
      temp_operators.push_back(op);
      continue;
    }

    if (!operators.empty() &&
        ((op != "(" && operators.back() == "(") ||
         (isAdditionOrSubtraction(op) &&
          isMultiplicationOrDivision(operators.back())))) {
      temp_numbers.push_back(operand1);
      temp_operators.push_back(op);
      continue;
    }

    while (!operators.empty() &&
           operators.back() == "(") { // Advance to the innermost expression to
                                      // process nested parenthesis
      operators.pop_back();
    }

    operand2 = 0;

    if (!numbers.empty()) {
      operand2 = numbers.back();
      numbers.pop_back();
      operand2_set = true;
    }

    if (calqi::math_functions.contains(op)) {
      numbers.push_back(operand2);

      if (calqi::valid_function_value.contains(op)) {
        if (!calqi::valid_function_value.at(op)(operand1)) {
          throw std::invalid_argument(calqi::function_error_messages.at(op));
        }
      }

      result = calqi::math_functions.at(op)(operand1);

      while (!temp_operators.empty() &&
             calqi::math_functions.contains(
                 temp_operators.back())) { // Handle nested function
        result = calqi::math_functions.at(temp_operators.back())(result);
        temp_operators.pop_back();
      }

      numbers.push_back(result);
      result = 0;

      // Restore all pending numbers and operators from temp stacks
      while (!temp_numbers.empty()) {
        numbers.push_back(temp_numbers.back());
        temp_numbers.pop_back();
      }

      while (!temp_operators.empty()) {
        operators.push_back(temp_operators.back());
        temp_operators.pop_back();
      }

      continue;
    } else if (op == "(") {
      if (result != 0)
        temp_numbers.push_back(result);

      if (operand2 != 0)
        numbers.push_back(operand2);

      if (operand1 != 0)
        numbers.push_back(operand1);

      continue;
    } else if (op == ")") {
      if (operand2_set)
        numbers.push_back(operand2);

      if (operand1_set)
        numbers.push_back(operand1);

      if (!temp_operators.empty()) {
        operators.push_back(temp_operators.back());
        temp_operators.pop_back();
      }

      if (!temp_numbers.empty() &&
          (operators.empty() ||
           !calqi::math_functions.contains(operators.back()))) {
        numbers.push_back(temp_numbers.back());
        temp_numbers.pop_back();
      }

      continue;
    } else if (op == "+") {
      result = add(operand1, operand2);
    } else if (op == "-") {
      result = subtract(operand1, operand2);
    } else if (op == "*") {
      result = multiply(operand1, operand2);
    } else if (op == "/") {
      result = divide(operand1, operand2);
    } else if (op == "%") {
      result = modulo(operand1, operand2);
    } else if (op == "^") {
      result = std::pow(operand1, operand2);
    } else {
      std::cerr << "Error: Unknown operator " << op << "\n";
      return 0;
    }

    numbers.push_back(result);
    result = 0;

    while (!temp_numbers.empty()) {
      numbers.push_back(temp_numbers.back());
      temp_numbers.pop_back();
    }

    while (!temp_operators.empty()) {
      operators.push_back(temp_operators.back());
      temp_operators.pop_back();
    }
  }

  if (!numbers.empty()) {
    result = numbers.back();
    numbers.pop_back();
  }

  return result;
}

} // namespace calqi