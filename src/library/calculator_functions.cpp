
#include <cmath>
#include <stdexcept>
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
  const double EPSILON = 1e-10;
  if (std::abs(b) < EPSILON) { // Checks if b is close enough to 0
    throw std::invalid_argument("Division by zero");
  }

  return a / b;
}

double abs(const double &a) { return std::abs(a); }

bool isOperator(const std::string &op) { return calqi::operators.contains(op); }

double evaluate(std::vector<double> &numbers,
                std::vector<std::string> &operators) {
  if (numbers.empty())
    return 0;

  std::vector<double> values{};
  std::vector<std::string> op_stack{};

  auto precedence = [](const std::string &op) {
    if (op == "+" || op == "-")
      return 1;
    if (op == "*" || op == "/" || op == "%")
      return 2;
    if (op == "^")
      return 3;
    return 0;
  };

  auto isBinaryOperator = [](const std::string &op) {
    return op == "+" || op == "-" || op == "*" || op == "/" || op == "%" ||
           op == "^";
  };

  auto apply_operator = [&](const std::string &op) {
    if (calqi::math_functions.contains(op)) {
      if (values.empty())
        throw std::runtime_error("Invalid expression.");

      double operand = values.back();
      values.pop_back();

      if (calqi::valid_function_value.contains(op) &&
          !calqi::valid_function_value.at(op)(operand)) {
        throw std::invalid_argument(calqi::function_error_messages.at(op));
      }

      values.push_back(calqi::math_functions.at(op)(operand));
      return;
    }

    if (values.size() < 2)
      throw std::runtime_error("Invalid expression.");

    double right = values.back();
    values.pop_back();
    double left = values.back();
    values.pop_back();

    if (op == "+")
      values.push_back(add(left, right));
    else if (op == "-")
      values.push_back(subtract(left, right));
    else if (op == "*")
      values.push_back(multiply(left, right));
    else if (op == "/")
      values.push_back(divide(left, right));
    else if (op == "%")
      values.push_back(modulo(left, right));
    else if (op == "^")
      values.push_back(std::pow(left, right));
    else
      throw std::runtime_error("Unknown operator.");
  };

  std::size_t number_index{0};
  std::size_t operator_index{0};
  bool expect_value{true};

  while (number_index < numbers.size() || operator_index < operators.size()) {
    if (expect_value) {
      if (operator_index < operators.size() &&
          (operators[operator_index] == "(" ||
           calqi::math_functions.contains(operators[operator_index]))) {
        op_stack.push_back(operators[operator_index]);
        operator_index++;
        continue;
      }

      if (number_index >= numbers.size())
        throw std::runtime_error("Invalid expression.");

      values.push_back(numbers[number_index]);
      number_index++;

      while (!op_stack.empty() &&
             calqi::math_functions.contains(op_stack.back()) &&
             (op_stack.size() == 1 || op_stack[op_stack.size() - 2] != "(")) {
        apply_operator(op_stack.back());
        op_stack.pop_back();
      }

      expect_value = false;
      continue;
    }

    if (operator_index >= operators.size())
      break;

    const std::string &op = operators[operator_index];

    if (op == ")") {
      while (!op_stack.empty() && op_stack.back() != "(") {
        apply_operator(op_stack.back());
        op_stack.pop_back();
      }

      if (op_stack.empty() || op_stack.back() != "(")
        throw std::runtime_error("Parenthesis mismatch.");

      op_stack.pop_back();
      operator_index++;

      while (!op_stack.empty() &&
             calqi::math_functions.contains(op_stack.back())) {
        apply_operator(op_stack.back());
        op_stack.pop_back();
      }

      expect_value = false;
      continue;
    }

    if (!isBinaryOperator(op))
      throw std::runtime_error("Invalid expression.");

    while (!op_stack.empty() && isBinaryOperator(op_stack.back()) &&
           ((op != "^" && precedence(op_stack.back()) >= precedence(op)) ||
            (op == "^" && precedence(op_stack.back()) > precedence(op)))) {
      apply_operator(op_stack.back());
      op_stack.pop_back();
    }

    op_stack.push_back(op);
    operator_index++;
    expect_value = true;
  }

  if (number_index != numbers.size() || operator_index != operators.size()) {
    throw std::runtime_error("Invalid expression.");
  }

  while (!op_stack.empty()) {
    if (op_stack.back() == "(")
      throw std::runtime_error("Parenthesis mismatch.");

    apply_operator(op_stack.back());
    op_stack.pop_back();
  }

  if (values.size() != 1)
    throw std::runtime_error("Invalid expression.");

  return values.back();
}

} // namespace calqi
