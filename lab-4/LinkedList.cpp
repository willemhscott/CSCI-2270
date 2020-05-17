#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node *prev, int newKey) {

    //Check if head is Null i.e list is empty
    if (head == nullptr) {
        head = new Node;
        head->key = newKey;
        head->next = nullptr;
    }

        // if list is not empty, look for prev and append our node there
    else if (prev == nullptr) {
        Node *newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    } else {
        Node *newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;
    }
}


// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n) {
    bool isDeleted = false;

    if (head == nullptr) {
        cout << "List is already empty" << endl;
        return isDeleted;
    }

    // Special case to delete the head
    if (n == 0) {
        //TODO
        Node *ohead = head;
        head = head->next;
        delete ohead;
    }

    Node *prev;
    Node *hnode = head;
    for (int i = 0; i < n && hnode != nullptr; i++) {
        prev = hnode;
        hnode = hnode->next;
    }
    if (hnode != nullptr) {
        prev->next = hnode->next;
        delete hnode;

        isDeleted = true;
    }

    // TODO

    return isDeleted;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast() {
    bool isSwapped = false;

    if (head == nullptr) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }

    // TODO
    Node *prev = head;
    Node *endnode = head;
    while (endnode->next != nullptr) {
        prev = endnode;
        endnode = endnode->next;
    }

    prev->next = head;
    endnode->next = head->next;
    head->next = nullptr;
    head = endnode;
    isSwapped = true;

    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList() {
    Node *temp = head;

    while (temp->next != nullptr) {
        cout << temp->key << " -> ";
        temp = temp->next;
    }

    cout << temp->key << endl;
}

// Search for a specified key and return a pointer to that node
Node *LinkedList::searchList(int key) {

    Node *ptr = head;
    while (ptr != nullptr && ptr->key != key) {
        ptr = ptr->next;
    }
    return ptr;
}
