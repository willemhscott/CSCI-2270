#ifndef LECT_190927_TREE_H
#define LECT_190927_TREE_H

#include "LinkedList.h"

class Heap {
public:
    int value;
    int height;

    Heap(int);
    Heap(int, Heap*);
    Heap *parent;
    Heap *left, *right;

    void insert(int);
    int insert(int, int);
    void print();
    void print(int);
    bool search(int);
    Heap *remove(int);
    LinkedList listify();

    void destroy();
};


#endif //LECT_190927_TREE_H
