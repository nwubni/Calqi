#pragma once

#include <string>
#include <unordered_map>

namespace calqi {
bool sinValid(const double &value);
bool cosValid(const double &value);
bool tanValid(const double &value);
bool logValid(const double &value);
bool sqrtValid(const double &value);
bool asinValid(const double &value);
bool acosValid(const double &value);
bool atanValid(const double &value);

const std::unordered_map<std::string, bool (*)(const double &)>
    valid_function_value = {{"sin", sinValid},   {"cos", cosValid},
                            {"tan", tanValid},   {"log", logValid},
                            {"sqrt", sqrtValid}, {"asin", asinValid},
                            {"acos", acosValid}, {"atan", atanValid},
                            {"ln", logValid}};
} // namespace calqi