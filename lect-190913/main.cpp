//
// Created by willemhscott  on 9/13/19.
//
#include <iostream>

#include "LinkedList.h"
#include "Stack.h"

using namespace std;

int main() {
    Stack stack = Stack();
    stack.push(15);
    stack.push(12);
    stack.push(11);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
}