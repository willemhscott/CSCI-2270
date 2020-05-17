#ifndef CSCI_2270_HASHTABLE_H
#define CSCI_2270_HASHTABLE_H

template <typename T, typename T2>
struct HashNode {
    T *key;
    T2 *value;
};

template <typename T, typename T2>
class HashTable {
public:
    HashTable() {
        buckets = new int[size];
        for (int i = 0; i < size; i++) {
            buckets[i].key = nullptr;
        }
    }

    void insert(T &key, T2 &value);
    unsigned int hash(T *key);
    void print();

    unsigned int size = 8;
    HashNode<T, T2> buckets[];
};


#endif //CSCI_2270_HASHTABLE_H
