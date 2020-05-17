#include "HashTable.h"
#include <iostream>

using namespace std;

int main() {
    auto h = HashTable<string, int>();
    h.insert("shit!", 5);
    h.insert("shit!", 5);
    h.insert("shit!", 5);
    h.insert("shit!", 5);
}