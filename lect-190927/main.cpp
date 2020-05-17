#include "Tree.h"
#include <iostream>

using namespace std;

int main() {
    srand(69696969);
    int midpoint = 10;

    Tree mytree = Tree(midpoint);
    int last = 0;
    for (int i = 0; i < 6; i++) {
        last = rand() % (midpoint * 2);
        mytree.insert(last);
    }

    for (int i = 0; i < 5; i++) {
        mytree.print();
        LinkedList ll = mytree.listify();
        ListNode *node = ll.head;
        while (node != nullptr) {
            cout << node->value << ", ";
            node = node->next;
        }
        cout << endl;
        mytree.remove(mytree.value);
    }

    //cout << mytree.height << endl;

}