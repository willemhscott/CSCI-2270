#include "Heap.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

Heap::Heap(int val) {
    value = val;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    height = 0;
}

Heap::Heap(int val, Heap *p_pointer) {
    value = val;
    parent = p_pointer;
    left = nullptr;
    right = nullptr;
    height = 0;
}

LinkedList Heap::listify() {
    LinkedList ll;
    if (left != nullptr) {
        ll = left->listify();
    } else {
        ll = LinkedList();
    }

    ll.put(value);

    if (right != nullptr) {
        LinkedList rl = right->listify();
        ListNode *node = rl.head;
        while (node != nullptr) {
            ll.put(node->value);
            node = node->next;
        }
    }

    return ll;
};

bool Heap::search(int n) {
    if (n == value) {
        return true;
    }
    if (n < value) {
        if (left == nullptr) {
            return false;
        }
        return left->search(n);
    } else {
        if (right == nullptr) {
            return false;
        }
        return right->search(n);
    }
}

void Heap::insert(int n) {
    /*
    int cheight = insert(n, 0);
    if (cheight > height) {
        height = cheight;
    }
     */

    if (n < value) {
        if (left == nullptr) {
            left = new Heap(n, this);
            //return 1;
        } else {
            left->insert(n);
        }
    } else {
        if (right == nullptr) {
            right = new Heap(n, this);
        } else {
            right->insert(n);
        }
    }
}

int Heap::insert(int h, int n) {
    if (n < value) {
        if (left == nullptr) {
            left = new Heap(n, this);
            return 1;
        } else {
            return left->insert(h + 1, n) + 1;
        }
    } else {
        if (right == nullptr) {
            right = new Heap(n, this);
            return 1;
        } else {
            return right->insert(h + 1, n) + 1;
        }
    }
}

void Heap::print() {
    print(0);
}

void Heap::print(int spaces) {
    string prefix = string(2 * spaces, ' ');
    cout << prefix;
    cout << "- ";

    cout << value << endl;
    if (left != nullptr) {
        left->print(spaces + 1);
    }
    if (right != nullptr) {
        right->print(spaces + 1);
    }
}

void Heap::destroy() {
    if (left != nullptr) {
        left->destroy();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->destroy();
        delete right;
        right = nullptr;
    }
}

Heap *Heap::remove(int n) {
    if (n == value) {
        if (left == nullptr && right == nullptr) {
            return nullptr;
        }
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        Heap *predec = left;
        while (predec->right != nullptr) {
            predec = predec->right;
        }
        value = predec->value;
        left = left->remove(predec->value);
    } else {
        if (n < value && left != nullptr) {
            left = left->remove(n);
        } else if (n > value && right != nullptr) {
            right = right->remove(n);
        }
    }
    return this;
}