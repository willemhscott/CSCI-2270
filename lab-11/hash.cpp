// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    unsigned int index = hashFunction(key);
    if (table[index] == nullptr) {
        return nullptr;
    }

    node *snode = table[index];
    while (snode != nullptr && snode->key != key) {
        snode = snode->next;
    }

    if (snode == nullptr) {
        return nullptr;
    }
    return snode;
    //TODO: Search the list at that specific index and return the node if found
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        unsigned int index = hashFunction(key);
        node *cnode = createNode(key, nullptr);
        if (table[index] == nullptr) {
            table[index] = cnode;
            return true;
        }

        node *n = table[index];
        while (n->next != nullptr) {
            n = n->next;
        }
        n->next = cnode;
        return true;
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";

        //TODO
        node *cnode = table[i];
        while (cnode != nullptr) {
            cout << cnode->key << " ";
            cnode = cnode->next;
        }

        cout << endl;

    }

 }
