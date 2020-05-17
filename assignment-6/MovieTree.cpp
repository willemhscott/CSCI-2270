#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
    //write your code
    root = NULL;
}

void destroy(MovieNode *m) {
    if (m->left != NULL) {
        destroy(m->left);
        delete m->left;
    }
    if (m->right != NULL) {
        destroy(m->right);
        delete m->right;
    }
}

MovieTree::~MovieTree() {
    destroy(root);
    delete root;
    root = NULL;
}


void print_values(MovieNode *root) {
    if (root->left != NULL) {
        print_values(root->left);
    }
    cout << "Movie: " << root->title << " " << root->rating << endl;
    if (root->right != NULL) {
        print_values(root->right);
    }
}

void MovieTree::printMovieInventory() {
    //std::cout << std::fixed;
    //std::cout << std::setprecision(1);
    // Your code here
    if (root != NULL)
        print_values(root);
    else
        cout << "Tree is Empty. Cannot print" << endl;
}



// You may add helper functions between this comment and the rentMovie
// definition if you like

MovieNode *find(MovieNode *root, string title) {
    if (title == root->title)
        return root;
    if (title < root->title) {
        if (root->left != NULL) {
            return find(root->left, title);
        } else {
            return NULL;
        }
    } else {
        if (root->right != NULL) {
            return find(root->right, title);
        } else {
            return NULL;
        }
    }
}

void MovieTree::findMovie(string title) {
    //cout << "Finding: " << title << endl;
    MovieNode *m = find(root, title);
    if (m == NULL) {
        cout << "Movie not found." << endl;
        return;
    }
    cout << "Movie Info:" << endl << "==================" << endl;
    cout << "Ranking:" << m->ranking << endl;
    cout << "Title  :" << m->title << endl;
    cout << "Year   :" << m->year << endl;
    cout << "rating :" << m->rating << endl;
}

void printQuery(MovieNode *root, float rating, int year) {
    if (root->rating >= rating && root->year >= year) {
        cout << root->title << "(" << root->year << ") " << root->rating << endl;
    }
    if (root->left != NULL) {
        printQuery(root->left, rating, year);
    }
    if (root->right != NULL) {
        printQuery(root->right, rating, year);
    }
}

void MovieTree::queryMovies(float rating, int year) {
    //write your code
    if (root != NULL) {
        cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
        printQuery(root, rating, year);
    } else
        cout << "Tree is Empty. Cannot query Movies" << endl;
}

void average(MovieNode *m, float &rt, int &mt) {
    rt += m->rating;
    mt += 1;
    if (m->left != NULL) {
        average(m->left, rt, mt);
    }
    if (m->right != NULL) {
        average(m->right, rt, mt);
    }
}

void MovieTree::averageRating() {
    //write your code
    float ratingTotal = 0;
    int nMovies = 0;
    float rav;
    if (root != NULL) {
        average(root, ratingTotal, nMovies);
        rav = ratingTotal / nMovies;
    } else {
        cout << "Average rating:0.0" << endl;
        return;
    }
    cout << "Average rating:" << rav << endl;
}

void insertNode(MovieNode *root, int ranking, string title, int year, float rating) {
    if (title < root->title) {
        if (root->left != NULL) {
            insertNode(root->left, ranking, title, year, rating);
        } else {
            root->left = new MovieNode(ranking, title, year, rating);
        }
    } else {
        if (root->right != NULL) {
            insertNode(root->right, ranking, title, year, rating);
        } else {
            root->right = new MovieNode(ranking, title, year, rating);
        }
    }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
    //write your code
    //MovieNode *node = new Node(ranking, title, year, rating);
    if (root == NULL) {
        root = new MovieNode(ranking, title, year, rating);
    } else {
        insertNode(root, ranking, title, year, rating);
    }
}