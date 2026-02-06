#pragma once

#include <cmath>
#include <string>
#include <unordered_map>

namespace calqi {
inline const std::unordered_map<std::string, double> math_constants = {
    {"pi", M_PI}, // 3.14159265358979323846
    {"e", M_E}    // 2.71828182845904523536
};
}