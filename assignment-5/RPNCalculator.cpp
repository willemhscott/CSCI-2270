#include <iostream>
#include "RPNCalculator.hpp"

using namespace std;

RPNCalculator::RPNCalculator() {
    stackHead = NULL;
}

RPNCalculator::~RPNCalculator() {
    while (stackHead != NULL) {
        pop();
    }
    stackHead = NULL;
}

bool RPNCalculator::isEmpty() {
    return stackHead == NULL;
}

void RPNCalculator::push(float num) {
    Operand *op = new Operand();
    op->number = num;
    op->next = stackHead;
    stackHead = op;
}

void RPNCalculator::pop() {
    if (isEmpty()) {
        cout << "Stack empty, cannot pop an item." << endl;
        return;
    }

    Operand *head = stackHead;
    stackHead = stackHead->next;
    delete head;
}

Operand* RPNCalculator::peek() {
    if (isEmpty()) {
        cout << "Stack empty, cannot peek." << endl;
    }
    return stackHead;
}

bool RPNCalculator::compute(string symbol) {
    if (symbol != "+" and symbol != "*") {
        cout << "err: invalid operation" << endl;
        return false;
    }

    if (isEmpty()) {
        cout << "err: not enough operands" << endl;
        return false;
    }
    float a = stackHead->number;
    pop();

    if (isEmpty()) {

        cout << "err: not enough operands" << endl;

        push(a);
        return false;
    }
    float b = stackHead->number;
    pop();

    if (symbol == "+") {
        push(a + b);
    } else {
        push(a * b);
    }
}