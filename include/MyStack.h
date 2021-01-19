// Copyright 2021 Ex09 TiNa
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_
#include <iostream>

template<typename T>
class MyStack {
private:
    int top;
    int size;
    T* stack;

public:
    explicit MyStack(int sizeIn) {
        top = 0;
        size = sizeIn;
        stack = new T[size];
    }

    MyStack(const MyStack& stack2) {
        top = stack2.top;
        size = stack2.size;
        stack = new T[size];
        for (int i = 0; i < size; i++)
            stack[i] = stack2.stack[i];
    }

    ~MyStack() {
        delete[] stack;
    }

    T get() const {
        if (top != 0) {
            return stack[top - 1];
        }
    }

    T pop() {
        if (top != 0) {
            top--;
            return stack[top];
        }
    }

    void push(T elem) {
        if (top < size) {
            stack[top] = elem;
            top++;
        }
    }

    bool isFull() const {
        if (top == size)
            return true;
        else
            return false;
    }

    bool isEmpty() const {
        if (top == 0)
            return true;
        else
            return false;
    }
};

#endif  // INCLUDE_MYSTACK_H_
