#include "MovieTree.hpp"
#include <iostream>

using namespace std;

MovieTree::MovieTree() {
    root = NULL;
}

void delLLHelper(LLMovieNode *node) {
    if (node == NULL) {
        return;
    }
    delLLHelper(node->next);
    delete node->next;
}

void dHelper(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    delLLHelper(root->head);
    delete root->head;

    dHelper(root->leftChild);
    dHelper(root->rightChild);
    if (root->leftChild != NULL)
        delete root->leftChild;
    if (root->rightChild != NULL)
        delete root->rightChild;
}

MovieTree::~MovieTree() {
    dHelper(root);
    if (root != NULL)
        delete root;
}


void printMovies(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    printMovies(node->leftChild);
    cout << "Movies starting with letter: " << node->titleChar << endl;
    LLMovieNode *mll = node->head;
    while (mll) {
        cout << " >> " << mll->title << " " << mll->rating << endl;
        mll = mll->next;
    }

    printMovies(node->rightChild);
}

void MovieTree::printMovieInventory() {
    printMovies(root);
}

void insertMovie(TreeNode *node, int ranking, std::string title, int year, float rating) {
    char tChar = title.front();
    if (tChar == node->titleChar) {
        if (node->head == NULL) {
            node->head = new LLMovieNode(ranking, title, year, rating);
        } else if (title < node->head->title) {
            auto temp = node->head;
            node->head = new LLMovieNode(ranking, title, year, rating);
            node->head->next = temp;
        } else {
            LLMovieNode *cnode = node->head;
            while (cnode->next != NULL && title > cnode->next->title) {
                cnode = cnode->next;
            }
            LLMovieNode *temp = cnode->next;
            cnode->next = new LLMovieNode(ranking, title, year, rating);
            cnode->next->next = temp;
        }
    } else if (tChar < node->titleChar) {
        if (node->leftChild != NULL) {
            insertMovie(node->leftChild, ranking, title, year, rating);
        } else {
            node->leftChild = new TreeNode();
            node->leftChild->titleChar = tChar;
            insertMovie(node->leftChild, ranking, title, year, rating);
        }
    } else {
        if (node->rightChild != NULL) {
            insertMovie(node->rightChild, ranking, title, year, rating);
        } else {
            node->rightChild = new TreeNode();
            node->rightChild->titleChar = tChar;
            insertMovie(node->rightChild, ranking, title, year, rating);
        }
    }
}

void MovieTree::addMovie(int ranking, std::string title, int year, float rating) {
    if (root == NULL) {
        root = new TreeNode();
        root->titleChar = title.front();
        root->head = new LLMovieNode(ranking, title, year, rating);
    } else {
        insertMovie(root, ranking, title, year, rating);
    }
}

TreeNode *delMovie(TreeNode *node, string title) {
    if (node == NULL) {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return nullptr;
    }
    if (title.front() == node->titleChar) {
        if (title == node->head->title) {
            auto temp = node->head;
            node->head = node->head->next;
            delete temp;
        } else {
            auto cnode = node->head;
            while (cnode && cnode->next->title != title) {
                cnode = cnode->next;
            }
            if (cnode) {
                auto temp = cnode->next;
                cnode->next = temp->next;
                delete temp;
            } else {
                cout << "Movie: " << title << " not found, cannot delete." << endl;
                return node;
            }
        }
        return node;
    } else if (title.front() < node->titleChar) {
        return delMovie(node->leftChild, title);
    } else {
        return delMovie(node->rightChild, title);
    }
}

TreeNode *removeNode(TreeNode *currNode, char titleChar) {
    //printTree();
    //if (currNode != NULL)
    //cout << currNode->key << ", " << value << endl;
    if (currNode == NULL) {
        return NULL;
    } else if (titleChar < currNode->titleChar) {
        currNode->leftChild = removeNode(currNode->leftChild, titleChar);
    } else if (titleChar > currNode->titleChar) {
        currNode->rightChild = removeNode(currNode->rightChild, titleChar);
    }
        // We found the node with the value
    else {
        //cout << "made it!" << endl;
        //TODO Case : No child
        if (currNode->leftChild == NULL && currNode->rightChild == NULL) {
            //cout << "no child" << endl;
            //delete currNode;
            delete currNode;
            return NULL;
        }
            //TODO Case : Only right child
        else if (currNode->leftChild == NULL) {
            //cout << "right only" << endl;
            auto temp = currNode->rightChild;
            delete currNode;
            return temp;
        }
            //TODO Case : Only left child
        else if (currNode->rightChild == NULL) {
            //cout << "left only" << endl;
            auto temp = currNode->leftChild;
            delete currNode;
            return temp;
        }
            //TODO Case: Both left and right child
        else {
            //cout << "two children" << endl;
            ///Replace with Minimum from right subtree
            //Node *prev = currNode;
            TreeNode *predec = currNode->leftChild;
            while (predec->rightChild != NULL) {
                //prev = predec;
                predec = predec->rightChild;
            }
            //prev->right = NULL;
            currNode->titleChar = predec->titleChar;
            currNode->head = predec->head;
            //cout << "removing p: " << predec->key << endl;
            currNode->leftChild = removeNode(currNode->leftChild, predec->titleChar);
        }

    }
    return currNode;
}

void MovieTree::deleteMovie(std::string title) {
    TreeNode *node = delMovie(root, title);
    if (node && node->head == NULL) {
        root = removeNode(this->root, node->titleChar);
    }
}
