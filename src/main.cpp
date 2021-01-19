// Copyright 2021 Ex10 TiNa
#include "postfix.h"
#include "MyStack.h"
#include <iostream>

int main()
{
    std::string s1("(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9");
    std::string s2 = infix2prefix(s1);
    std::cout << s2;  // 6 4 2 - * 5 + 2.6 3 7 * + * 9 -
    return 0;
}
