#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue) {
    /*
     *  a. myArray[ ] :​ ​sorted​ array that should be able to hold at most 100 integers.
     *  b. numEntries : the number of elements inserted so far.
     *  c. newValue : the incoming value to be inserted into the sorted array (i.e.
     *  myArray[]).
     */
    int j = 0;
    for (; j < numEntries; j++) {
        //cout << myArray[j] << " " << newValue << endl;
        if (myArray[j] > newValue) {
            for (int k = numEntries; k > j; k--) {
                myArray[k] = myArray[k-1];
            }
            break;
        }
    }

    myArray[j] = newValue;
    return numEntries + 1;
}

int main(int argc, char *argv[]) {
    if (argc < 1) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    ifstream dataFile;
    dataFile.open(argv[1]);

    if (!dataFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    int i = 0;
    int values[100];

    while (getline(dataFile, line)) {
        int val = stoi(line);
        insertIntoSortedArray(values, i, val);
        i++;
        cout << values[0];
        for (int j = 1; j < i; j++) {
            cout << "," << values[j];
        }
        cout << endl;
    }
    return 0;
}