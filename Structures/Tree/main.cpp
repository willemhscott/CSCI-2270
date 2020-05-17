#include "Tree.h"
#include <iostream>

using namespace std;

int main() {
    srand(69696969);
    int midpoint = 10;

    Teap mytree = Teap(midpoint);
    int last = 0;
    for (int i = 0; i < 6; i++) {
        last = rand() % (midpoint * 2);
        mytree.insert(last);
    }
    mytree.print();
    mytree = *mytree.remove(mytree.value);
    mytree.print();

    LinkedList ll = mytree.listify();
    ListNode *node = ll.head;
    while (node != nullptr) {
        cout << node->value << ", ";
        node = node->next;
    }
    cout << endl;

    //cout << mytree.height << endl;

}