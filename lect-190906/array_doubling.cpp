#include <iostream>
using namespace std;

int main() {
    int n = 1;
    int c = 0;

    int *ptr;
    ptr = new int[n];

    add_item(ptr, &n, &c, 5);
    for (int i = 0; i < c; i++) {
        cout << ptr[i];
    }
}

int add_item(int array[], int *n, int *c, int item) {
    if (*n - 2 > *c) {
        *n = *n * 2;
        int *pin = new int[*n];
        for (int i = 0; i < *c; i++) {
            pin[i] = array[i];
        }
        delete[] array;
        array = pin;
    } else {
        array[*c] = item;
    }
    *c = *c + 1;
}