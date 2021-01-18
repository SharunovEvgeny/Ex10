// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 12.01.2021.
//
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
 private:
    int size;
    int top;
    T *stackData;

 public:
    explicit MyStack(int sizeValue = 7) {
        stackData = new T[sizeValue];
        top = 0;
        size = sizeValue;
    }

    MyStack(const MyStack &copiedStack) {
        stackData = new T[copiedStack.size];
        size = copiedStack.size;
        top = copiedStack.top;
        for (int iter = 0; iter < copiedStack.size; iter++) {
            stackData[iter] = copiedStack.stackData[iter];
        }
    }

    ~MyStack() {
        top = 0;
        size = 0;
        delete[] stackData;
    }

    T get() const {
        if (!isEmpty()) {
            return stackData[top - 1];
        } else {
            throw "Can not get a stack item because the stack is empty";
        }
    }

    T pop() {
        if (!isEmpty()) {
            return stackData[--top];
        } else {
            throw "Can not get a stack item because the stack is empty";
        }
    }

    void push(T newItem) {
        if (!isFull()) {
            stackData[top] = newItem;
            top++;
        } else {
            throw "It is impossible to add item.Stack is overflowed";
        }
    }

    [[nodiscard]] bool isFull() const {
        return size == top;
    }

    [[nodiscard]] bool isEmpty() const {
        return 0 == top;
    }
};

#endif  // INCLUDE_MYSTACK_H_
