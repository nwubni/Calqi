# C++ Calculator

A simple calculator that can evaluate expressions containing addition, subtraction, multiplication, division, and parentheses.

**Command to build program:** <br>
`g++ -std=c++20 -o calc calc.cpp parsers/calculator_parser.cpp library/calculator_functions.cpp`

**Command to run program:** <br>
`./calc "2 + (3 * 4)"`

**Command to run tests:** <br>
`g++ -std=c++20 tests/test_calculator.cpp parsers/calculator_parser.cpp library/calculator_functions.cpp -o test_calculator && ./test_calculator`

