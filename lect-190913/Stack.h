//
// Created by willemhscott on 9/23/19.
//

#ifndef LECT_190913_STACK_H
#define LECT_190913_STACK_H

#include "LinkedList.h"


class Stack {
public:
    Stack();
    void push(int);
    int pop();
private:
    LinkedList contents;
};


#endif //LECT_190913_STACK_H
