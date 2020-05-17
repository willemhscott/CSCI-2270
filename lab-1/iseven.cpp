#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void isEven(int& n) {
    n = n % 2;
}

int main(int argc, char* argv[]) {
    if (argc == 0) {
        cout << "Pass a file name!" << endl;
        return 1;
    }
    int n = stoi(argv[1]);

    /*
    ifstream file;
    file.open(argv[0]);

    if (!file) {
        cout << "Invalid file!" << endl;
        return 1;
    }
    file >> n;
     */

    isEven(n);
    if (n == 0)
        cout << "it is even!" << endl;
    else
        cout << "it is odd!" << endl;
    return 0;
}

