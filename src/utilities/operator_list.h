#pragma once
#include <string>
#include <unordered_set>

namespace calqi {
const std::unordered_set<std::string> operators = {
    "+",   "-",   "*",   "/",    "%",    "^",    "(",   ")", "sqrt",
    "sin", "cos", "tan", "asin", "acos", "atan", "log", "ln"};
}