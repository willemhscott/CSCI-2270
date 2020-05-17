#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Nice! YOu fucked it up!" << endl;
        return 0;
    }
    ifstream f;
    f.open(argv[1]);

    MovieTree mt = MovieTree();

    string line;
    while (getline(f, line)) {
        stringstream s (line);
        string rank;
        getline(s, rank, ',');
        string title;
        getline(s, title, ',');
        string year;
        getline(s, year, ',');
        string rating;
        getline(s, rating);
        mt.addMovieNode(stoi(rank), title, stoi(year), stof(rating));
    }

    while (true) {
        cout << "======Main Menu======" << endl;
        cout << "1. Find a movie" << endl;
        cout << "2. Query movies" << endl;
        cout << "3. Print the inventory" << endl;
        cout << "4. Average Rating of movies" << endl;
        cout << "5. Quit" << endl;

        string choice;
        string choice2;
        getline(cin, choice);
        int c = stoi(choice);

        switch (c) {
            case 1:
                cout << "Enter title:" << endl;
                getline(cin, choice);
                mt.findMovie(choice);
                break;
            case 2:
                cout << "Enter minimum rating:" << endl;
                getline(cin, choice);
                cout << "Enter minimum year:" << endl;
                getline(cin, choice2);
                mt.queryMovies(stof(choice), stoi(choice2));
                break;
            case 3:
                mt.printMovieInventory();
                break;
            case 4:
                mt.averageRating();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
        }
    }

}