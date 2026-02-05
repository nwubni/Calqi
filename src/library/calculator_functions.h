#pragma once

#include <iostream>
#include <string>
#include <vector>

double add(const double &a, const double &b);
double subtract(const double &a, const double &b);
double multiply(const double &a, const double &b);
double divide(const double &a, const double &b);
bool isOperator(const std::string &op);
bool isAdditionOrSubtraction(const std::string &op);
bool isMultiplicationOrDivision(const std::string &op);
double evaluate(std::vector<double> &numbers, std::vector<std::string> &operators);