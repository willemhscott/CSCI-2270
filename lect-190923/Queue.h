//
// Created by willemhscott on 9/25/19.
//

#ifndef LECT_190923_QUEUE_H
#define LECT_190923_QUEUE_H

#include "LinkedList.h"

class Queue {
    Queue();
    void push(int);
    int pop();
    int peek();
    bool isFull();
    bool isEmpty();
private:
    LinkedList contents;
};


#endif //LECT_190923_QUEUE_H
