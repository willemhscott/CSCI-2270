#include <iostream>
#include "ProducerConsumer.hpp"

using namespace std;

ProducerConsumer::ProducerConsumer() {
    queueFront = 0; //the index in queue[] that will be dequeued next
    queueEnd = 0; //the first index in queue[] that is available to populate
    counter = 0; //changed
}

bool ProducerConsumer::isEmpty() {
    return counter == 0;
}

bool ProducerConsumer::isFull() {
    return counter == SIZE;
}

void ProducerConsumer::enqueue(std::string item) {
    if (counter == SIZE) {
        cout << "Queue full, cannot add new item" << endl;
        return;
    }
    counter += 1;
    queue[queueEnd] = item;
    queueEnd = (queueEnd + 1) % SIZE;
}

void ProducerConsumer::dequeue() {
    if (isEmpty()) {
        cout << "Queue empty, cannot dequeue an item" << endl;
        return;
    }
    counter -= 1;
    queueFront = (queueFront + 1) % SIZE;
}

std::string ProducerConsumer::peek() {
    if (counter != 0) {
        return queue[queueFront];
    } else {
        cout << "Queue empty, cannot peek";
        return "";
    }
}

int ProducerConsumer::queueSize() {
    return counter;
}

