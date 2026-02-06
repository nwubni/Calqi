# C++ Calculator

A simple calculator that can evaluate expressions containing addition, subtraction, multiplication, division, and parentheses.

**Command to build program:** <br>
`g++ -std=c++20 -o calqi src/main.cpp src/parsers/calculator_parser.cpp src/library/calculator_functions.cpp src/utilities/function_validator.cpp -lreadline`

**Command to run program:** <br>
`./calqi "2 + (3 * 4)"`

**Command to run tests:** <br>
`g++ -std=c++20 tests/test_calculator.cpp src/parsers/calculator_parser.cpp src/library/calculator_functions.cpp src/utilities/function_validator.cpp -o test_calculator && ./test_calculator`
