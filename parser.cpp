#include <deque>
#include <iostream>
#include <stack>

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

void parseExpression(const std::string &expression, std::deque<int> &numbers,
                     std::deque<char> &operators) {
  std::string number{};

  for (const char &ch : expression) {
    if (isdigit(ch)) {
      number += ch;
      continue;
    }

    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' ||
        ch == ')') {
      if (!number.empty()) {
        numbers.push_back(std::stoi(number));
        number.clear();
      }

      operators.push_back(ch);
    }
  }

  if (!number.empty())
    numbers.push_back(std::stoi(number));
}

bool isAdditionOrSubtraction(char op) { return op == '+' || op == '-'; }

bool isMultiplicationOrDivision(char op) { return op == '*' || op == '/'; }

bool isSubtractionOrDivision(char op) { return op == '-' || op == '/'; }

int evaluate(std::deque<int> &numbers, std::deque<char> &operators) {
  if (numbers.empty())
    return 0;

  char op{};
  int operand1{};
  int operand2{};
  int result{0};
  std::stack<int> tempNumbers{};
  std::stack<char> tempOperators{};

  while (!numbers.empty() && !operators.empty()) {
    operand1 = 0;
    if (!numbers.empty()) {
      operand1 = numbers.front();
      numbers.pop_front();
    }

    op = operators.front();
    operators.pop_front();

    if (!operators.empty() &&
        ((op != '(' && operators.front() == '(') ||
         (isAdditionOrSubtraction(op) &&
          isMultiplicationOrDivision(operators.front())))) {
      tempNumbers.push(operand1);
      tempOperators.push(op);
      continue;
    }

    while (!operators.empty() && operators.front() == '(') {
      operators.pop_front();
    }

    operand2 = 0;
    if (!numbers.empty()) {
      operand2 = numbers.front();
      numbers.pop_front();
    }

    switch (op) {
    case '(':
      if (result != 0)
        tempNumbers.push(result);

      if (operand2 != 0)
        numbers.push_front(operand2);

      if (operand1 != 0)
        numbers.push_front(operand1);
      continue;
    case ')':
      if (operand2 != 0)
        numbers.push_front(operand2);

      if (operand1 != 0)
        numbers.push_front(operand1);

      if (!tempNumbers.empty()) {
        numbers.push_front(tempNumbers.top());
        tempNumbers.pop();
      }

      if (!tempOperators.empty()) {
        operators.push_front(tempOperators.top());
        tempOperators.pop();
      }

      if (operators.empty()) {
        while(!tempNumbers.empty()) {
          numbers.push_front(tempNumbers.top());
          tempNumbers.pop();
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

    numbers.push_front(result);
    result = 0;

    while (!tempNumbers.empty()) {
      numbers.push_front(tempNumbers.top());
      tempNumbers.pop();
    }

    while (!tempOperators.empty()) {
      operators.push_front(tempOperators.top());
      tempOperators.pop();
    }
  }

  while (!numbers.empty()) {
    result = numbers.front();
    numbers.pop_front();
  }

  return result;
}

#ifndef TESTING
int main() {
  std::deque<int> numbers{};
  std::deque<char> operators{};
  std::string expression = "10-4";
  //   "12+34-5*6/2";

  parseExpression(expression, numbers, operators);

  int result = evaluate(numbers, operators);

  std::cout << "\nOperators:\n";

  while (!operators.empty()) {
    std::cout << operators.front() << "\n";
    operators.pop_front();
  }

  std::cout << "\nResult: " << result << "\n";

  return 0;
}
#endif