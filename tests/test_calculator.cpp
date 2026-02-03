#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "../parsers/calculator_parser.h"
#include "../library/calculator_functions.h"

void test_evaluate_empty_vectors() {
  // Expression: (empty)
  std::vector<int> numbers;
  std::vector<char> operators;
  int result = evaluate(numbers, operators);
  assert(result == 0);
  std::cout << "✓ test_evaluate_empty_vectors passed\n";
}

void test_evaluate_single_addition() {
  // Expression: 5+3
  std::vector<int> numbers{5, 3};
  std::vector<char> operators{'+'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  std::cout << "Result: " << result << "\n";
  assert(result == 8);
  std::cout << "✓ test_evaluate_single_addition passed\n";
}

void test_evaluate_single_subtraction() {
  // Expression: 10-4
  std::vector<int> numbers{10, 4};
  std::vector<char> operators{'-'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 6);
  std::cout << "✓ test_evaluate_single_subtraction passed\n";
}

void test_evaluate_single_multiplication() {
  // Expression: 6*7
  std::vector<int> numbers{6, 7};
  std::vector<char> operators{'*'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 42);
  std::cout << "✓ test_evaluate_single_multiplication passed\n";
}

void test_evaluate_single_division() {
  // Expression: 20/4
  std::vector<int> numbers{20, 4};
  std::vector<char> operators{'/'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 5);
  std::cout << "✓ test_evaluate_single_division passed\n";
}

void test_evaluate_multiple_additions() {
  // Expression: 1+2+3+4
  std::vector<int> numbers{1, 2, 3, 4};
  std::vector<char> operators{'+', '+', '+'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 10);
  std::cout << "✓ test_evaluate_multiple_additions passed\n";
}

void test_evaluate_multiple_subtractions() {
  // Expression: 20-5-3
  std::vector<int> numbers{20, 5, 3};
  std::vector<char> operators{'-', '-'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 12);
  std::cout << "✓ test_evaluate_multiple_subtractions passed\n";
}

void test_evaluate_multiplication_precedence() {
  // Expression: 2+3*4
  std::vector<int> numbers{2, 3, 4};
  std::vector<char> operators{'+', '*'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 14);
  std::cout << "✓ test_evaluate_multiplication_precedence passed\n";
}

void test_evaluate_division_precedence() {
  // Expression: 10+20/4
  std::vector<int> numbers{10, 20, 4};
  std::vector<char> operators{'+', '/'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 15);
  std::cout << "✓ test_evaluate_division_precedence passed\n";
}

void test_evaluate_mixed_operations() {
  // Expression: 12+34-5*6/2
  std::vector<int> numbers{12, 34, 5, 6, 2};
  std::vector<char> operators{'+', '-', '*', '/'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 31);
  std::cout << "✓ test_evaluate_mixed_operations passed\n";
}

void test_evaluate_consecutive_multiplications() {
  // Expression: 2*3*4
  std::vector<int> numbers{2, 3, 4};
  std::vector<char> operators{'*', '*'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 24);
  std::cout << "✓ test_evaluate_consecutive_multiplications passed\n";
}

void test_evaluate_consecutive_divisions() {
  // Expression: 8/4/2
  std::vector<int> numbers{8, 4, 2};
  std::vector<char> operators{'/', '/'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 1);
  std::cout << "✓ test_evaluate_consecutive_divisions passed\n";
}

void test_evaluate_subtraction_with_multiplication() {
  // Expression: 10-2*3
  std::vector<int> numbers{10, 2, 3};
  std::vector<char> operators{'-', '*'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 4);
  std::cout << "✓ test_evaluate_subtraction_with_multiplication passed\n";
}

void test_evaluate_complex_expression() {
  // Expression: 5+3*2-4/1
  std::vector<int> numbers{5, 3, 2, 4, 1};
  std::vector<char> operators{'+', '*', '-', '/'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 7);
  std::cout << "✓ test_evaluate_complex_expression passed\n";
}

void test_evaluate_division_by_zero() {
  // Expression: 10/0
  std::vector<int> numbers{10, 0};
  std::vector<char> operators{'/'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 0);
  std::cout << "✓ test_evaluate_division_by_zero passed\n";
}

void test_evaluate_with_zeros() {
  // Expression: 0+5*0
  std::vector<int> numbers{0, 5, 0};
  std::vector<char> operators{'+', '*'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 0);
  std::cout << "✓ test_evaluate_with_zeros passed\n";
}

void test_evaluate_large_numbers() {
  // Expression: 1000+500*2
  std::vector<int> numbers{1000, 500, 2};
  std::vector<char> operators{'+', '*'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 2000);
  std::cout << "✓ test_evaluate_large_numbers passed\n";
}

void test_evaluate_with_opening_parenthesis() {
  // Expression: (2+3) - testing opening parenthesis
  std::vector<int> numbers{2, 3};
  std::vector<char> operators{'(', '+', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 5);
  std::cout << "✓ test_evaluate_with_opening_parenthesis passed (result: "
            << result << ")\n";
}

// void test_evaluate_with_closing_parenthesis() {
//   // Expression: )5+3 - testing closing parenthesis at start
//   std::vector<int> numbers{5, 3};
//   std::vector<char> operators{')', '+'};
//   int result = evaluate(numbers, operators);
//   std::cout << "✓ test_evaluate_with_closing_parenthesis passed (result: " <<
//   result << ")\n";
// }

void test_evaluate_parenthesis_simple_addition() {
  // Expression: (2+3)
  std::vector<int> numbers{2, 3};
  std::vector<char> operators{'(', '+', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 5);
  std::cout << "✓ test_evaluate_parenthesis_simple_addition passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_with_multiplication() {
  // Expression: (2+3)*4
  std::vector<int> numbers{2, 3, 4};
  std::vector<char> operators{'(', '+', ')', '*'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 20);
  std::cout
      << "✓ test_evaluate_parenthesis_with_multiplication passed (result: "
      << result << ")\n";
}

void test_evaluate_nested_parenthesis() {
  // Expression: ((2+3)*4)
  std::vector<int> numbers{2, 3, 4};
  std::vector<char> operators{'(', '(', '+', ')', '*', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 20);
  std::cout << "✓ test_evaluate_nested_parenthesis passed (result: " << result
            << ")\n";
}

void test_evaluate_multiple_parenthesis_groups() {
  // Expression: (2+3)*(4+5)
  std::vector<int> numbers{2, 3, 4, 5};
  std::vector<char> operators{'(', '+', ')', '*', '(', '+', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 45);
  std::cout << "✓ test_evaluate_multiple_parenthesis_groups passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_at_end() {
  // Expression: 2*(3+4)
  std::vector<int> numbers{2, 3, 4};
  std::vector<char> operators{'*', '(', '+', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 14);
  std::cout << "✓ test_evaluate_parenthesis_at_end passed (result: " << result
            << ")\n";
}

void test_evaluate_parenthesis_with_subtraction() {
  // Expression: (10-3)*2
  std::vector<int> numbers{10, 3, 2};
  std::vector<char> operators{'(', '-', ')', '*'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 14);
  std::cout << "✓ test_evaluate_parenthesis_with_subtraction passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_with_division() {
  // Expression: (20/4)+3
  std::vector<int> numbers{20, 4, 3};
  std::vector<char> operators{'(', '/', ')', '+'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 8);
  std::cout << "✓ test_evaluate_parenthesis_with_division passed (result: "
            << result << ")\n";
}

void test_evaluate_deeply_nested_parenthesis() {
  // Expression: (((2+3)*4)-5)
  std::vector<int> numbers{2, 3, 4, 5};
  std::vector<char> operators{'(', '(', '(', '+', ')', '*', ')', '-', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 15);
  std::cout << "✓ test_evaluate_deeply_nested_parenthesis passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_mixed_precedence() {
  // Expression: 2+3*(4+5)
  std::vector<int> numbers{2, 3, 4, 5};
  std::vector<char> operators{'+', '*', '(', '+', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 29);
  std::cout << "✓ test_evaluate_parenthesis_mixed_precedence passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_complex_nested() {
  // Expression: ((2+3)*(4-1))/5
  std::vector<int> numbers{2, 3, 4, 1, 5};
  std::vector<char> operators{'(', '(', '+', ')', '*', '(', '-', ')', ')', '/'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 3);
  std::cout << "✓ test_evaluate_parenthesis_complex_nested passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_single_number() {
  // Expression: (5)
  std::vector<int> numbers{5};
  std::vector<char> operators{'(', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 5);
  std::cout << "✓ test_evaluate_parenthesis_single_number passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_consecutive_groups() {
  // Expression: (2+3)+(4*5)
  std::vector<int> numbers{2, 3, 4, 5};
  std::vector<char> operators{'(', '+', ')', '+', '(', '*', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 25);
  std::cout << "✓ test_evaluate_parenthesis_consecutive_groups passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_subtraction_division() {
  // Expression: (10-2)/(4-2)
  std::vector<int> numbers{10, 2, 4, 2};
  std::vector<char> operators{'(', '-', ')', '/', '(', '-', ')'};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  int result = evaluate(numbers, operators);
  assert(result == 4);
  std::cout
      << "✓ test_evaluate_parenthesis_subtraction_division passed (result: "
      << result << ")\n";
}

int main() {
  std::cout << "Running unit tests for evaluate function...\n\n";

  test_evaluate_empty_vectors();
  test_evaluate_single_addition();
  test_evaluate_single_subtraction();
  test_evaluate_single_multiplication();
  test_evaluate_single_division();
  test_evaluate_multiple_additions();
  test_evaluate_multiple_subtractions();
  test_evaluate_multiplication_precedence();
  test_evaluate_division_precedence();
  test_evaluate_mixed_operations();
  test_evaluate_consecutive_multiplications();
  test_evaluate_consecutive_divisions();
  test_evaluate_subtraction_with_multiplication();
  test_evaluate_complex_expression();
  test_evaluate_division_by_zero();
  test_evaluate_with_zeros();
  test_evaluate_large_numbers();

  std::cout << "\n--- Parenthesis Tests ---\n";
  test_evaluate_with_opening_parenthesis();
  //   test_evaluate_with_closing_parenthesis();
  test_evaluate_parenthesis_simple_addition();
  test_evaluate_parenthesis_with_multiplication();
  test_evaluate_nested_parenthesis();
  test_evaluate_multiple_parenthesis_groups();
  test_evaluate_parenthesis_at_end();
  test_evaluate_parenthesis_with_subtraction();
  test_evaluate_parenthesis_with_division();
  test_evaluate_deeply_nested_parenthesis();
  test_evaluate_parenthesis_mixed_precedence();
  test_evaluate_parenthesis_complex_nested();
  test_evaluate_parenthesis_single_number();
  test_evaluate_parenthesis_consecutive_groups();
  test_evaluate_parenthesis_subtraction_division();

  std::cout << "\n✅ All tests completed!\n";
  return 0;
}
