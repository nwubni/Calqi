#pragma once
#include <string>
#include <unordered_map>

namespace calqi {
inline const std::unordered_map<std::string, std::string>
    function_error_messages = {
        {"+", "Addition operator (+) requires two operands"},
        {"-", "Subtraction operator (-) requires two operands"},
        {"*", "Multiplication operator (*) requires two operands"},
        {"/", "Division operator (/) requires two operands"},
        {"%", "Modulo operator (%) requires two operands"},
        {"^", "Exponentiation operator (^) requires two operands"},
        {"neg", "Negation operator (neg) requires one operand"},
        {"sqrt",
         "Square root function (sqrt) requires one operand greater than or "
         "equal to 0"},
        {"sin", "Sine function (sin) requires one operand"},
        {"cos", "Cosine function (cos) requires one operand"},
        {"tan", "Tangent function (tan) requires one operand"},
        {"asin", "Arcsine function (asin) requires one operand within [-1, 1]"},
        {"acos",
         "Arccosine function (acos) requires one operand within [-1, 1]"},
        {"atan", "Arctangent function (atan) requires one operand"},
        {"log", "Logarithm (log) function requires one operand greater than 0"},
        {"ln",
         "Natural logarithm (ln) function requires one operand greater than 0"},
        {"sinh", "Hyperbolic sine function (sinh) requires one operand"},
        {"cosh", "Hyperbolic cosine function (cosh) requires one operand"},
        {"tanh", "Hyperbolic tangent function (tanh) requires one operand"},
        {"atanh", "Inverse hyperbolic tangent function (atanh) requires one "
                  "operand in the range (-1, 1)"},
        {"asinh",
         "Inverse hyperbolic sine function (asinh) requires one operand"},
        {"acosh", "Inverse hyperbolic cosine function (acosh) requires one "
                  "operand >= 1"},
};
}