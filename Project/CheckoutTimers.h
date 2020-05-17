#include <string>
#include <iostream>

using namespace std;

struct CheckedOutBook {
    int endtime;
    string name;
    string author;
    string title;

    CheckedOutBook(){
        // Throwaway constructor
        endtime = 0;
    }
    CheckedOutBook(int _endtime, string _name, string _author, string _title) {
        /*
         * A class for tracking the books that have been checked out
         * Contains the book, author, and the name of the person who checked
         * it out, as well as the time (since unix epoch) that it will be returned
         */
        endtime = _endtime;
        name = _name;
        author = _author;
        title = _title;
    }
};

class CheckoutTimers {
public:
    void checkout(int minutes, string name, string author, string title);
    int peek();
    CheckedOutBook pop();
    void printTimers();

    CheckoutTimers() {
        /*
         * A priority queue containing `CheckedOutBooks`
         * Prioritizes based on the book's `endtime` attribute
         * Begins with a capacity of 8 and uses array doubling
         * to scale
         */
        capacity = 8;
        size = 0;
        heap = new CheckedOutBook[capacity];
        for (int i = 0; i < capacity; i++) {
            heap[i] = CheckedOutBook();
        }
    }
private:
    int capacity;
    int size;
    CheckedOutBook *heap;

    int parent(int i) {
        return (i-1)/2;
    }

    void swap(int i, int j) {
        // Simple swap of two elements in the array
        CheckedOutBook temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void minHeapify(int i) {
        // Self explanatory
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < size && heap[l].endtime < heap[i].endtime) {
            smallest = l;
        }

        if (r < size && heap[r].endtime < heap[i].endtime && heap[r].endtime < heap[l].endtime) {
            smallest = r;
        }

        if (smallest != i) {
            swap(i, smallest);
            minHeapify(smallest);
        }
    }
};
