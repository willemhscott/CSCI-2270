//
// Created by willemhscott  on 9/1/19.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Park {
    string parkname;
    string state;
    int area;
};

void addPark(Park parks[], string parkName, string state, int area, int length) {
    parks[length].parkname = parkName;
    parks[length].state = state;
    parks[length].area = area;
}

void printList(const Park parks[], int length) {
    for (int i = 0; i < length; i++) {
        Park p = parks[i];
        cout << p.parkname << " [" << p.state << "] area: " << p.area << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(argv[1]);
    outputFile.open(argv[2]);

    int minimumArea = stoi(argv[3]);

    if (!inputFile.is_open() && !outputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    int i = 0;
    Park parks[100];

    while (getline(inputFile, line)) {
        stringstream ss(line);

        string name, state, area;

        getline(ss, name, ',');
        getline(ss, state, ',');
        getline(ss, area);

        if (stoi(area) >= minimumArea) {
            outputFile << line << endl;
        }

        addPark(parks, name, state, stoi(area), i);
        i++;
    }
    printList(parks, i);
    outputFile.close();

    return 0;
}