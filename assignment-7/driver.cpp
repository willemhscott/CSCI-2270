#include <iostream>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"
using namespace std;

int main(int argc, char* argv[]) {
    MovieTree mt = MovieTree();
    string fname = argv[1];
    ifstream file;
    file.open(fname);
    string line;
    while (getline(file, line)) {
        stringstream l(line);
        string rank, title, year, rating;
        getline(l, rank, ',');
        getline(l, title, ',');
        getline(l, year, ',');
        getline(l, rating);
        mt.addMovie(stoi(rank), title, stoi(year), stof(rating));
    }
    file.close();

    int choice;
    string ln;
    while (true) {
        cout << "======Main Menu======" << endl;
        cout << "1. Print the inventory" << endl;
        cout << "2. Delete a movie" << endl;
        cout << "3. Quit" << endl;
        getline(cin, ln);
        choice = stoi(ln);

        switch (choice) {
            case 1:
                mt.printMovieInventory();
                break;
            case 2:
                cout << "Enter a movie title:" << endl;
                getline(cin, ln);
                mt.deleteMovie(ln);
                break;
            case 3:
                cout << "Goodbye!" << endl;
                return 0;
        }
    }
    return 0;

}