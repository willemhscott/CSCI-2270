//
// Created by willemhscott  on 9/25/19.
//

#include "Queue.h"

Queue::Queue() {
    contents = LinkedList();
}

void Queue::push(int value) {
    contents.put(value);
}

int Queue::pop() {
    return contents.popleft();
}

int Queue::peek() {
    return contents.get(0);
}

int Queue::isEmpty() {
    return contents.head == nullptr;
}