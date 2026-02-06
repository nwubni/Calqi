#pragma once
#include <string>
#include <unordered_map>

namespace calqi {
const std::unordered_map<std::string, std::string> operator_error_messages = {
    {"+", "Addition operator (+) requires two operands"},
    {"-", "Subtraction operator (-) requires two operands"},
    {"*", "Multiplication operator (*) requires two operands"},
    {"/", "Division operator (/) requires two operands"},
    {"%", "Modulo operator (%) requires two operands"},
    {"^", "Exponentiation operator (^) requires two operands"},
    {"sqrt", "Square root function (sqrt) requires one operand greater than or equal to 0"},
    {"sin", "Sine function (sin) requires one operand within [-1, 1]"},
    {"cos", "Cosine function (cos) requires one operand within [-1, 1]"},
    {"tan", "Tangent function (tan) requires one operand"},
    {"asin", "Arcsine function (asin) requires one operand within [-1, 1]"},
    {"acos", "Arccosine function (acos) requires one operand within [-1, 1]"},
    {"atan", "Arctangent function (atan) requires one operand"},
    {"log", "Logarithm (log) function requires one operand greater than 0"},
    {"ln", "Natural logarithm (ln) function requires one operand greater than 0"}};
}