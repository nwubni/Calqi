#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "../src/library/calculator_functions.h"
#include "../src/parsers/calculator_parser.h"

void test_evaluate_empty_vectors() {
  // Expression: (empty)
  std::vector<double> numbers;
  std::vector<std::string> operators;
  double result = calqi::evaluate(numbers, operators);
  assert(result == 0);
  std::cout << "✓ test_evaluate_empty_vectors passed\n";
}

void test_evaluate_single_addition() {
  // Expression: 5+3
  std::vector<double> numbers{5, 3};
  std::vector<std::string> operators{"+"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  std::cout << "Result: " << result << "\n";
  assert(result == 8);
  std::cout << "✓ test_evaluate_single_addition passed\n";
}

void test_evaluate_single_subtraction() {
  // Expression: 10-4
  std::vector<double> numbers{10, 4};
  std::vector<std::string> operators{"-"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 6);
  std::cout << "✓ test_evaluate_single_subtraction passed\n";
}

void test_evaluate_single_multiplication() {
  // Expression: 6*7
  std::vector<double> numbers{6, 7};
  std::vector<std::string> operators{"*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 42);
  std::cout << "✓ test_evaluate_single_multiplication passed\n";
}

void test_evaluate_single_division() {
  // Expression: 20/4
  std::vector<double> numbers{20, 4};
  std::vector<std::string> operators{"/"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 5);
  std::cout << "✓ test_evaluate_single_division passed\n";
}

void test_evaluate_multiple_additions() {
  // Expression: 1+2+3+4
  std::vector<double> numbers{1, 2, 3, 4};
  std::vector<std::string> operators{"+", "+", "+"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 10);
  std::cout << "✓ test_evaluate_multiple_additions passed\n";
}

void test_evaluate_multiple_subtractions() {
  // Expression: 20-5-3
  std::vector<double> numbers{20, 5, 3};
  std::vector<std::string> operators{"-", "-"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 12);
  std::cout << "✓ test_evaluate_multiple_subtractions passed\n";
}

void test_evaluate_multiplication_precedence() {
  // Expression: 2+3*4
  std::vector<double> numbers{2, 3, 4};
  std::vector<std::string> operators{"+", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 14);
  std::cout << "✓ test_evaluate_multiplication_precedence passed\n";
}

void test_evaluate_division_precedence() {
  // Expression: 10+20/4
  std::vector<double> numbers{10, 20, 4};
  std::vector<std::string> operators{"+", "/"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 15);
  std::cout << "✓ test_evaluate_division_precedence passed\n";
}

void test_evaluate_mixed_operations() {
  // Expression: 12+34-5*6/2
  std::vector<double> numbers{12, 34, 5, 6, 2};
  std::vector<std::string> operators{"+", "-", "*", "/"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 31);
  std::cout << "✓ test_evaluate_mixed_operations passed\n";
}

void test_evaluate_consecutive_multiplications() {
  // Expression: 2*3*4
  std::vector<double> numbers{2, 3, 4};
  std::vector<std::string> operators{"*", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 24);
  std::cout << "✓ test_evaluate_consecutive_multiplications passed\n";
}

void test_evaluate_consecutive_divisions() {
  // Expression: 8/4/2
  std::vector<double> numbers{8, 4, 2};
  std::vector<std::string> operators{"/", "/"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 1);
  std::cout << "✓ test_evaluate_consecutive_divisions passed\n";
}

void test_evaluate_subtraction_with_multiplication() {
  // Expression: 10-2*3
  std::vector<double> numbers{10, 2, 3};
  std::vector<std::string> operators{"-", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 4);
  std::cout << "✓ test_evaluate_subtraction_with_multiplication passed\n";
}

void test_evaluate_complex_expression() {
  // Expression: 5+3*2-4/1
  std::vector<double> numbers{5, 3, 2, 4, 1};
  std::vector<std::string> operators{"+", "*", "-", "/"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 7);
  std::cout << "✓ test_evaluate_complex_expression passed\n";
}

void test_evaluate_division_by_zero() {
  // Expression: 10/0
  std::vector<double> numbers{10, 0};
  std::vector<std::string> operators{"/"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  bool exception_thrown = false;
  try {
    double result = calqi::evaluate(numbers, operators);
  } catch (const std::invalid_argument &e) {
    exception_thrown = true;
  }
  assert(exception_thrown);
  std::cout << "✓ test_evaluate_division_by_zero passed\n";
}

void test_evaluate_with_zeros() {
  // Expression: 0+5*0
  std::vector<double> numbers{0, 5, 0};
  std::vector<std::string> operators{"+", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 0);
  std::cout << "✓ test_evaluate_with_zeros passed\n";
}

void test_evaluate_large_numbers() {
  // Expression: 1000+500*2
  std::vector<double> numbers{1000, 500, 2};
  std::vector<std::string> operators{"+", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 2000);
  std::cout << "✓ test_evaluate_large_numbers passed\n";
}

void test_evaluate_with_opening_parenthesis() {
  // Expression: (2+3) - testing opening parenthesis
  std::vector<double> numbers{2, 3};
  std::vector<std::string> operators{"(", "+", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 5);
  std::cout << "✓ test_evaluate_with_opening_parenthesis passed (result: "
            << result << ")\n";
}

// void test_evaluate_with_closing_parenthesis() {
//   // Expression: )5+3 - testing closing parenthesis at start
//   std::vector<double> numbers{5, 3};
//   std::vector<std::string> operators{")", "+"};
//   double result = evaluate(numbers, operators);
//   std::cout << "✓ test_evaluate_with_closing_parenthesis passed (result: " <<
//   result << ")\n";
// }

void test_evaluate_parenthesis_simple_addition() {
  // Expression: (2+3)
  std::vector<double> numbers{2, 3};
  std::vector<std::string> operators{"(", "+", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 5);
  std::cout << "✓ test_evaluate_parenthesis_simple_addition passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_with_multiplication() {
  // Expression: (2+3)*4
  std::vector<double> numbers{2, 3, 4};
  std::vector<std::string> operators{"(", "+", ")", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 20);
  std::cout
      << "✓ test_evaluate_parenthesis_with_multiplication passed (result: "
      << result << ")\n";
}

void test_evaluate_nested_parenthesis() {
  // Expression: ((2+3)*4)
  std::vector<double> numbers{2, 3, 4};
  std::vector<std::string> operators{"(", "(", "+", ")", "*", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 20);
  std::cout << "✓ test_evaluate_nested_parenthesis passed (result: " << result
            << ")\n";
}

void test_evaluate_multiple_parenthesis_groups() {
  // Expression: (2+3)*(4+5)
  std::vector<double> numbers{2, 3, 4, 5};
  std::vector<std::string> operators{"(", "+", ")", "*", "(", "+", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 45);
  std::cout << "✓ test_evaluate_multiple_parenthesis_groups passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_at_end() {
  // Expression: 2*(3+4)
  std::vector<double> numbers{2, 3, 4};
  std::vector<std::string> operators{"*", "(", "+", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 14);
  std::cout << "✓ test_evaluate_parenthesis_at_end passed (result: " << result
            << ")\n";
}

void test_evaluate_parenthesis_with_subtraction() {
  // Expression: (10-3)*2
  std::vector<double> numbers{10, 3, 2};
  std::vector<std::string> operators{"(", "-", ")", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 14);
  std::cout << "✓ test_evaluate_parenthesis_with_subtraction passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_with_division() {
  // Expression: (20/4)+3
  std::vector<double> numbers{20, 4, 3};
  std::vector<std::string> operators{"(", "/", ")", "+"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 8);
  std::cout << "✓ test_evaluate_parenthesis_with_division passed (result: "
            << result << ")\n";
}

void test_evaluate_deeply_nested_parenthesis() {
  // Expression: (((2+3)*4)-5)
  std::vector<double> numbers{2, 3, 4, 5};
  std::vector<std::string> operators{"(", "(", "(", "+", ")",
                                     "*", ")", "-", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 15);
  std::cout << "✓ test_evaluate_deeply_nested_parenthesis passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_mixed_precedence() {
  // Expression: 2+3*(4+5)
  std::vector<double> numbers{2, 3, 4, 5};
  std::vector<std::string> operators{"+", "*", "(", "+", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 29);
  std::cout << "✓ test_evaluate_parenthesis_mixed_precedence passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_complex_nested() {
  // Expression: ((2+3)*(4-1))/5
  std::vector<double> numbers{2, 3, 4, 1, 5};
  std::vector<std::string> operators{"(", "(", "+", ")", "*",
                                     "(", "-", ")", ")", "/"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 3);
  std::cout << "✓ test_evaluate_parenthesis_complex_nested passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_single_number() {
  // Expression: (5)
  std::vector<double> numbers{5};
  std::vector<std::string> operators{"(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 5);
  std::cout << "✓ test_evaluate_parenthesis_single_number passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_consecutive_groups() {
  // Expression: (2+3)+(4*5)
  std::vector<double> numbers{2, 3, 4, 5};
  std::vector<std::string> operators{"(", "+", ")", "+", "(", "*", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 25);
  std::cout << "✓ test_evaluate_parenthesis_consecutive_groups passed (result: "
            << result << ")\n";
}

void test_evaluate_parenthesis_subtraction_division() {
  // Expression: (10-2)/(4-2)
  std::vector<double> numbers{10, 2, 4, 2};
  std::vector<std::string> operators{"(", "-", ")", "/", "(", "-", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 4);
  std::cout
      << "✓ test_evaluate_parenthesis_subtraction_division passed (result: "
      << result << ")\n";
}

// --- Trigonometric and Logarithmic Function Tests ---

void test_evaluate_sin_function() {
  // Expression: sin(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"sin", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // sin(0) = 0
  std::cout << "✓ test_evaluate_sin_function passed (result: " << result
            << ")\n";
}

void test_evaluate_cos_function() {
  // Expression: cos(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"cos", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 0.999 && result <= 1.001); // cos(0) = 1
  std::cout << "✓ test_evaluate_cos_function passed (result: " << result
            << ")\n";
}

void test_evaluate_tan_function() {
  // Expression: tan(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"tan", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // tan(0) = 0
  std::cout << "✓ test_evaluate_tan_function passed (result: " << result
            << ")\n";
}

void test_evaluate_asin_function() {
  // Expression: asin(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"asin", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // asin(0) = 0
  std::cout << "✓ test_evaluate_asin_function passed (result: " << result
            << ")\n";
}

void test_evaluate_acos_function() {
  // Expression: acos(1)
  std::vector<double> numbers{1};
  std::vector<std::string> operators{"acos", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // acos(1) = 0
  std::cout << "✓ test_evaluate_acos_function passed (result: " << result
            << ")\n";
}

void test_evaluate_atan_function() {
  // Expression: atan(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"atan", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // atan(0) = 0
  std::cout << "✓ test_evaluate_atan_function passed (result: " << result
            << ")\n";
}

void test_evaluate_log_function() {
  // Expression: log(100) - base-10 logarithm
  std::vector<double> numbers{100};
  std::vector<std::string> operators{"log", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 1.999 && result <= 2.001); // log10(100) = 2
  std::cout << "✓ test_evaluate_log_function passed (result: " << result
            << ")\n";
}

void test_evaluate_ln_function() {
  // Expression: ln(2.718281828)
  std::vector<double> numbers{2.718281828};
  std::vector<std::string> operators{"ln", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 0.999 && result <= 1.001); // ln(e) ≈ 1
  std::cout << "✓ test_evaluate_ln_function passed (result: " << result
            << ")\n";
}

void test_evaluate_sinh_function() {
  // Expression: sinh(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"sinh", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // sinh(0) = 0
  std::cout << "✓ test_evaluate_sinh_function passed (result: " << result
            << ")\n";
}

void test_evaluate_cosh_function() {
  // Expression: cosh(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"cosh", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 0.999 && result <= 1.001); // cosh(0) = 1
  std::cout << "✓ test_evaluate_cosh_function passed (result: " << result
            << ")\n";
}

void test_evaluate_tanh_function() {
  // Expression: tanh(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"tanh", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // tanh(0) = 0
  std::cout << "✓ test_evaluate_tanh_function passed (result: " << result
            << ")\n";
}

void test_evaluate_asinh_function() {
  // Expression: asinh(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"asinh", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // asinh(0) = 0
  std::cout << "✓ test_evaluate_asinh_function passed (result: " << result
            << ")\n";
}

void test_evaluate_acosh_function() {
  // Expression: acosh(1)
  std::vector<double> numbers{1};
  std::vector<std::string> operators{"acosh", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // acosh(1) = 0
  std::cout << "✓ test_evaluate_acosh_function passed (result: " << result
            << ")\n";
}

void test_evaluate_atanh_function() {
  // Expression: atanh(0)
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"atanh", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.001 && result <= 0.001); // atanh(0) = 0
  std::cout << "✓ test_evaluate_atanh_function passed (result: " << result
            << ")\n";
}

void test_evaluate_neg_function() {
  // Expression: neg(5)
  std::vector<double> numbers{5};
  std::vector<std::string> operators{"neg", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == -5); // neg(5) = -5
  std::cout << "✓ test_evaluate_neg_function passed (result: " << result
            << ")\n";
}

void test_evaluate_neg_negative_number() {
  // Expression: neg(-3)
  std::vector<double> numbers{-3};
  std::vector<std::string> operators{"neg", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 3); // neg(-3) = 3
  std::cout << "✓ test_evaluate_neg_negative_number passed (result: " << result
            << ")\n";
}

void test_evaluate_neg_with_addition() {
  // Expression: 2+neg(5)
  std::vector<double> numbers{2, 5};
  std::vector<std::string> operators{"+", "neg", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == -3); // 2 + neg(5) = 2 + (-5) = -3
  std::cout << "✓ test_evaluate_neg_with_addition passed (result: " << result
            << ")\n";
}

void test_evaluate_neg_with_multiplication() {
  // Expression: 7*neg(3)
  std::vector<double> numbers{7, 3};
  std::vector<std::string> operators{"*", "neg", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == -21); // 7 * neg(3) = 7 * (-3) = -21
  std::cout << "✓ test_evaluate_neg_with_multiplication passed (result: "
            << result << ")\n";
}

void test_evaluate_double_negation() {
  // Expression: 8-neg(2)
  std::vector<double> numbers{8, 2};
  std::vector<std::string> operators{"-", "neg", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 10); // 8 - neg(2) = 8 - (-2) = 10
  std::cout << "✓ test_evaluate_double_negation passed (result: " << result
            << ")\n";
}

void test_evaluate_neg_in_parentheses() {
  // Expression: (neg(5))*3
  std::vector<double> numbers{5, 3};
  std::vector<std::string> operators{"(", "neg", "(", ")", ")", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == -15); // (neg(5)) * 3 = (-5) * 3 = -15
  std::cout << "✓ test_evaluate_neg_in_parentheses passed (result: " << result
            << ")\n";
}

void test_evaluate_neg_with_exponent() {
  // Expression: 2^neg(3)
  std::vector<double> numbers{2, 3};
  std::vector<std::string> operators{"^", "neg", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 0.124 && result <= 0.126); // 2^(-3) = 0.125
  std::cout << "✓ test_evaluate_neg_with_exponent passed (result: " << result
            << ")\n";
}

void test_evaluate_neg_with_function() {
  // Expression: sin(neg(1))
  std::vector<double> numbers{1};
  std::vector<std::string> operators{"sin", "(", "neg", "(", ")", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.85 && result <= -0.84); // sin(-1) ≈ -0.8414
  std::cout << "✓ test_evaluate_neg_with_function passed (result: " << result
            << ")\n";
}

void test_evaluate_function_with_addition() {
  // Expression: 1+cos(3)
  std::vector<double> numbers{1, 3};
  std::vector<std::string> operators{"+", "cos", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 0.009 && result <= 0.011); // 1 + cos(3) ≈ 0.01
  std::cout << "✓ test_evaluate_function_with_addition passed (result: "
            << result << ")\n";
}

void test_evaluate_function_with_multiplication() {
  // Expression: 2*sin(1.5708)
  std::vector<double> numbers{2, 1.5708};
  std::vector<std::string> operators{"*", "sin", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 1.99 && result <= 2.01); // 2 * sin(π/2) ≈ 2
  std::cout << "✓ test_evaluate_function_with_multiplication passed (result: "
            << result << ")\n";
}

void test_evaluate_nested_functions() {
  // Expression: cos(cos(0))
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"cos", "(", "cos", "(", ")", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 0.54 && result <= 0.55); // cos(cos(0)) = cos(1) ≈ 0.5403
  std::cout << "✓ test_evaluate_nested_functions passed (result: " << result
            << ")\n";
}

void test_evaluate_function_in_parenthesis() {
  // Expression: 2*sin(0)+1
  std::vector<double> numbers{2, 0, 1};
  std::vector<std::string> operators{"*", "sin", "(", ")", "+"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 0.99 && result <= 1.01); // 2*sin(0)+1 = 2*0+1 = 1
  std::cout << "✓ test_evaluate_function_in_parenthesis passed (result: "
            << result << ")\n";
}

void test_evaluate_function_in_nested_parenthesis() {
  // Expression (sin(0)+1)*2
  std::vector<double> numbers{0, 1, 2};
  std::vector<std::string> operators{"(", "sin", "(", ")", "+", ")", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 1.99 && result <= 2.01); // (sin(0)+1)*2 = (0+1)*2 = 2
  std::cout << "✓ test_evaluate_function_in_nested_parenthesis passed (result: "
            << result << ")\n";
}

void test_evaluate_multiple_functions() {
  // Expression: sin(0)+cos(0)
  std::vector<double> numbers{0, 0};
  std::vector<std::string> operators{"sin", "(", ")", "+", "cos", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 0.99 && result <= 1.01); // sin(0)+cos(0) = 0+1 = 1
  std::cout << "✓ test_evaluate_multiple_functions passed (result: " << result
            << ")\n";
}

void test_evaluate_log_with_operations() {
  // Expression: 10+ln(2.718281828)
  std::vector<double> numbers{10, 2.718281828};
  std::vector<std::string> operators{"+", "ln", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 10.99 && result <= 11.01); // 10 + ln(e) ≈ 11
  std::cout << "✓ test_evaluate_log_with_operations passed (result: " << result
            << ")\n";
}

void test_stress_very_large_numbers() {
  // Expression: 999999999*999999999
  std::vector<double> numbers{999999999, 999999999};
  std::vector<std::string> operators{"*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 9.99e17 && result <= 1.0e18); // ~9.99998e17
  std::cout << "✓ test_stress_very_large_numbers passed (result: " << result
            << ")\n";
}

void test_stress_very_small_numbers() {
  // Expression: 0.000000001*0.000000001
  std::vector<double> numbers{0.000000001, 0.000000001};
  std::vector<std::string> operators{"*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 9.9e-19 && result <= 1.1e-18); // 1e-18
  std::cout << "✓ test_stress_very_small_numbers passed (result: " << result
            << ")\n";
}

void test_stress_deeply_nested_parentheses() {
  // Expression: ((((1+2)*3)/4)^2)
  std::vector<double> numbers{1, 2, 3, 4, 2};
  std::vector<std::string> operators{"(", "(", "(", "(", "+", ")",
                                     "*", ")", "/", ")", "^", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 5.06 && result <= 5.07); // ((1+2)*3/4)^2 = (2.25)^2 = 5.0625
  std::cout << "✓ test_stress_deeply_nested_parentheses passed (result: "
            << result << ")\n";
}

void test_stress_long_addition_chain() {
  // Expression: 1+2+3+4+5+6+7+8+9+10
  std::vector<double> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<std::string> operators{"+", "+", "+", "+", "+",
                                     "+", "+", "+", "+"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 55); // Sum of 1 to 10 = 55
  std::cout << "✓ test_stress_long_addition_chain passed (result: " << result
            << ")\n";
}

void test_stress_long_multiplication_chain() {
  // Expression: 2*2*2*2*2*2*2*2*2*2
  std::vector<double> numbers{2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  std::vector<std::string> operators{"*", "*", "*", "*", "*",
                                     "*", "*", "*", "*"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 1024); // 2^10 = 1024
  std::cout << "✓ test_stress_long_multiplication_chain passed (result: "
            << result << ")\n";
}

void test_stress_nested_functions() {
  // Expression: sin(cos(sin(cos(0))))
  std::vector<double> numbers{0};
  std::vector<std::string> operators{"sin", "(", "cos", "(", "sin", "(",
                                     "cos", "(", ")",   ")", ")",   ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= 0.617 && result <= 0.619); // sin(cos(sin(cos(0)))) ≈ 0.618
  std::cout << "✓ test_stress_nested_functions passed (result: " << result
            << ")\n";
}

void test_stress_mixed_operations_complex() {
  // Expression: (10+5)*2-8/4+3^2
  std::vector<double> numbers{10, 5, 2, 8, 4, 3, 2};
  std::vector<std::string> operators{"(", "+", ")", "*", "-", "/", "+", "^"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 37); // (10+5)*2-8/4+3^2 = 15*2-2+9 = 30-2+9 = 37
  std::cout << "✓ test_stress_mixed_operations_complex passed (result: "
            << result << ")\n";
}

void test_stress_precision_near_zero() {
  // Expression: sin(3.14159265359)-0
  std::vector<double> numbers{3.14159265359, 0};
  std::vector<std::string> operators{"sin", "(", ")", "-"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result >= -0.0001 && result <= 0.0001); // sin(π) ≈ 0
  std::cout << "✓ test_stress_precision_near_zero passed (result: " << result
            << ")\n";
}

void test_stress_exponentiation_large() {
  // Expression: 10^15
  std::vector<double> numbers{10, 15};
  std::vector<std::string> operators{"^"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 1e15); // 10^15 = 1000000000000000
  std::cout << "✓ test_stress_exponentiation_large passed (result: " << result
            << ")\n";
}

void test_stress_negative_exponentiation() {
  // Expression: 10^neg(6)
  std::vector<double> numbers{10, 6};
  std::vector<std::string> operators{"^", "neg", "(", ")"};

  std::reverse(numbers.begin(), numbers.end());
  std::reverse(operators.begin(), operators.end());

  double result = calqi::evaluate(numbers, operators);
  assert(result == 1e-6); // 10^(-6) = 0.000001
  std::cout << "✓ test_stress_negative_exponentiation passed (result: "
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

  std::cout << "\n--- Trigonometric and Logarithmic Function Tests ---\n";
  test_evaluate_sin_function();
  test_evaluate_cos_function();
  test_evaluate_tan_function();
  test_evaluate_asin_function();
  test_evaluate_acos_function();
  test_evaluate_atan_function();
  test_evaluate_log_function();
  test_evaluate_ln_function();

  std::cout << "\n--- Hyperbolic Function Tests ---\n";
  test_evaluate_sinh_function();
  test_evaluate_cosh_function();
  test_evaluate_tanh_function();
  test_evaluate_asinh_function();
  test_evaluate_acosh_function();
  test_evaluate_atanh_function();

  std::cout << "\n--- Negation Function Tests ---\n";
  test_evaluate_neg_function();
  test_evaluate_neg_negative_number();
  test_evaluate_neg_with_addition();
  test_evaluate_neg_with_multiplication();
  test_evaluate_double_negation();
  test_evaluate_neg_in_parentheses();
  test_evaluate_neg_with_exponent();
  test_evaluate_neg_with_function();

  std::cout << "\n--- Function Combination Tests ---\n";
  test_evaluate_function_with_addition();
  test_evaluate_function_with_multiplication();
  test_evaluate_nested_functions();
  test_evaluate_function_in_parenthesis();
  test_evaluate_function_in_nested_parenthesis();
  test_evaluate_multiple_functions();
  test_evaluate_log_with_operations();

  std::cout << "\n--- Stress Tests ---\n";
  test_stress_very_large_numbers();
  test_stress_very_small_numbers();
  test_stress_deeply_nested_parentheses();
  test_stress_long_addition_chain();
  test_stress_long_multiplication_chain();
  test_stress_nested_functions();
  test_stress_mixed_operations_complex();
  test_stress_precision_near_zero();
  test_stress_exponentiation_large();
  test_stress_negative_exponentiation();

  std::cout << "\n✅ All tests completed\n";

  return 0;
}
