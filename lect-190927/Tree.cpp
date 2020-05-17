#include "Tree.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

Tree::Tree(int val) {
    value = val;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    height = 0;
}

Tree::Tree(int val, Tree *p_pointer) {
    value = val;
    parent = p_pointer;
    left = nullptr;
    right = nullptr;
    height = 0;
}

LinkedList Tree::listify() {
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

bool Tree::search(int n) {
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

void Tree::insert(int n) {
    /*
    int cheight = insert(n, 0);
    if (cheight > height) {
        height = cheight;
    }
     */

    if (n < value) {
        if (left == nullptr) {
            left = new Tree(n, this);
            //return 1;
        } else {
            left->insert(n);
        }
    } else {
        if (right == nullptr) {
            right = new Tree(n, this);
        } else {
            right->insert(n);
        }
    }
}

int Tree::insert(int h, int n) {
    if (n < value) {
        if (left == nullptr) {
            left = new Tree(n, this);
            return 1;
        } else {
            return left->insert(h + 1, n) + 1;
        }
    } else {
        if (right == nullptr) {
            right = new Tree(n, this);
            return 1;
        } else {
            return right->insert(h + 1, n) + 1;
        }
    }
}

void Tree::print() {
    print(0);
}

void Tree::print(int spaces) {
    string prefix = "";
    for (int i = 0; i < spaces; i++) {
        prefix += " ";
    }
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

void Tree::destroy() {
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

void Tree::remove(int n) {
    if (n == value) {
        if (left != nullptr) {
            Tree *previous = this;
            Tree *current = left;
            while (current->right != nullptr) {
                previous = current;
                current = current->right;
            }
            int val = current->value;
            previous->left = current->left;
            previous->right = nullptr;
            value = val;
            delete current;

        } else if (right != nullptr) {
            Tree *previous = this;
            Tree *current = right;
            while (current->left != nullptr) {
                previous = current;
                current = current->left;
            }
            int val = current->value;
            previous->right = current->right;
            previous->left = nullptr;
            value = val;
            delete current;

        } else {
            return;
        }
    } else {

        if (n < value) {
            if (left == nullptr) {
                return;
            }
            left->remove(n);
        } else {
            if (right == nullptr) {
                return;
            }
            right->remove(n);
        }
    }
};