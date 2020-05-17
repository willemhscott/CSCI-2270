//
// Created by willemhscott on 9/13/19.
//

#ifndef ASSIGNMENT_1_LINKEDLIST_H
#define ASSIGNMENT_1_LINKEDLIST_H

struct ListNode {
    ListNode(int n) {
        value = n;
        next = nullptr;
        last = nullptr;
    }
    int value;
    ListNode *next;
    ListNode *last;

};

class LinkedList {
private:
    ListNode *head;
    ListNode *tail;
public:
    LinkedList();

    void put(int); // append right
    void putleft(int); // append left
    int get(int); // get at index
    int pop(); // remove and return from right
    int pop(int);
    int popleft(); // remove and return from right
    int size();
    int index(int);
    void remove(int);

};


#endif //ASSIGNMENT_1_LINKEDLIST_H
