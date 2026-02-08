#pragma once

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unordered_map>

namespace calqi {

// Negation function
inline double neg(double x) { return -x; }

// Factorial function
inline double fact(double x) {
  int n = static_cast<int>(x);
  if (n < 0)
    return 0; // Invalid, will be caught by validator

  if (n == 0 || n == 1)
    return 1;

  if (n > 170)
    return std::numeric_limits<double>::infinity();

  // Lookup table for small factorials
  static const double table[] = {1,       1,        2,        6,     24,
                                 120,     720,      5040,     40320, 362880,
                                 3628800, 39916800, 479001600};

  if (n < 13)
    return table[n];

  double result = table[12];
  for (int i = 13; i <= n; i++) {
    result *= i;
  }

  return result;
}

// Random number generator (1 to max)
inline double rand_func(double max) {
  static bool seeded = false;
  if (!seeded) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    seeded = true;
  }
  int max_int = static_cast<int>(max);
  if (max_int <= 0)
    return 0;
  return 1 + (std::rand() % max_int);
}

inline const std::unordered_map<std::string, double (*)(double)> math_functions{
    {"abs", std::abs},     {"sqrt", std::sqrt},   {"neg", neg},
    {"sin", std::sin},     {"cos", std::cos},     {"tan", std::tan},
    {"asin", std::asin},   {"acos", std::acos},   {"atan", std::atan},
    {"log", std::log10},   {"ln", std::log},      {"sinh", std::sinh},
    {"cosh", std::cosh},   {"tanh", std::tanh},   {"atanh", std::atanh},
    {"asinh", std::asinh}, {"acosh", std::acosh}, {"fact", fact},
    {"floor", std::floor}, {"ceil", std::ceil},   {"rand", rand_func}};
} // namespace calqi
