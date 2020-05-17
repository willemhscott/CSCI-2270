#include <iostream>
using namespace std;
#define COUNT 10

/*
Each node in the tree has this structure
*/
struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};


/*
Variables and functions for Tree ADT
*/
class Teap
{

  public:
    Node *root;
    Teap();
    void createTree();
    void deleteTree(Node *root);
    int sumNodes(Node *root);
    void preOrderTraverse(Node *root);
    void print2DUtil(Node *root, int space);
};
