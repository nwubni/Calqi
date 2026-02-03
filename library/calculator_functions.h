#pragma once

#include <iostream>
#include <vector>

int add(const int &a, const int &b);
int subtract(const int &a, const int &b);
int multiply(const int &a, const int &b);
int divide(const int &a, const int &b);
bool isOperator(const char &c);
bool isAdditionOrSubtraction(const char &op);
bool isMultiplicationOrDivision(const char &op);
int evaluate(std::vector<int> &numbers, std::vector<char> &operators);