#pragma once

#include <cmath>
#include <string>
#include <unordered_map>

const std::unordered_map<std::string, double(*)(double)> trigonometricFunctions{
    {"sin", std::sin},
    {"cos", std::cos},
    {"tan", std::tan},
    {"asin", std::asin},
    {"acos", std::acos},
    {"atan", std::atan}
};