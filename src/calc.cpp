#include <algorithm>
#include <iostream>
#include <readline/history.h>
#include <readline/readline.h>
#include <vector>

#include "library/calculator_functions.h"
#include "parsers/calculator_parser.h"

int main(int arg, char **argv) {
  std::vector<double> numbers{};
  std::vector<std::string> operators{};
  std::string expression{};
  double result{};

  if (arg < 2) {
    read_history(".calc_history");

    while (true) {
      char *input = readline("calqi> ");

      if (!input) { // Ctrl+D pressed
        std::cout << "\n";
        break;
      }

      expression = input;
      free(input);

      if (expression == "exit" || expression == "quit" || expression == "q") {
        write_history(".calc_history");
        break;
      }

      if (expression.empty())
        continue;

      numbers.clear();
      operators.clear();

      parseExpression(expression, numbers, operators);
      result = evaluate(numbers, operators);

      add_history(expression.c_str());

      std::cout << "\nAnswer: " << result << "\n";
    }

    write_history(".calc_history");
  } else {
    expression = argv[1];
    parseExpression(expression, numbers, operators);
    result = evaluate(numbers, operators);

    std::cout << "\nAnswer: " << result << "\n";
  }

  return 0;
}
