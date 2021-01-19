// Copyright 2021 Ex10 TiNa
#include <string>
#include <iostream>
#include "postfix.h"
#include "MyStack.h"

int Priority(char oper) {
    if (oper == '(')
        return 0;
    if (oper == ')')
        return 1;
    if ((oper == '+') || (oper == '-'))
        return 2;
    if ((oper == '*') || (oper == '/'))
        return 3;
}

bool isOperator(char elem) {
    if ((elem == '(') || (elem == ')') || (elem == '+') || (elem == '-') || (elem == '*') || (elem == '/'))
        return true;
    else
        return false;
}

std::string infix2prefix(std::string inf) {
    std::string pref = "";
    MyStack<char> stack(400);
    for (int i = 0; i < inf.size(); i++) {
        if (inf[i] == ' ') {
            continue;
        }
        if (isOperator(inf[i])) {
            if ((Priority(inf[i]) == 0) || stack.isEmpty()) {
                stack.push(inf[i]);
            } else {
                if (Priority(inf[i]) > Priority(stack.get())) {
                    stack.push(inf[i]);
                } else {
                    while (!stack.isEmpty() && Priority(stack.get()) >= Priority(inf[i])) {
                        pref = pref + stack.pop() + ' ';
                    }
                    if (Priority(inf[i]) == 1) {
                        if (Priority(stack.get()) == 0) {
                            stack.pop();
                        }
                    } else {
                        stack.push(inf[i]);
                    }
                }
            }
        } else {
            if (inf[i + 1] == '.' || inf[i] == '.') {
                std::cout << "/'" << 1 << "/'" << std::endl;
                pref = pref + inf[i];
            } else {
                std::cout << "/'" << 2 << "/'" << std::endl;
                pref = pref + inf[i] + ' ';
            }
        }
    }
    while (!stack.isEmpty()) {
        pref = pref + stack.pop() + " ";
    }
    if (pref[pref.length() - 1] == ' ') {
        pref = pref.substr(0, pref.length() - 1);
    }
    return pref;
}
