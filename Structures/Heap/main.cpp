#include "Heap.h"
#include <iostream>
#include <LinkedList.h>

using namespace std;

int main() {
    srand(69696969);
    int midpoint = 10;

    Heap myheap = Heap(midpoint);
    int last = 0;
    for (int i = 0; i < 6; i++) {
        last = rand() % (midpoint * 2);
        myheap.insert(last);
    }
    myheap.print();
    myheap = *myheap.remove(myheap.value);
    myheap.print();

    LinkedList ll = myheap.listify();
    ListNode *node = ll.head;
    while (node != nullptr) {
        cout << node->value << ", ";
        node = node->next;
    }
    cout << endl;

    //cout << myheap.height << endl;

}