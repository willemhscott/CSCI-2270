#include "HashTable.h"
#include <iostream>

using namespace std;

template<typename T, typename T2>
void HashTable<T, T2>::insert(T& key, T2& value) {
    unsigned int h = hash(key);
    if (buckets[h].key == nullptr) {
        buckets[h].key = key;
        buckets[h].value = value;
    } else {
        unsigned int osize = size;
        size = (unsigned int) size * 1.25;
        HashNode<T, T2> *b = buckets;
        buckets = new int[size];
        for (unsigned int i = 0; i < osize; i++) {
            if (b[i].key != nullptr)
                insert(b[i].key, b[i].value);
        }
        insert(key, value);
    }

}

template<typename T, typename T2>
unsigned int HashTable<T, T2>::hash(T *key) {
    return key % size;
}

template<typename T, typename T2>
void HashTable<T, T2>::print() {
    cout << "{";
    for (unsigned int i = 0; i < size; i++) {
        HashNode<T, T2> t = buckets[i];
        if (t.key != nullptr) {
            cout << t.key << ": " << t.value << ", ";
        }
    }
    cout << "}" << endl;
}