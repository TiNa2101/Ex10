// Copyright 2021 Ex10 TiNa
#ifndef INCLUDE_POSTFIX_H_
#define INCLUDE_POSTFIX_H_
#include <iostream>
#include <string.h>

std::string infix2prefix(std::string inf);
int Priority(char oper);
bool isOperator(char elem);

#endif  // INCLUDE_POSTFIX_H_
