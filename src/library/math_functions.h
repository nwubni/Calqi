#pragma once

#include <cmath>
#include <string>
#include <unordered_map>

namespace calqi {

// Negation function
inline double neg(double x) { return -x; }

inline const std::unordered_map<std::string, double (*)(double)> math_functions{
    {"abs", std::abs},     {"sqrt", std::sqrt},  {"neg", neg},
    {"sin", std::sin},     {"cos", std::cos},    {"tan", std::tan},
    {"asin", std::asin},   {"acos", std::acos},  {"atan", std::atan},
    {"log", std::log10},   {"ln", std::log},     {"sinh", std::sinh},
    {"cosh", std::cosh},   {"tanh", std::tanh},  {"atanh", std::atanh},
    {"asinh", std::asinh}, {"acosh", std::acosh}};
} // namespace calqi
