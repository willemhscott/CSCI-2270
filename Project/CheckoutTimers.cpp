#include "CheckoutTimers.h"
#include <ctime>
#include <iostream>

using namespace std;

void CheckoutTimers::checkout(int minutes, string name, string author, string title) {
    /*
     * Checkout a book, i.e. add a new `CheckedOutBook` to the priority queue
     * Use array doubling if too many books are checked out at once
     * That said, books are by default checked out for 60 seconds in real time
     * So you must be determined to add 8 before the first is checked out again
     */
    time_t stime = time(nullptr);
    CheckedOutBook node = CheckedOutBook((int) stime + minutes, name, author, title);

    // Doubling
    if (size + 1 >= capacity) {
        capacity *= 2;
        CheckedOutBook *temp = new CheckedOutBook[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = heap[i];
        }
        delete[] heap;
        heap = temp;
    }
    // Insert the new node
    heap[size] = node;
    int index = size;
    size++;
    // Bubble up to maintain heap
    while (index != 0 && heap[parent(index)].endtime > heap[index].endtime) {
        swap(index, parent(index));
        index = parent(index);
    }
}

int CheckoutTimers::peek() {
    /*
     * Return the end time of the timer ending soonest
     * Return 0 if there are no timers
     */
    if (size == 0) {
        return 0;
    } else {
        CheckedOutBook item = heap[0];
        return item.endtime;
    }
}

CheckedOutBook CheckoutTimers::pop() {
    /*
     * Get the smallest timer and re-heapify
     */
    CheckedOutBook node = heap[0];
    size -= 1;
    swap(0, size);
    minHeapify(0);
    return node;
}

void CheckoutTimers::printTimers() {
    /*
     * Self explanatory, print out each timer by time remaining (using the current time)
     */
    time_t t = time(nullptr);
    for (int i = 0; i < size; i++) {
        CheckedOutBook b = heap[i];
        cout << b.name << " has " << b.title << " by " << b.author;
        cout << " for another " << (int) b.endtime - t << " minutes" << endl;
    }
    if (size == 0) {
        cout << "No books are currently checked out." << endl;
    }
}

