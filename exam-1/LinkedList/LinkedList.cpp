#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=NULL){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    }

    else{

        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;

    }
}



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n){
    // Why is everything NULL instead of nullptr?
    // I can't use nullptr because it prints differently
    // But my linter complains about using NULL instead of nullptr

    Node *temp = head;
    int count = 0;

    // Count the number of items in our LL (linked list)
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // The item we want to remove will be at the size - n'th index
    int index = count - n;
    temp = head;
    Node *previous = NULL;
    // Traverse the LL until we find the size - n'th item
    // Tracking the size - n - 1'th item so we can linked the list back up
    for (int i = 0; i < index; i++) {
        previous = temp;
        temp = temp->next;
    }

    // If we aren't looking at removing the head
    if (previous != NULL) {
        previous->next = temp->next;
    } else { // Otherwise
        head = head->next;
    }
    // cleanup
    delete temp;
}

