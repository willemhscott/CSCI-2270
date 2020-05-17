//
// Created by willemhscott  on 9/23/19.
//

#include "Stack.h"

Stack::Stack() {
    contents = LinkedList();
}

void Stack::push(int value) {
    contents.putleft(value);
}

int Stack::pop() {
    return contents.popleft();
}

int Stack::peek() {
    return contents.get(0);
}