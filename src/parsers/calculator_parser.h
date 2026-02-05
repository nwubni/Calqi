#pragma once

#include <string>
#include <vector>

void parseExpression(const std::string &expression, std::vector<double> &numbers,
                     std::vector<std::string> &operators);