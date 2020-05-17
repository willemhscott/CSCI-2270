#ifndef LECT_190927_TREE_H
#define LECT_190927_TREE_H

#include "LinkedList.h"

class Teap {
public:
    int value;
    int height;

    Teap(int);
    Teap(int, Teap*);
    Teap *parent;
    Teap *left, *right;

    void insert(int);
    int insert(int, int);
    void print();
    void print(int);
    bool search(int);
    Teap *remove(int);
    LinkedList listify();

    void destroy();
};


#endif //LECT_190927_TREE_H
