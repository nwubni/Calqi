#pragma once
#include <string>
#include <unordered_set>

namespace calqi {
inline const std::unordered_set<std::string> operators = {
    "+",    "-",   "*",    "/",    "%",    "^",     "(",     ")",
    "sqrt", "sin", "cos",  "tan",  "asin", "acos",  "atan",  "log",
    "ln",   "abs", "sinh", "cosh", "tanh", "atanh", "asinh", "acosh"};
}