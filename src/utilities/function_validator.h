#pragma once

#include <string>
#include <unordered_map>

namespace calqi {
bool sinValid(const double &value);
bool cosValid(const double &value);
bool tanValid(const double &value);
bool logValid(const double &value);
bool negValid(const double &value);
bool sqrtValid(const double &value);
bool asinValid(const double &value);
bool acosValid(const double &value);
bool atanValid(const double &value);
bool sinhValid(const double &value);
bool coshValid(const double &value);
bool tanhValid(const double &value);
bool atanhValid(const double &value);
bool asinhValid(const double &value);
bool acoshValid(const double &value);
bool factValid(const double &value);
bool floorValid(const double &value);
bool ceilValid(const double &value);
bool randValid(const double &value);

inline const std::unordered_map<std::string, bool (*)(const double &)>
    valid_function_value = {
        {"sin", sinValid},     {"neg", negValid},     {"cos", cosValid},
        {"tan", tanValid},     {"log", logValid},     {"sqrt", sqrtValid},
        {"asin", asinValid},   {"acos", acosValid},   {"atan", atanValid},
        {"ln", logValid},      {"sinh", sinhValid},   {"cosh", coshValid},
        {"tanh", tanhValid},   {"atanh", atanhValid}, {"asinh", asinhValid},
        {"acosh", acoshValid}, {"fact", factValid},   {"floor", floorValid},
        {"ceil", ceilValid},   {"rand", randValid}};
} // namespace calqi