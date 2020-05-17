#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

void LinkedList::put(int n) {
    if (tail == nullptr) {
        head = new ListNode(n);
        tail = head;
    } else {
        tail->next = new ListNode(n);
        tail->next->last = tail;
        tail = tail->next;
    }
}

void LinkedList::putleft(int n) {
    if (head == nullptr) {
        head = new ListNode(n);
        tail = head;
    } else {
        head->last = new ListNode(n);
        head->last->next = head;
        head = head->last;
    }
}

int LinkedList::size() {
    if (head == nullptr) {
        return 0;
    }
    ListNode *item = head;
    int c = 1;
    while (item->next != nullptr) {
        item = item->next;
        c++;
    }
    return c;
}

int LinkedList::get(int i) {
    ListNode *item = head;
    for (int j = 0; j < i; j++) {
        //if (item->next != nullptr) {
        item = item->next;
        //}
    }
    return item->value;
}

int LinkedList::pop() {
    if (tail->last == nullptr) {
        int value = tail->last->value;
        tail = nullptr;
        head = nullptr;
        return value;
    }
    ListNode *newtail = tail->last;
    tail->last->next = nullptr;
    int value = tail->value;
    delete tail;
    tail = newtail;

    return value;
}

int LinkedList::popleft() {
    if (head->next == nullptr) {
        int value = head->value;
        head = nullptr;
        tail = nullptr;
        return value;
    }

    ListNode *newhead = head->next;
    head->next->last = nullptr;
    int value = head->value;
    delete head;
    head = newhead;

    return value;
}

int LinkedList::index(int number) {
    int n = 0;
    ListNode *item = head;
    while (item) {
        if (item->value == number) {
            return n;
        }
        n++;
        item = item->next;
    }
    return -1;
}

int LinkedList::pop(int index) {
    ListNode *item = head;
    for (int i = 0; i < index; i++) {
        item = item->next;
    }
    item->last->next = item->next;
    item->next->last = item->last;

    int value = item->value;
    delete item;
    return value;
}

void LinkedList::remove(int number) {
    ListNode *item = head;
    while (item) {
        if (item->value == number) {
            break;
        }
    }
    item->last->next = item->next;
    item->next->last = item->last;

    delete item;
}

//void LinkedList::sort() {

//}