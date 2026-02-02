#include <algorithm>
#include <iostream>
#include <vector>

int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int divide(int a, int b) {
  if (b == 0) {
    std::cerr << "Error: Division by zero\n";
    return 0; // or handle error appropriately
  }
  return a / b;
}

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

    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' ||
        ch == ')') {
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

bool isAdditionOrSubtraction(char op) { return op == '+' || op == '-'; }

bool isMultiplicationOrDivision(char op) { return op == '*' || op == '/'; }

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

    while (!operators.empty() && operators.back() == '(') {
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

#ifndef TESTING
int main() {
  std::vector<int> numbers{};
  std::vector<char> operators{};
  std::string expression = "2((10)/(((2))))";

  parseExpression(expression, numbers, operators);

  int result = evaluate(numbers, operators);

  std::cout << "\nResult: " << result << "\n";

  return 0;
}
#endif