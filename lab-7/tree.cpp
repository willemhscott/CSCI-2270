#include <iostream>
#include "tree.hpp"

using namespace std;
#define COUNT 10


/*
Constructor for a Tree object
*/
Teap::Teap() {
    this->root = nullptr;
}

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void Teap::print2DUtil(Node *root, int space) {
    // Base case
    if (root == nullptr)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

void Teap::preOrderTraverse(Node *node) {
    if (node == nullptr)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    preOrderTraverse(node->left);

    /* now recur on right subtree */
    preOrderTraverse(node->right);
}


/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
            This function deletes all the nodes in the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
void Teap::deleteTree(Node *node) {
    if (node == nullptr) return;

    /*TODO first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
    /* TODO then delete the node */
    cout << "\n Deleting node:" << node->data;
    delete node;
}

/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
          This function gives the sum of all the nodes in the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
int Teap::sumNodes(Node *node) {
    if (node == nullptr) {
        return 0;
    }
//TODO Base case
    int sum = node->data;
    sum += sumNodes(node->left);
    sum += sumNodes(node->right);

//TODO Implement Sum of all nodes

    return sum;
}

/*
 Creates a tree of 7 elements
 */
void Teap::createTree() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    this->root = root;
}
