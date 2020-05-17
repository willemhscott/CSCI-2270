#include <iostream>

using namespace std;

// Multi file compilation
// Usually 3+ files
// Header file with prototypes (.h/.hpp)
// Implementation file with func definitions (.cpp)
//    Include header file #include <myfile.h>
// Driver file: Where main function goes
//    Include header file
//    main.cpp
//    Time12Driver.cpp -- relevant name

// g++ -c file1.cpp
// g++ -c file2.cpp
// g++ file1.o file2.o -o final.exe

// All in one:
//    g++ file1.cpp file2.cpp -o final.exe

void add_item(int *&array, int *n, int *c, int item) {
    //cout << *n << " " << *c << endl;
    if (*n - 2 < *c) {
        //cout << "doubled" << endl;
        *n = *n * 2;
        int *pin = new int[*n];
        for (int i = 0; i < *c; i++) {
            pin[i] = array[i];
        }
        delete[] array;
        array = pin;
    }
    array[*c] = item;
    *c = *c + 1;
}

void doubleArray(int *&arr, int &n) {
    int *temp = new int[n * 2];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

int main() {
    int n = 1;
    int c = 0;

    int *ptr;
    ptr = new int[n];

    for (int i = 0; i < 2049; i++) {
        add_item(ptr, &n, &c, i);
        cout << ptr[i] << endl;
    }

    return 0;
}

