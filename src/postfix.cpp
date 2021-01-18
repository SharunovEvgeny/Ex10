// Copyright 2021 SharunovEvgeny
#include <iostream>
#include "MyStack.h"
#include "postfix.h"


std::string infix2postfix(std::string infix) {
    MyStack<char> op(201);
    std::string postfix;
    std::map<char, int> status = {
            {'(', 1},
            {')', 2},
            {'+', 3},
            {'-', 3},
            {'*', 4},
            {'/', 4},};
    for (char iter : infix) {
        if (iter == ' ') {
            continue;
        }
        if (('0' <= iter and iter <= '9') or iter == '.') {
            postfix += iter;
            continue;
        }
        char last = postfix[postfix.length() - 1];
        if ('0' <= last and last <= '9')
            postfix += ' ';
        if (iter == ')') {
            while (!op.isEmpty() && op.get() != '(') {
                postfix += op.pop();
                postfix += ' ';
            }
            if (!op.isEmpty()) {
                op.pop();
            }
            continue;
        }
        if (op.isEmpty()) {
            op.push(iter);
            continue;
        } else {
            bool f = status.find(iter)->second > status.find(op.get())->second;
            if (iter == '(' or f) {
                op.push(iter);
                continue;
            }
        }
        int st = status.find(iter)->second;
        while (!op.isEmpty() && status.find(op.get())->second >= st) {
            postfix += op.pop();
            postfix += ' ';
        }
        op.push(iter);
    }
    char last = postfix[postfix.length() - 1];
    if ('0' <= last and last <= '9')
        postfix += ' ';
    while (!op.isEmpty()) {
        postfix += op.pop();
        postfix += ' ';
    }
    postfix.pop_back();
    return postfix;
}
